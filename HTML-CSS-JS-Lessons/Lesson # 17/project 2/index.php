<!DOCTYPE html>
<html>
<head>
    <title>Secret Santa</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            background-color: #f4f4f9;
            color: #333;
        }
        h1, h2 {
            color: #4CAF50;
        }
        form {
            background-color: #ffffff;
            border: 1px solid #ccc;
            border-radius: 8px;
            padding: 20px;
            margin-bottom: 20px;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
        }
        form label {
            display: block;
            margin-bottom: 8px;
            font-weight: bold;
        }
        form input, form button {
            width: 100%;
            padding: 10px;
            margin-bottom: 10px;
            border: 1px solid #ccc;
            border-radius: 4px;
            font-size: 16px;
        }
        form button {
            background-color: #4CAF50;
            color: white;
            border: none;
            cursor: pointer;
        }
        form button:hover {
            background-color: #45a049;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }
        table, th, td {
            border: 1px solid #ccc;
        }
        th, td {
            padding: 12px;
            text-align: left;
        }
        th {
            background-color: #4CAF50;
            color: white;
        }
        tr:nth-child(even) {
            background-color: #f9f9f9;
        }
    </style>
</head>
<body>
    <h1>Secret Santa Manager</h1>

    <?php
    $db = new SQLite3('secret_santa.db');

    // Create tables
    $db->exec("
        CREATE TABLE IF NOT EXISTS participants (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT,
            email TEXT
        )
    ");

    $db->exec("
        CREATE TABLE IF NOT EXISTS assignments (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            giver_id INTEGER,
            receiver_id INTEGER,
            FOREIGN KEY (giver_id) REFERENCES participants(id),
            FOREIGN KEY (receiver_id) REFERENCES participants(id)
        )
    ");

    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        if (isset($_POST['add_participant'])) {
            $name = $_POST['name'];
            $email = $_POST['email'];
            $db->exec("INSERT INTO participants (name, email) VALUES ('$name', '$email')");
            echo "<div class='message success'>Participant '$name' added successfully!</div>";
        } elseif (isset($_POST['generate_pairs'])) {
            // Clear old assignments
            $db->exec("DELETE FROM assignments");

            // Fetch participants
            $result = $db->query("SELECT id FROM participants");
            $participants = [];
            while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
                $participants[] = $row['id'];
            }

            // Shuffle and assign
            shuffle($participants);
            $pairs = [];
            $length = count($participants);
            for ($i = 0; $i < $length; $i++) {
                $giver = $participants[$i];
                $receiver = $participants[($i + 1) % $length];
                $db->exec("INSERT INTO assignments (giver_id, receiver_id) VALUES ($giver, $receiver)");
            }
            echo "<div class='message success'>Secret Santa pairs generated successfully!</div>";
        }
    }
    ?>

    <h2>Add New Participant</h2>
    <form method="POST">
        <label>Name:</label>
        <input type="text" name="name" required>
        <label>Email:</label>
        <input type="email" name="email" required>
        <button type="submit" name="add_participant">Add Participant</button>
    </form>

    <h2>Generate Secret Santa Pairs</h2>
    <form method="POST">
        <button type="submit" name="generate_pairs">Generate Pairs</button>
    </form>

    <h2>Participants and Assignments</h2>
    <?php
    $result = $db->query("
        SELECT 
            givers.name AS giver_name, 
            receivers.name AS receiver_name 
        FROM assignments
        JOIN participants AS givers ON assignments.giver_id = givers.id
        JOIN participants AS receivers ON assignments.receiver_id = receivers.id
    ");

    echo "<table>";
    echo "<tr><th>Giver</th><th>Receiver</th></tr>";
    while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
        echo "<tr>";
        echo "<td>" . $row['giver_name'] . "</td>";
        echo "<td>" . $row['receiver_name'] . "</td>";
        echo "</tr>";
    }
    echo "</table>";

    $db->close();
    ?>
</body>
</html>
