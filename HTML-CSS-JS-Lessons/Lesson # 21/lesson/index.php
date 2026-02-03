<html>
<head>
    <title>Pagination</title>
</head>

<body>
<?php
// 1. Connect to (or create) the database
$db = new SQLite3('pagination.db');

// 2. Create a table called "posts" if it doesn't exist already
$db->exec("
    CREATE TABLE IF NOT EXISTS posts (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        title TEXT,
        content TEXT
    )
");

// 3. Check if the table is empty (i.e., it has 0 posts)
$post_count = $db->querySingle("SELECT COUNT(*) FROM posts");
if ($post_count == 0) {
    // If empty, insert 30 sample posts
    for ($i = 1; $i <= 30; $i++) {
        $title = "Post Title $i";
        $content = "This is the content for post number $i.";
        $db->exec("INSERT INTO posts (title, content) VALUES ('$title', '$content')");
    }
}

// --- PAGINATION STARTS HERE ---

// 4. Figure out which page the user is on (default to page 1 if not set)
$page = isset($_GET['page']) ? intval($_GET['page']) : 1;
if ($page < 1) $page = 1; // just in case someone types a negative number

// 5. Set how many posts to show per page
$posts_per_page = 5;

// 6. Calculate how many posts to skip before showing results
// Example: Page 1 skips 0, Page 2 skips 5, Page 3 skips 10, etc.
$skip = ($page - 1) * $posts_per_page;

// 7. Get the correct posts from the database for this page
$query = "SELECT * FROM posts LIMIT $posts_per_page OFFSET $skip";
$results = $db->query($query);

// 8. Show the posts
echo "<h1>Blog Posts - Page $page</h1>";
while ($post = $results->fetchArray(SQLITE3_ASSOC)) {
    echo "<h2>" . htmlspecialchars($post['title']) . "</h2>";
    echo "<p>" . htmlspecialchars($post['content']) . "</p>";
    echo "<hr>";
}

// --- PAGINATION LINKS ---

// 9. Get total number of posts in the table
$total_posts = $db->querySingle("SELECT COUNT(*) FROM posts");

// 10. Figure out how many total pages there should be
$total_pages = ceil($total_posts / $posts_per_page);

// 11. Show page links (1, 2, 3, ...)
echo "<div style='margin-top: 20px;'>";
for ($i = 1; $i <= $total_pages; $i++) {
    if ($i == $page) {
        // Bold the current page number
        echo "<strong>$i</strong> ";
    } else {
        // Link to all other pages
        echo "<a href='?page=$i'>$i</a> ";
    }
}
echo "</div>";
?>

    <!--
    Question:

    You are building a simple product catalog that supports pagination. Write a PHP script that performs the following steps:

    1. Create or connect to an SQLite database file called `catalog.db`.
    2. Create a table named `products` with the following columns:
       - `id`: INTEGER, primary key, auto-incremented.
       - `name`: TEXT, the name of the product.
       - `description`: TEXT, a short description of the product.
    3. If the table is empty, insert 40 sample products. Each product should have a name like "Product 1", "Product 2", etc., and a generic description like "This is the description for product X".
    4. Display 8 products per page. If no page is set or a negative number is used, default to page 1.
    5. Show the correct products for the current page.
    6. At the bottom of the page, include numbered links for each page (e.g., 1 2 3 4 5). The current page number should appear in bold.
    -->

</body>
</html>
