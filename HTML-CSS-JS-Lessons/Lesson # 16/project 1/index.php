<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Library Management</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            background-color: #f4f4f4;
            color: #333;
        }
        h1, h2 {
            color: #333;
        }
        form {
            margin-bottom: 20px;
            padding: 10px;
            background-color: #fff;
            border: 1px solid #ccc;
            border-radius: 8px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }
        label {
            display: block;
            margin-bottom: 5px;
            font-weight: bold;
        }
        input[type="text"], input[type="submit"] {
            padding: 8px;
            margin: 5px 0 10px;
            width: 100%;
            box-sizing: border-box;
        }
        input[type="submit"] {
            background-color: #5cb85c;
            color: white;
            border: none;
            border-radius: 5px;
            cursor: pointer;
        }
        input[type="submit"]:hover {
            background-color: #4cae4c;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-bottom: 20px;
        }
        table, th, td {
            border: 1px solid #ddd;
        }
        th, td {
            padding: 12px;
            text-align: left;
        }
        th {
            background-color: #f2f2f2;
        }
        tr:nth-child(even) {
            background-color: #f9f9f9;
        }
        .action-buttons {
            display: flex;
            gap: 10px;
        }
        .action-buttons form {
            margin: 0;
        }
        .action-buttons input[type="submit"] {
            width: auto;
            padding: 5px 10px;
        }
        .delete-button {
            background-color: #d9534f;
        }
        .delete-button:hover {
            background-color: #c9302c;
        }
        .update-button {
            background-color: #f0ad4e;
        }
        .update-button:hover {
            background-color: #ec971f;
        }
    </style>
</head>
<body>

    <h1>Library Management</h1>

    <!-- Form to Add a New Book -->
    <h2>Add a New Book</h2>
    <form action="index.php" method="POST">
        <input type="hidden" name="action" value="add">
        <label for="title">Title:</label>
        <input type="text" name="title" id="title" required>

        <label for="author">Author:</label>
        <input type="text" name="author" id="author" required>

        <label for="genre">Genre:</label>
        <input type="text" name="genre" id="genre" required>

        <input type="submit" value="Add Book">
    </form>

    <hr>

    <!-- List of Books -->
    <h2>Current Books in Library</h2>

    <?php
    // Step 1: Create or connect to the SQLite database
    $db = new SQLite3('library.db');

    // Step 2: Create a 'books' table if it doesn't already exist
    $db->exec("CREATE TABLE IF NOT EXISTS books (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        title TEXT NOT NULL,
        author TEXT NOT NULL,
        genre TEXT NOT NULL
    )");

    // Handle form submissions for adding, deleting, and updating books
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $action = $_POST['action'];

        if ($action == 'add') {
            // Add a new book
            $title = $_POST['title'];
            $author = $_POST['author'];
            $genre = $_POST['genre'];

            $db->exec("INSERT INTO books (title, author, genre) VALUES ('$title', '$author', '$genre')");
            echo "<p>New book added successfully!</p>";
        } elseif ($action == 'delete') {
            // Delete a book
            $id = $_POST['id'];
            $db->exec("DELETE FROM books WHERE id = $id");
            echo "<p>Book deleted successfully!</p>";
        } elseif ($action == 'update') {
            // Update a book's details
            $id = $_POST['id'];
            $title = $_POST['title'];
            $author = $_POST['author'];
            $genre = $_POST['genre'];

            $db->exec("UPDATE books SET title = '$title', author = '$author', genre = '$genre' WHERE id = $id");
            echo "<p>Book updated successfully!</p>";
        }
    }

    // Step 3: Fetch and display all books
    $result = $db->query("SELECT * FROM books");

    if ($result->numColumns() > 0) {
        echo "<table>";
        echo "<tr><th>ID</th><th>Title</th><th>Author</th><th>Genre</th><th>Actions</th></tr>";

        while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
            echo "<tr>";
            echo "<td>" . $row['id'] . "</td>";
            echo "<td>" . $row['title'] . "</td>";
            echo "<td>" . $row['author'] . "</td>";
            echo "<td>" . $row['genre'] . "</td>";
            echo "<td class='action-buttons'>
                <!-- Form to delete a book -->
                <form action='index.php' method='POST'>
                    <input type='hidden' name='action' value='delete'>
                    <input type='hidden' name='id' value='" . $row['id'] . "'>
                    <input class='delete-button' type='submit' value='Delete'>
                </form>

                <!-- Form to update a book -->
                <form action='index.php' method='POST'>
                    <input type='hidden' name='action' value='update'>
                    <input type='hidden' name='id' value='" . $row['id'] . "'>
                    <input type='text' name='title' value='" . $row['title'] . "' required>
                    <input type='text' name='author' value='" . $row['author'] . "' required>
                    <input type='text' name='genre' value='" . $row['genre'] . "' required>
                    <input class='update-button' type='submit' value='Update'>
                </form>
            </td>";
            echo "</tr>";
        }

        echo "</table>";
    } else {
        echo "<p>No books in the library.</p>";
    }

    // Step 4: Close the database connection
    $db->close();
    ?>

</body>
</html>
