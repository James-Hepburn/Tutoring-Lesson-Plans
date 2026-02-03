<html>
<head>
</head>

<body>
    <?php
    /*
    In a one-to-one relationship, each record in one table is linked to exactly one record in another table. This means that for every row in Table A, there is a corresponding row in Table B, and vice versa.

    For example: A users table could have a one-to-one relationship with a profiles table. Each user has exactly one profile, and each profile belongs to exactly one user.
    
    Purpose of One-to-One Relationships: The primary purpose of a one-to-one relationship is data organization and separation. Instead of storing all data in a single table, you divide it into smaller tables
    */
    
    // Step 1: Create or connect to the SQLite database
    $db = new SQLite3('relationships.db');

    // Step 2: Create the 'users' table
    $db->exec("DROP TABLE IF EXISTS users");
    $db->exec("
    CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        username TEXT,
        email TEXT
    )");

    // Step 3: Create the 'profiles' table
    $db->exec("DROP TABLE IF EXISTS profiles");
    $db->exec("
    CREATE TABLE IF NOT EXISTS profiles (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        user_id INTEGER UNIQUE,
        bio TEXT,
        FOREIGN KEY (user_id) REFERENCES users(id)
    )");

    // Step 4: Insert data into the 'users' table
    $db->exec("INSERT INTO users (username, email) VALUES ('john_doe', 'john@example.com')");
    $db->exec("INSERT INTO users (username, email) VALUES ('jane_doe', 'jane@example.com')");
    $db->exec("INSERT INTO users (username, email) VALUES ('random_person', 'random@example.com')");

    // Step 5: Insert data into the 'profiles' table
    $db->exec("INSERT INTO profiles (user_id, bio)
    VALUES (1, 'Hi, I am John! I love coding.')");
    $db->exec("INSERT INTO profiles (user_id, bio)
    VALUES (2, 'Hey, I am Jane! A digital artist.')");

    // Step 6: Retrieve data from both tables using a JOIN
    $result = $db->query("
        SELECT users.username, users.email, profiles.bio
        FROM users
        INNER JOIN profiles ON users.id = profiles.user_id
    ");

    // INNER JOIN is a type of SQL join that returns only the rows where there is a match in both tables being joined. If a row in one table does not have a matching row in the other table, it will not be included in the result.

    // Step 7: Display the data in an HTML table
    if ($result) {
        echo "<h2>User Profiles</h2>";
        echo "<table border='1'>";
        echo "<tr><th>Username</th><th>Email</th><th>Bio</th></tr>";

        while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
            echo "<tr>";
            echo "<td>" . $row['username'] . "</td>";
            echo "<td>" . $row['email'] . "</td>";
            echo "<td>" . $row['bio'] . "</td>";
            echo "</tr>";
        }

        echo "</table>";
    } else {
        echo "No profiles found.";
    }

    // Step 8: Close the database connection
    $db->close();
    ?>
</body>
</html>
