<html>
<head>
    <title>Fitness Tracker</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            background-color: #f4f4f9;
        }
        h1 {
            color: #4CAF50;
        }
        h2 {
            color: #333;
        }
        form {
            background-color: #fff;
            border: 1px solid #ccc;
            padding: 15px;
            margin-bottom: 20px;
            border-radius: 5px;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
        }
        input[type="text"], input[type="email"], input[type="number"], input[type="date"], input[type="submit"] {
            margin: 5px 0;
            padding: 8px;
            width: 100%;
            border: 1px solid #ccc;
            border-radius: 3px;
        }
        input[type="submit"] {
            background-color: #4CAF50;
            color: white;
            border: none;
            cursor: pointer;
        }
        input[type="submit"]:hover {
            background-color: #45a049;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }
        table, th, td {
            border: 1px solid #ddd;
        }
        th, td {
            padding: 10px;
            text-align: left;
        }
        th {
            background-color: #f2f2f2;
        }
    </style>
</head>

<body>
    <?php
    // Step 1: Create or connect to the SQLite database
    $db = new SQLite3('fitness_tracker.db');

    // Step 2: Create the 'users' table
    $db->exec("CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        username TEXT NOT NULL,
        email TEXT NOT NULL
    )");

    // Step 3: Create the 'workouts' table
    $db->exec("CREATE TABLE IF NOT EXISTS workouts (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        user_id INTEGER NOT NULL,
        date TEXT NOT NULL,
        type TEXT NOT NULL,
        duration INTEGER NOT NULL,
        calories_burned INTEGER NOT NULL,
        FOREIGN KEY (user_id) REFERENCES users(id)
    )");

    // Step 4: Form to add users
    if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['add_user'])) {
        $username = $_POST['username'];
        $email = $_POST['email'];
        $db->exec("INSERT INTO users (username, email) VALUES ('$username', '$email')");
    }

    // Step 5: Form to add workouts
    if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['add_workout'])) {
        $user_id = $_POST['user_id'];
        $date = $_POST['date'];
        $type = $_POST['type'];
        $duration = $_POST['duration'];
        $calories_burned = $_POST['calories_burned'];
        $db->exec("INSERT INTO workouts (user_id, date, type, duration, calories_burned) VALUES ('$user_id', '$date', '$type', '$duration', '$calories_burned')");
    }

    // Step 6: Display forms to add data
    echo "<h1>Fitness Tracker</h1>";
    echo "<h2>Add User</h2>";
    echo "<form method='POST'>
        Username: <input type='text' name='username' required><br>
        Email: <input type='email' name='email' required><br>
        <input type='submit' name='add_user' value='Add User'>
    </form>";

    echo "<h2>Add Workout</h2>";
    echo "<form method='POST'>
        User ID: <input type='number' name='user_id' required><br>
        Date: <input type='date' name='date' required><br>
        Type: <input type='text' name='type' required><br>
        Duration (minutes): <input type='number' name='duration' required><br>
        Calories Burned: <input type='number' name='calories_burned' required><br>
        <input type='submit' name='add_workout' value='Add Workout'>
    </form>";

    // Step 7: Retrieve and display data
    $result = $db->query(
        "SELECT users.username, workouts.date, workouts.type, workouts.duration, workouts.calories_burned
         FROM users
         JOIN workouts ON users.id = workouts.user_id"
    );

    echo "<h2>All Workouts</h2>";
    echo "<table>";
    echo "<tr><th>Username</th><th>Date</th><th>Workout Type</th><th>Duration (min)</th><th>Calories Burned</th></tr>";

    while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
        echo "<tr>";
        echo "<td>" . htmlspecialchars($row['username']) . "</td>";
        echo "<td>" . htmlspecialchars($row['date']) . "</td>";
        echo "<td>" . htmlspecialchars($row['type']) . "</td>";
        echo "<td>" . htmlspecialchars($row['duration']) . "</td>";
        echo "<td>" . htmlspecialchars($row['calories_burned']) . "</td>";
        echo "</tr>";
    }

    echo "</table>";

    // Close the database connection
    $db->close();
    ?>
</body>
</html>
