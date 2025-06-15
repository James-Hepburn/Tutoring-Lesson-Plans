<html>
<head>
    <title>Sorting with ORDER BY</title>
</head>

<body>
<?php
// 1. Connect to (or create) the database
$db = new SQLite3('sorting.db');

// 2. Create a table called "posts" if it doesn't exist already
$db->exec("
    CREATE TABLE IF NOT EXISTS posts (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        title TEXT,
        content TEXT,
        created_at DATETIME
    )
");

// 3. If the table is empty, insert 30 sample posts with random dates
$post_count = $db->querySingle("SELECT COUNT(*) FROM posts");
if ($post_count == 0) {
    for ($i = 1; $i <= 30; $i++) {
        $title = "Post Title $i";
        $content = "This is the content for post number $i.";
        // random date within last 30 days
        $days_ago    = rand(0, 30);
        $created_at  = date('Y-m-d H:i:s', strtotime("-{$days_ago} days"));
        $db->exec("
            INSERT INTO posts (title, content, created_at)
            VALUES (
                '{$title}',
                '{$content}',
                '{$created_at}'
            )
        ");
    }
}

// --- SORTING STARTS HERE ---

// 4. Read sort parameters (default to 'created_at' DESC)
$allowed_cols = ['id','title','created_at'];
$allowed_dirs = ['asc','desc'];

$sort = isset($_GET['sort']) && in_array($_GET['sort'], $allowed_cols)
      ? $_GET['sort'] : 'created_at';
$dir  = isset($_GET['dir'])  && in_array(strtolower($_GET['dir']), $allowed_dirs)
      ? strtoupper($_GET['dir']) : 'DESC';

// 5. Build and run the query with ORDER BY
$query   = "
    SELECT *
    FROM posts
    ORDER BY {$sort} {$dir}
";
$results = $db->query($query);

// 6. Helper: generate clickable sort links
function sort_link($col, $label, $current_sort, $current_dir) {
    $next_dir = ($current_sort === $col && strtolower($current_dir) === 'asc')
                ? 'desc' : 'asc';
    $arrow = '';
    if ($current_sort === $col) {
        $arrow = strtolower($current_dir) === 'asc' ? ' ▲' : ' ▼';
    }
    return "<a href=\"?sort={$col}&dir={$next_dir}\">{$label}{$arrow}</a>";
}

// 7. Render the sorted table
echo "<h1>All Posts (sorted by " . htmlspecialchars($sort) . " " . htmlspecialchars($dir) . ")</h1>";
echo "<table border='1' cellpadding='8'>";
echo "<tr>
        <th>" . sort_link('id',         'ID',         $sort, $dir) . "</th>
        <th>" . sort_link('title',      'Title',      $sort, $dir) . "</th>
        <th>" . sort_link('created_at', 'Created At', $sort, $dir) . "</th>
      </tr>";

while ($post = $results->fetchArray(SQLITE3_ASSOC)) {
    echo "<tr>";
    echo "<td>" . htmlspecialchars($post['id']) . "</td>";
    echo "<td>" . htmlspecialchars($post['title']) . "</td>";
    echo "<td>" . htmlspecialchars($post['created_at']) . "</td>";
    echo "</tr>";
}
echo "</table>";
?>

<!--
Question:

You are building a simple product catalog that supports dynamic sorting. Write a PHP script that:

1. Connects to (or creates) an SQLite database file called `catalog.db`.
2. Creates a table named `products` with columns:
   - `id` (INTEGER PRIMARY KEY AUTOINCREMENT)
   - `name` (TEXT)
   - `description` (TEXT)
   - `price` (REAL)
   - `created_at` (DATETIME)
3. If the table is empty, inserts 40 sample products:
   - Names as "Product 1" through "Product 40"
   - Descriptions like "Description for product X"
   - Random prices between 0 and 200
   - Random `created_at` timestamps within the last 90 days
4. Displays all products in an HTML table.
5. Allows users to sort by `name`, `price`, or `created_at` in ascending or descending order via clickable column headers.
6. Highlights the active sort column and indicates direction with ▲/▼.
-->
</body>
</html>
