<!DOCTYPE html>
<html>
<head>
    <title>Student Academic Management</title>
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
        .message {
            padding: 10px;
            margin-bottom: 20px;
            border-radius: 4px;
            color: #fff;
        }
        .success {
            background-color: #4CAF50;
        }
        .error {
            background-color: #f44336;
        }
    </style>
</head>
<body>
    <h1>Student Academic Management</h1>

    <?php
    // Step 1: Create or connect to the SQLite database
    $db = new SQLite3('students.db');

    // Step 2: Create the students table
    $db->exec("
        CREATE TABLE IF NOT EXISTS students (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT,
            email TEXT
        )
    ");

    // Step 2: Create the academic_details table
    $db->exec("
        CREATE TABLE IF NOT EXISTS academic_details (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            student_id INTEGER UNIQUE,
            gpa REAL,
            graduation_year INTEGER,
            FOREIGN KEY (student_id) REFERENCES students(id)
        )
    ");

    // Handle form submissions
    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        if (isset($_POST['add_student'])) {
            $name = $_POST['name'];
            $email = $_POST['email'];
            $db->exec("INSERT INTO students (name, email) VALUES ('$name', '$email')");
            echo "<div class='message success'>Student '$name' added successfully!</div>";
        } elseif (isset($_POST['add_academic_details'])) {
            $student_id = $_POST['student_id'];
            $gpa = $_POST['gpa'];
            $graduation_year = $_POST['graduation_year'];
            $result = $db->querySingle("SELECT COUNT(*) FROM students WHERE id = $student_id");
            if ($result > 0) {
                $db->exec("
                    INSERT OR REPLACE INTO academic_details (student_id, gpa, graduation_year) 
                    VALUES ($student_id, $gpa, $graduation_year)
                ");
                echo "<div class='message success'>Academic details for student ID '$student_id' updated successfully!</div>";
            } else {
                echo "<div class='message error'>Student ID '$student_id' does not exist.</div>";
            }
        } elseif (isset($_POST['search_student'])) {
            $search_name = $_POST['search_name'];
            $search_result = $db->query("
                SELECT students.name AS student_name, students.email, academic_details.gpa, academic_details.graduation_year
                FROM students
                LEFT JOIN academic_details ON students.id = academic_details.student_id
                WHERE students.name LIKE '%$search_name%'
            ");

            echo "<h2>Search Results</h2>";
            echo "<table>";
            echo "<tr><th>Student Name</th><th>Email</th><th>GPA</th><th>Graduation Year</th></tr>";

            $found = false;
            while ($row = $search_result->fetchArray(SQLITE3_ASSOC)) {
                $found = true;
                echo "<tr>";
                echo "<td>" . $row['student_name'] . "</td>";
                echo "<td>" . $row['email'] . "</td>";
                echo "<td>" . ($row['gpa'] ?? 'N/A') . "</td>";
                echo "<td>" . ($row['graduation_year'] ?? 'N/A') . "</td>";
                echo "</tr>";
            }

            if (!$found) {
                echo "<tr><td colspan='4'>No students found.</td></tr>";
            }

            echo "</table>";
        }
    }
    ?>

    <!-- Form to add a new student -->
    <h2>Add New Student</h2>
    <form method="POST">
        <label>Name:</label>
        <input type="text" name="name" required>
        <label>Email:</label>
        <input type="email" name="email" required>
        <button type="submit" name="add_student">Add Student</button>
    </form>

    <!-- Form to add or update academic details -->
    <h2>Add/Update Academic Details</h2>
    <form method="POST">
        <label>Student ID:</label>
        <input type="number" name="student_id" required>
        <label>GPA:</label>
        <input type="number" step="0.01" name="gpa" required>
        <label>Graduation Year:</label>
        <input type="number" name="graduation_year" required>
        <button type="submit" name="add_academic_details">Add/Update Academic Details</button>
    </form>

    <!-- Form to search for a student -->
    <h2>Search for a Student</h2>
    <form method="POST">
        <label>Student Name:</label>
        <input type="text" name="search_name" required>
        <button type="submit" name="search_student">Search</button>
    </form>

    <!-- Display all students -->
    <h2>All Students</h2>
    <?php
    $result = $db->query("
        SELECT students.name AS student_name, students.email, academic_details.gpa, academic_details.graduation_year
        FROM students
        LEFT JOIN academic_details ON students.id = academic_details.student_id
    ");

    echo "<table>";
    echo "<tr><th>Student Name</th><th>Email</th><th>GPA</th><th>Graduation Year</th></tr>";

    while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
        echo "<tr>";
        echo "<td>" . $row['student_name'] . "</td>";
        echo "<td>" . $row['email'] . "</td>";
        echo "<td>" . ($row['gpa'] ?? 'N/A') . "</td>";
        echo "<td>" . ($row['graduation_year'] ?? 'N/A') . "</td>";
        echo "</tr>";
    }

    echo "</table>";

    // Close the database connection
    $db->close();
    ?>
</body>
</html>
