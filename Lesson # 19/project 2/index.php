<?php
// Connect to SQLite database
$db = new SQLite3("bookclub.db");

// Create tables if they don't exist
$db->exec("CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT, 
    name TEXT NOT NULL
)");

$db->exec("CREATE TABLE IF NOT EXISTS book_clubs (
    id INTEGER PRIMARY KEY AUTOINCREMENT, 
    club_name TEXT NOT NULL UNIQUE
)");

$db->exec("CREATE TABLE IF NOT EXISTS books (
    id INTEGER PRIMARY KEY AUTOINCREMENT, 
    title TEXT NOT NULL, 
    author TEXT NOT NULL
)");

$db->exec("CREATE TABLE IF NOT EXISTS user_clubs (
    user_id INTEGER, 
    club_id INTEGER, 
    PRIMARY KEY (user_id, club_id),
    FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE,
    FOREIGN KEY (club_id) REFERENCES book_clubs(id) ON DELETE CASCADE
)");

$db->exec("CREATE TABLE IF NOT EXISTS club_books (
    club_id INTEGER, 
    book_id INTEGER, 
    PRIMARY KEY (club_id, book_id),
    FOREIGN KEY (club_id) REFERENCES book_clubs(id) ON DELETE CASCADE,
    FOREIGN KEY (book_id) REFERENCES books(id) ON DELETE CASCADE
)");

// Preloaded Book Clubs
$preloaded_clubs = [
    "Science Fiction Book Club",
    "Mystery Book Club",
    "Fantasy Book Club"
];

foreach ($preloaded_clubs as $club) {
    $db->exec("INSERT OR IGNORE INTO book_clubs (club_name) VALUES ('$club')");
}

// Preloaded Books
$preloaded_books = [
    ["Dune", "Frank Herbert", 1], ["Neuromancer", "William Gibson", 1], ["Foundation", "Isaac Asimov", 1], // Sci-Fi
    ["The Hound of the Baskervilles", "Arthur Conan Doyle", 2], ["Gone Girl", "Gillian Flynn", 2], ["The Girl with the Dragon Tattoo", "Stieg Larsson", 2], // Mystery
    ["The Hobbit", "J.R.R. Tolkien", 3], ["Harry Potter and the Sorcerer’s Stone", "J.K. Rowling", 3], ["The Name of the Wind", "Patrick Rothfuss", 3] // Fantasy
];

foreach ($preloaded_books as $book) {
    $db->exec("INSERT OR IGNORE INTO books (title, author) VALUES ('$book[0]', '$book[1]')");
    $book_id = $db->querySingle("SELECT id FROM books WHERE title = '$book[0]'");
    $db->exec("INSERT OR IGNORE INTO club_books (club_id, book_id) VALUES ($book[2], $book_id)");
}

// Handle Form Submissions
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST["add_user"])) {
        $name = $db->escapeString($_POST["name"]);
        $db->exec("INSERT INTO users (name) VALUES ('$name')");
    }

    if (isset($_POST["join_club"])) {
        $user_id = intval($_POST["user_id"]);
        $club_id = intval($_POST["club_id"]);
        $db->exec("INSERT OR IGNORE INTO user_clubs (user_id, club_id) VALUES ($user_id, $club_id)");
    }

    if (isset($_POST["leave_club"])) {
        $user_id = intval($_POST["user_id"]);
        $club_id = intval($_POST["club_id"]);
        $db->exec("DELETE FROM user_clubs WHERE user_id = $user_id AND club_id = $club_id");
    }
}

// Fetch dropdown data
$users = $db->query("SELECT * FROM users");
$clubs = $db->query("SELECT * FROM book_clubs");
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Book Club Tracker</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css">
</head>
<body class="bg-light">
    <div class="container mt-4">
        <h2 class="text-center mb-4">Book Club Tracker</h2>

        <!-- Add User -->
        <h4>Add a User</h4>
        <form method="post">
            <input type="text" name="name" class="form-control mb-2" placeholder="Enter name" required>
            <button type="submit" name="add_user" class="btn btn-primary">Add User</button>
        </form>

        <hr>

        <!-- Join/Leave Book Club -->
        <h4>Join/Leave a Book Club</h4>
        <form method="post" class="row g-2">
            <div class="col-md-4">
                <select name="user_id" class="form-select" required>
                    <option value="">Select User</option>
                    <?php while ($row = $users->fetchArray(SQLITE3_ASSOC)) { ?>
                        <option value="<?= $row['id'] ?>"><?= htmlspecialchars($row['name']) ?></option>
                    <?php } ?>
                </select>
            </div>
            <div class="col-md-4">
                <select name="club_id" class="form-select" required>
                    <option value="">Select Book Club</option>
                    <?php while ($row = $clubs->fetchArray(SQLITE3_ASSOC)) { ?>
                        <option value="<?= $row['id'] ?>"><?= htmlspecialchars($row['club_name']) ?></option>
                    <?php } ?>
                </select>
            </div>
            <div class="col-md-2">
                <button type="submit" name="join_club" class="btn btn-success">Join</button>
            </div>
            <div class="col-md-2">
                <button type="submit" name="leave_club" class="btn btn-danger">Leave</button>
            </div>
        </form>

        <hr>

        <!-- List Book Clubs and Their Books -->
        <h4>Book Clubs & Their Books</h4>
        <ul class="list-group">
            <?php
            $clubs = $db->query("SELECT * FROM book_clubs");
            while ($club = $clubs->fetchArray(SQLITE3_ASSOC)) {
                echo "<li class='list-group-item'><strong>" . htmlspecialchars($club['club_name']) . "</strong><ul>";
                $books = $db->query("
                    SELECT books.title, books.author FROM books 
                    JOIN club_books ON books.id = club_books.book_id 
                    WHERE club_books.club_id = {$club['id']}
                ");
                while ($book = $books->fetchArray(SQLITE3_ASSOC)) {
                    echo "<li>" . htmlspecialchars($book['title']) . " by " . htmlspecialchars($book['author']) . "</li>";
                }
                echo "</ul></li>";
            }
            ?>
        </ul>

        <hr>

        <!-- List Users in Each Club -->
        <h4>Users in Each Club</h4>
        <ul class="list-group">
            <?php
            $clubs = $db->query("SELECT * FROM book_clubs");
            while ($club = $clubs->fetchArray(SQLITE3_ASSOC)) {
                echo "<li class='list-group-item'><strong>" . htmlspecialchars($club['club_name']) . "</strong><ul>";
                $members = $db->query("
                    SELECT users.name FROM users 
                    JOIN user_clubs ON users.id = user_clubs.user_id 
                    WHERE user_clubs.club_id = {$club['id']}
                ");
                while ($member = $members->fetchArray(SQLITE3_ASSOC)) {
                    echo "<li>" . htmlspecialchars($member['name']) . "</li>";
                }
                echo "</ul></li>";
            }
            ?>
        </ul>

    </div>
</body>
</html>
