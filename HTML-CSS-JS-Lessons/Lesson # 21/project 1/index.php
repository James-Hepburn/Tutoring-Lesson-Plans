<html>
<head>
    <title>Adopt a Pet</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #fefaf6;
            text-align: center;
        }
        .pet {
            border: 1px solid #ccc;
            padding: 10px;
            margin: 20px auto;
            width: 300px;
            background-color: #fff;
            border-radius: 10px;
        }
        img {
            max-width: 100%;
            height: auto;
            border-radius: 8px;
        }
        .pagination {
            margin-top: 20px;
        }
        .pagination a {
            margin: 0 5px;
            text-decoration: none;
        }
    </style>
</head>

<body>
<?php
$db = new SQLite3("adoptapet.db");

// Create table
$db->exec("CREATE TABLE IF NOT EXISTS pets (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    species TEXT,
    gender TEXT,
    age INTEGER,
    image TEXT
)");

// Seed pets only if table is empty
$count = $db->querySingle("SELECT COUNT(*) FROM pets");
if ($count == 0) {
  $pets = [
      ["Tuna", "Cat", "Female", 3, "public/pet1.jpg"],
      ["Barkley", "Dog", "Male", 2, "public/pet2.jpg"],
      ["Sprinkles", "Hamster", "Female", 1, "public/pet3.jpg"],
      ["Waffles", "Rabbit", "Male", 4, "public/pet4.jpg"],
      ["Clawdia", "Cat", "Female", 5, "public/pet5.webp"],
      ["Rex", "Dog", "Male", 6, "public/pet6.jpg"],
      ["Pebbles", "Turtle", "Female", 10, "public/pet7.jpg"],
      ["Fidget", "Ferret", "Male", 3, "public/pet8.jpg"],
      ["Zazu", "Parrot", "Female", 2, "public/pet9.webp"]
  ];

    foreach ($pets as $pet) {
        [$name, $species, $gender, $age, $image] = $pet;
        $stmt = $db->prepare("INSERT INTO pets (name, species, gender, age, image) VALUES (?, ?, ?, ?, ?)");
        $stmt->bindValue(1, $name, SQLITE3_TEXT);
        $stmt->bindValue(2, $species, SQLITE3_TEXT);
        $stmt->bindValue(3, $gender, SQLITE3_TEXT);
        $stmt->bindValue(4, $age, SQLITE3_INTEGER);
        $stmt->bindValue(5, $image, SQLITE3_TEXT);
        $stmt->execute();
    }
}

// Get page number
$page = isset($_GET['page']) ? intval($_GET['page']) : 1;
if ($page < 1) $page = 1;

// Pagination setup
$pets_per_page = 3;
$offset = ($page - 1) * $pets_per_page;
$total_pets = $db->querySingle("SELECT COUNT(*) FROM pets");
$total_pages = ceil($total_pets / $pets_per_page);

// Get pets for current page
$results = $db->query("SELECT * FROM pets LIMIT $pets_per_page OFFSET $offset");

// Display
echo "<h1>🐾 Adopt a Pet 🐾</h1>";

while ($row = $results->fetchArray(SQLITE3_ASSOC)) {
    echo "<div class='pet'>";
    echo "<img src='" . htmlspecialchars($row['image']) . "' alt='Pet Image'>";
    echo "<h2>" . htmlspecialchars($row['name']) . "</h2>";
    echo "<p><em>" . htmlspecialchars($row['species']) . "</em></p>";
    echo "<p>Gender: " . htmlspecialchars($row['gender']) . "</p>";
    echo "<p>Age: " . htmlspecialchars($row['age']) . " years</p>";
    echo "</div>";
}

// Pagination links
echo "<div class='pagination'>";
for ($i = 1; $i <= $total_pages; $i++) {
    if ($i == $page) {
        echo "<strong>$i</strong> ";
    } else {
        echo "<a href='?page=$i'>$i</a> ";
    }
}
echo "</div>";

$db->close();
?>
</body>
</html>
