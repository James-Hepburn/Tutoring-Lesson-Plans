<html>
<head>
    <title>Many-to-Many Relationship Example</title>
</head>

<body>
    <?php
    /*
    A many-to-many relationship occurs when multiple records in one table can be associated with multiple records in another table.

    Example: 
    - A 'students' table is linked to a 'courses' table.
    - Each student can enroll in multiple courses, and each course can have multiple students.

    Purpose of Many-to-Many Relationships:
    - To model complex relationships between entities where a direct one-to-one or one-to-many relationship is insufficient.
    - Requires a junction table to link the two main tables.
    */

    // Step 1: Create or connect to the SQLite database
    $db = new SQLite3('relationships.db');

    // Step 2: Create the 'students' table
    $db->exec("DROP TABLE IF EXISTS students");
    $db->exec("
    CREATE TABLE IF NOT EXISTS students (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT
    )");

    // Step 3: Create the 'courses' table
    $db->exec("DROP TABLE IF EXISTS courses");
    $db->exec("
    CREATE TABLE IF NOT EXISTS courses (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        course_name TEXT
    )");

    // Step 4: Create the 'student_course' junction table
    $db->exec("DROP TABLE IF EXISTS student_course");
    $db->exec("
    CREATE TABLE IF NOT EXISTS student_course (
        student_id INTEGER,
        course_id INTEGER,
        PRIMARY KEY (student_id, course_id),
        FOREIGN KEY (student_id) REFERENCES students(id),
        FOREIGN KEY (course_id) REFERENCES courses(id)
    )");

    // Step 5: Insert data into 'students' and 'courses' tables
    $db->exec("INSERT INTO students (name) VALUES ('Alice')");
    $db->exec("INSERT INTO students (name) VALUES ('Bob')");
    $db->exec("INSERT INTO courses (course_name) VALUES ('Math')");
    $db->exec("INSERT INTO courses (course_name) VALUES ('Science')");
    $db->exec("INSERT INTO courses (course_name) VALUES ('History')");

    // Step 6: Insert relationships into 'student_course' table
    $db->exec("INSERT INTO student_course (student_id, course_id) VALUES (1, 1)"); // Alice - Math
    $db->exec("INSERT INTO student_course (student_id, course_id) VALUES (1, 2)"); // Alice - Science
    $db->exec("INSERT INTO student_course (student_id, course_id) VALUES (2, 2)"); // Bob - Science
    $db->exec("INSERT INTO student_course (student_id, course_id) VALUES (2, 3)"); // Bob - History

    // Step 7: Retrieve data using a JOIN
    $result = $db->query("
        SELECT students.name AS student_name, courses.course_name
        FROM students
        INNER JOIN student_course ON students.id = student_course.student_id
        INNER JOIN courses ON student_course.course_id = courses.id
    ");

    // Step 8: Display the data in an HTML table
    if ($result) {
        echo "<h2>Student Enrollments</h2>";
        echo "<table border='1'>";
        echo "<tr><th>Student Name</th><th>Course Name</th></tr>";

        while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
            echo "<tr>";
            echo "<td>" . $row['student_name'] . "</td>";
            echo "<td>" . $row['course_name'] . "</td>";
            echo "</tr>";
        }

        echo "</table>";
    } else {
        echo "No data found.";
    }

    // Step 9: Close the database connection
    $db->close();
    ?>
</body>
</html>
