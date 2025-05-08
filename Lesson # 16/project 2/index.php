<?php
// Database connection
$db = new SQLite3('movies.db');

// Create table if not exists
$db->exec("CREATE TABLE IF NOT EXISTS movies (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT NOT NULL,
    director TEXT NOT NULL,
    genre TEXT NOT NULL,
    year INTEGER NOT NULL,
    rating INTEGER NOT NULL CHECK(rating BETWEEN 1 AND 5)
)");

// Handle form submissions
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $action = $_POST['action'];

    if ($action == 'add') {
        $title = $_POST['title'];
        $director = $_POST['director'];
        $genre = $_POST['genre'];
        $year = $_POST['year'];
        $rating = $_POST['rating'];

        $result = $db->exec("INSERT INTO movies (title, director, genre, year, rating) VALUES ('$title', '$director', '$genre', $year, $rating)");

        if ($result) {
            header("Location: index.php"); // Redirect to refresh and show new movie in the list
            exit(); // Ensure no further code runs after the redirect
        } else {
            echo "<p>Error adding movie: " . $db->lastErrorMsg() . "</p>";
        }
    }
}

// Pre-add some movies if not already present
$movies = [
    ['title' => 'Pulp Fiction', 'director' => 'Quentin Tarantino', 'genre' => 'Crime', 'year' => 1994, 'rating' => 5],
    ['title' => 'The Lord of the Rings: The Fellowship of the Ring', 'director' => 'Peter Jackson', 'genre' => 'Fantasy', 'year' => 2001, 'rating' => 5],
    ['title' => 'Forrest Gump', 'director' => 'Robert Zemeckis', 'genre' => 'Drama', 'year' => 1994, 'rating' => 4],
    ['title' => 'The Dark Knight', 'director' => 'Christopher Nolan', 'genre' => 'Action', 'year' => 2008, 'rating' => 5],
    ['title' => 'La La Land', 'director' => 'Damien Chazelle', 'genre' => 'Musical', 'year' => 2016, 'rating' => 4]
];

foreach ($movies as $movie) {
    $title = $movie['title'];
    $check = $db->querySingle("SELECT COUNT(*) as count FROM movies WHERE title = '$title'");
    if ($check == 0) {
        $db->exec("INSERT INTO movies (title, director, genre, year, rating) VALUES ('{$movie['title']}', '{$movie['director']}', '{$movie['genre']}', {$movie['year']}, {$movie['rating']})");
    }
}
?>
<!DOCTYPE html>
<html>
<head>
  <title>Movie Catalogue</title>
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
      input[type="text"], input[type="number"], select, input[type="submit"] {
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
  </style>
</head>
<body>
  <h1>Movie Catalogue</h1>

  <!-- Form to Add a New Movie -->
  <h2>Add a New Movie</h2>
  <form action="index.php" method="POST">
    <input type="hidden" name="action" value="add">
    <label for="title">Title:</label>
    <input type="text" name="title" id="title" required>

    <label for="director">Director:</label>
    <input type="text" name="director" id="director" required>

    <label for="genre">Genre:</label>
    <input type="text" name="genre" id="genre" required>

    <label for="year">Release Year:</label>
    <input type="number" name="year" id="year" required min="1900" max="2100">

    <label for="rating">Rating (1-5):</label>
    <input type="number" name="rating" id="rating" required min="1" max="5">

    <input type="submit" value="Add Movie">
  </form>

  <hr>

  <!-- List of All Movies -->
  <h2>All Movies</h2>
  <?php
  // Display all movies by default
  $allMovies = $db->query("SELECT * FROM movies");
  if ($allMovies->numColumns() > 0) {
    echo "<table>";
    echo "<tr><th>ID</th><th>Title</th><th>Director</th><th>Genre</th><th>Year</th><th>Rating</th></tr>";

    while ($row = $allMovies->fetchArray(SQLITE3_ASSOC)) {
      echo "<tr>";
      echo "<td>" . $row['id'] . "</td>";
      echo "<td>" . $row['title'] . "</td>";
      echo "<td>" . $row['director'] . "</td>";
      echo "<td>" . $row['genre'] . "</td>";
      echo "<td>" . $row['year'] . "</td>";
      echo "<td>" . $row['rating'] . " stars</td>";
      echo "</tr>";
    }
    echo "</table>";
  } else {
    echo "<p>No movies in the catalogue yet.</p>";
  }
  ?>

  <!-- Filtering Form -->
  <h2>Filter Movies</h2>
  <form method="GET" action="index.php">
    <label for="filter_genre">Filter by Genre:</label>
    <input type="text" name="filter_genre" id="filter_genre">

    <label for="sort_by">Sort by:</label>
    <select name="sort_by" id="sort_by">
      <option value="title">Title</option>
      <option value="year">Release Year</option>
      <option value="rating">Rating</option>
    </select>
    <input type="submit" value="Apply Filters">
  </form>

  <!-- Display Filtered Movies -->
  <h2>Filtered Movies</h2>
  <?php
  // Handle filtered movies
  $query = "SELECT * FROM movies";
  if (!empty($_GET['filter_genre']) || !empty($_GET['sort_by'])) {
    if (!empty($_GET['filter_genre'])) {
      $filter_genre = $_GET['filter_genre'];
      $query .= " WHERE genre LIKE '%$filter_genre%'";
    }
    if (!empty($_GET['sort_by'])) {
      $sort_by = $_GET['sort_by'];
      $query .= " ORDER BY $sort_by";
    }

    $filteredMovies = $db->query($query);

    if ($filteredMovies->numColumns() > 0) {
      echo "<table>";
      echo "<tr><th>ID</th><th>Title</th><th>Director</th><th>Genre</th><th>Year</th><th>Rating</th></tr>";

      while ($row = $filteredMovies->fetchArray(SQLITE3_ASSOC)) {
        echo "<tr>";
        echo "<td>" . $row['id'] . "</td>";
        echo "<td>" . $row['title'] . "</td>";
        echo "<td>" . $row['director'] . "</td>";
        echo "<td>" . $row['genre'] . "</td>";
        echo "<td>" . $row['year'] . "</td>";
        echo "<td>" . $row['rating'] . " stars</td>";
        echo "</tr>";
      }
      echo "</table>";
    } else {
      echo "<p>No movies match the filter criteria.</p>";
    }
  } else {
    echo "<p>Please apply a filter to view results here.</p>";
  }

  // Close database connection
  $db->close();
  ?>
</body>
</html>
