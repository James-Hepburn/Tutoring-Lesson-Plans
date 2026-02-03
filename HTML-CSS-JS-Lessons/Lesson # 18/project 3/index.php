<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Hotel Booking System</title>
    <style>
        body {
            font-family: 'Arial', sans-serif;
            background-color: #f5f5f5;
            margin: 0;
            padding: 20px;
        }
        header {
            background-color: #3aafa9;
            color: white;
            padding: 10px 20px;
            text-align: center;
        }
        h1 {
            margin: 0;
        }
        form {
            background-color: white;
            padding: 20px;
            margin-bottom: 20px;
            border-radius: 5px;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
        }
        input, select {
            width: 100%;
            padding: 10px;
            margin: 5px 0;
            border: 1px solid #ccc;
            border-radius: 5px;
        }
        input[type="submit"] {
            background-color: #3aafa9;
            color: white;
            cursor: pointer;
            border: none;
        }
        input[type="submit"]:hover {
            background-color: #2b7a78;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }
        th, td {
            padding: 10px;
            border: 1px solid #ddd;
            text-align: left;
        }
        th {
            background-color: #3aafa9;
            color: white;
        }
    </style>
</head>
<body>

<header>
    <h1>Hotel Booking System</h1>
</header>

<?php
// Database connection
$db = new SQLite3('hotel_booking_system.db');

// Create tables if not already present
$db->exec("CREATE TABLE IF NOT EXISTS hotels (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    location TEXT NOT NULL
)");

$db->exec("CREATE TABLE IF NOT EXISTS rooms (
    id INTEGER PRIMARY KEY,
    hotel_id INTEGER NOT NULL,
    room_type TEXT NOT NULL,
    price_per_night REAL NOT NULL,
    availability TEXT NOT NULL,
    FOREIGN KEY (hotel_id) REFERENCES hotels(id)
)");

$db->exec("CREATE TABLE IF NOT EXISTS bookings (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    room_id INTEGER NOT NULL,
    guest_name TEXT NOT NULL,
    check_in_date TEXT NOT NULL,
    check_out_date TEXT NOT NULL,
    FOREIGN KEY (room_id) REFERENCES rooms(id)
)");

// Pre-insert hotels and rooms if not already present
$db->exec("INSERT OR IGNORE INTO hotels (id, name, location) VALUES
    (1, 'Seaside Hotel', 'Beach City'),
    (2, 'Mountain Retreat', 'Highland Village')");

$db->exec("INSERT OR IGNORE INTO rooms (id, hotel_id, room_type, price_per_night, availability) VALUES
    (1, 1, 'Standard Room', 100, 'Available'),
    (2, 1, 'Deluxe Room', 150, 'Available'),
    (3, 1, 'Suite', 200, 'Available'),
    (4, 2, 'Standard Room', 120, 'Available'),
    (5, 2, 'Deluxe Room', 180, 'Available'),
    (6, 2, 'Suite', 250, 'Available')");

// Add a booking with overlap check
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['add_booking'])) {
    $room_id = $_POST['room_id'];
    $guest_name = $_POST['guest_name'];
    $check_in_date = $_POST['check_in_date'];
    $check_out_date = $_POST['check_out_date'];

    // Check for overlapping bookings
    $overlap_check = $db->querySingle(
        "SELECT COUNT(*) FROM bookings 
         WHERE room_id = '$room_id' 
         AND ('$check_in_date' < check_out_date AND '$check_out_date' > check_in_date)"
    );

    if ($overlap_check > 0) {
        echo "<p style='color: red;'>Room ID $room_id is already booked for the selected dates.</p>";
    } else {
        $db->exec("INSERT INTO bookings (room_id, guest_name, check_in_date, check_out_date) 
                   VALUES ('$room_id', '$guest_name', '$check_in_date', '$check_out_date')");
        echo "<p style='color: green;'>Booking successful for room ID $room_id.</p>";
    }
}

// Cancel a booking
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['cancel_booking'])) {
    $booking_id = $_POST['booking_id'];
    $db->exec("DELETE FROM bookings WHERE id = '$booking_id'");
    echo "<p style='color: red;'>Booking ID $booking_id has been cancelled.</p>";
}

// Update room availability based on current date
$current_date = date('Y-m-d');
$db->exec("UPDATE rooms 
           SET availability = 'Unavailable' 
           WHERE id IN (
               SELECT room_id FROM bookings 
               WHERE '$current_date' BETWEEN check_in_date AND check_out_date
           )");
$db->exec("UPDATE rooms 
           SET availability = 'Available' 
           WHERE id NOT IN (
               SELECT room_id FROM bookings 
               WHERE '$current_date' BETWEEN check_in_date AND check_out_date
           )");

// Display available rooms
$rooms = $db->query("SELECT rooms.id, hotels.name AS hotel_name, rooms.room_type, rooms.price_per_night, rooms.availability 
                     FROM rooms 
                     JOIN hotels ON rooms.hotel_id = hotels.id");

echo "<h2>Available Rooms</h2>";
echo "<table>";
echo "<tr><th>Room ID</th><th>Hotel Name</th><th>Room Type</th><th>Price Per Night</th><th>Availability</th></tr>";
while ($room = $rooms->fetchArray(SQLITE3_ASSOC)) {
    echo "<tr>";
    echo "<td>" . htmlspecialchars($room['id']) . "</td>";
    echo "<td>" . htmlspecialchars($room['hotel_name']) . "</td>";
    echo "<td>" . htmlspecialchars($room['room_type']) . "</td>";
    echo "<td>$" . htmlspecialchars($room['price_per_night']) . "</td>";
    echo "<td>" . htmlspecialchars($room['availability']) . "</td>";
    echo "</tr>";
}
echo "</table>";

// Display current bookings
$bookings = $db->query("SELECT bookings.id, rooms.room_type, hotels.name AS hotel_name, bookings.guest_name, bookings.check_in_date, bookings.check_out_date 
                        FROM bookings 
                        JOIN rooms ON bookings.room_id = rooms.id 
                        JOIN hotels ON rooms.hotel_id = hotels.id");

echo "<h2>Current Bookings</h2>";
echo "<table>";
echo "<tr><th>Booking ID</th><th>Hotel Name</th><th>Room Type</th><th>Guest Name</th><th>Check-in Date</th><th>Check-out Date</th></tr>";
while ($booking = $bookings->fetchArray(SQLITE3_ASSOC)) {
    echo "<tr>";
    echo "<td>" . htmlspecialchars($booking['id']) . "</td>";
    echo "<td>" . htmlspecialchars($booking['hotel_name']) . "</td>";
    echo "<td>" . htmlspecialchars($booking['room_type']) . "</td>";
    echo "<td>" . htmlspecialchars($booking['guest_name']) . "</td>";
    echo "<td>" . htmlspecialchars($booking['check_in_date']) . "</td>";
    echo "<td>" . htmlspecialchars($booking['check_out_date']) . "</td>";
    echo "</tr>";
}
echo "</table>";
?>

<h2>Make a Booking</h2>
<form method="POST">
    Room ID: <input type="number" name="room_id" required><br>
    Guest Name: <input type="text" name="guest_name" required><br>
    Check-in Date: <input type="date" name="check_in_date" required><br>
    Check-out Date: <input type="date" name="check_out_date" required><br>
    <input type="submit" name="add_booking" value="Book Room">
</form>

<h2>Cancel a Booking</h2>
<form method="POST">
    Booking ID: <input type="number" name="booking_id" required><br>
    <input type="submit" name="cancel_booking" value="Cancel Booking">
</form>

</body>
</html>
