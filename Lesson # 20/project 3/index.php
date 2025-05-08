<?php
// Connect to SQLite
$db = new SQLite3('library.db');

// Create tables if not exist
$db->exec("CREATE TABLE IF NOT EXISTS students (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  name TEXT NOT NULL
)");

$db->exec("CREATE TABLE IF NOT EXISTS books (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  title TEXT NOT NULL,
  author TEXT NOT NULL,
  total_copies INTEGER NOT NULL,
  available_copies INTEGER NOT NULL
)");

$db->exec("CREATE TABLE IF NOT EXISTS rentals (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  student_id INTEGER,
  book_id INTEGER,
  date_borrowed TEXT,
  due_date TEXT,
  date_returned TEXT
)");

// Triggers
$db->exec("CREATE TRIGGER IF NOT EXISTS check_availability
BEFORE INSERT ON rentals
FOR EACH ROW
BEGIN
  SELECT CASE
    WHEN (SELECT available_copies FROM books WHERE id = NEW.book_id) <= 0
    THEN RAISE(ABORT, 'Book not available')
  END;
END;");

$db->exec("CREATE TRIGGER IF NOT EXISTS decrement_copies
AFTER INSERT ON rentals
FOR EACH ROW
BEGIN
  UPDATE books SET available_copies = available_copies - 1 WHERE id = NEW.book_id;
END;");

$db->exec("CREATE TRIGGER IF NOT EXISTS increment_copies
AFTER UPDATE OF date_returned ON rentals
FOR EACH ROW
WHEN NEW.date_returned IS NOT NULL
BEGIN
  UPDATE books SET available_copies = available_copies + 1 WHERE id = NEW.book_id;
END;");

// Handle form actions
function safe($str) {
  return htmlspecialchars($str);
}

if (isset($_POST['add_student'])) {
  $name = $_POST['student_name'];
  $db->exec("INSERT INTO students (name) VALUES ('$name')");
}

if (isset($_POST['add_book'])) {
  $title = $_POST['title'];
  $author = $_POST['author'];
  $copies = (int)$_POST['copies'];
  $db->exec("INSERT INTO books (title, author, total_copies, available_copies) VALUES ('$title', '$author', $copies, $copies)");
}

if (isset($_POST['borrow'])) {
  $student_id = $_POST['student_id'];
  $book_id = $_POST['book_id'];
  $today = date('Y-m-d');
  $due = date('Y-m-d', strtotime('+7 days'));
  try {
    $db->exec("INSERT INTO rentals (student_id, book_id, date_borrowed, due_date) VALUES ($student_id, $book_id, '$today', '$due')");
  } catch (Exception $e) {
    echo "<p style='color:red;'>Error: " . $e->getMessage() . "</p>";
  }
}

if (isset($_POST['return'])) {
  $rental_id = $_POST['rental_id'];
  $today = date('Y-m-d');
  $db->exec("UPDATE rentals SET date_returned = '$today' WHERE id = $rental_id");
}
?>

<h1>📚 Library Rental System</h1>

<h2>Add Student</h2>
<form method="post">
  <input name="student_name" placeholder="Student Name" required>
  <button name="add_student">Add Student</button>
</form>

<h2>Add Book</h2>
<form method="post">
  <input name="title" placeholder="Book Title" required>
  <input name="author" placeholder="Author" required>
  <input name="copies" type="number" placeholder="Copies" required>
  <button name="add_book">Add Book</button>
</form>

<h2>Borrow Book</h2>
<form method="post">
  <select name="student_id" required>
    <option value="">Select Student</option>
    <?php
    $res = $db->query("SELECT * FROM students");
    while ($row = $res->fetchArray()) {
      echo "<option value='{$row['id']}'>" . safe($row['name']) . "</option>";
    }
    ?>
  </select>
  <select name="book_id" required>
    <option value="">Select Book</option>
    <?php
    $res = $db->query("SELECT * FROM books");
    while ($row = $res->fetchArray()) {
      echo "<option value='{$row['id']}'>" . safe($row['title']) . " by " . safe($row['author']) . " ({$row['available_copies']} available)</option>";
    }
    ?>
  </select>
  <button name="borrow">Borrow</button>
</form>

<h2>Return Book</h2>
<form method="post">
  <select name="rental_id" required>
    <option value="">Select Rental</option>
    <?php
    $res = $db->query("SELECT rentals.id AS rid, students.name AS sname, books.title AS btitle, rentals.date_borrowed, rentals.date_returned
      FROM rentals
      JOIN students ON students.id = rentals.student_id
      JOIN books ON books.id = rentals.book_id
      WHERE rentals.date_returned IS NULL");
    while ($row = $res->fetchArray()) {
      echo "<option value='{$row['rid']}'>" . safe($row['sname']) . " - " . safe($row['btitle']) . " (Borrowed: {$row['date_borrowed']})</option>";
    }
    ?>
  </select>
  <button name="return">Return</button>
</form>

<h2>📖 All Rentals</h2>
<table border="1" cellpadding="5">
  <tr><th>Student</th><th>Book</th><th>Borrowed</th><th>Due</th><th>Returned</th></tr>
  <?php
  $res = $db->query("SELECT students.name AS sname, books.title AS btitle, rentals.* FROM rentals
    JOIN students ON students.id = rentals.student_id
    JOIN books ON books.id = rentals.book_id
    ORDER BY rentals.id DESC");
  while ($row = $res->fetchArray()) {
    echo "<tr>
      <td>" . safe($row['sname']) . "</td>
      <td>" . safe($row['btitle']) . "</td>
      <td>{$row['date_borrowed']}</td>
      <td>{$row['due_date']}</td>
      <td>" . ($row['date_returned'] ?? "Not returned") . "</td>
    </tr>";
  }
  ?>
</table>
