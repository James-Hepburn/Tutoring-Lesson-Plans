<html>
<head>
    <title>One-to-Many Relationship Example</title>
</head>

<body>
    <?php
    /*
    A one-to-many relationship occurs when a single record in one table is associated with multiple records in another table.

    Example: 
    - A users table (one user) is linked to a posts table (many posts).
    - Each user can write multiple posts, but each post is written by only one user.

    Purpose of One-to-Many Relationships:
    - To represent hierarchical data or relationships where one "parent" entity has multiple "child" entities.
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

    // Step 3: Create the 'posts' table
    $db->exec("DROP TABLE IF EXISTS posts");
    $db->exec("
    CREATE TABLE IF NOT EXISTS posts (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        user_id INTEGER,
        title TEXT,
        content TEXT,
        FOREIGN KEY (user_id) REFERENCES users(id)
    )");

    // Step 4: Insert data into the 'users' table
    $db->exec("INSERT INTO users (username, email) VALUES ('john_doe', 'john@example.com')");
    $db->exec("INSERT INTO users (username, email) VALUES ('jane_doe', 'jane@example.com')");

    // Step 5: Insert multiple posts for each user
    $db->exec("INSERT INTO posts (user_id, title, content) VALUES (1, 'John\'s First Post', 'This is John\'s first post content.')");
    $db->exec("INSERT INTO posts (user_id, title, content) VALUES (1, 'John\'s Second Post', 'This is John\'s second post content.')");
    $db->exec("INSERT INTO posts (user_id, title, content) VALUES (2, 'Jane\'s First Post', 'This is Jane\'s first post content.')");
    $db->exec("INSERT INTO posts (user_id, title, content) VALUES (2, 'Jane\'s Second Post', 'This is Jane\'s second post content.')");
    $db->exec("INSERT INTO posts (user_id, title, content) VALUES (2, 'Jane\'s Third Post', 'This is Jane\'s third post content.')");

    // Step 6: Retrieve data from both tables using a JOIN
    $result = $db->query("
        SELECT users.username, posts.title, posts.content
        FROM users
        INNER JOIN posts ON users.id = posts.user_id
    ");

    // Step 7: Display the data in an HTML table
    if ($result) {
        echo "<h2>User Posts</h2>";
        echo "<table border='1'>";
        echo "<tr><th>Username</th><th>Post Title</th><th>Content</th></tr>";

        while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
            echo "<tr>";
            echo "<td>" . $row['username'] . "</td>";
            echo "<td>" . $row['title'] . "</td>";
            echo "<td>" . $row['content'] . "</td>";
            echo "</tr>";
        }

        echo "</table>";
    } else {
        echo "No posts found.";
    }

    // Step 8: Close the database connection
    $db->close();
    ?>
</body>
</html>
