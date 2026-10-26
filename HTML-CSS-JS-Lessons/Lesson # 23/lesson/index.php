<html>
<head>
    <title>Aggregate Functions: COUNT, SUM, AVG, MIN, MAX and ROUND</title>
</head>

<body>
<?php
/*
    Aggregate functions take MANY rows and squash them into ONE value.

    COUNT(*)      how many rows there are
    SUM(column)   adds up every value in the column
    AVG(column)   the average of the column
    MIN(column)   the smallest value (also works on text and dates)
    MAX(column)   the largest value (also works on text and dates)

    ROUND(value, decimals)  is not an aggregate, but you'll almost always
    use it with AVG, because averages often have long decimals.

    Aggregates work on whatever rows are left after WHERE.
    So "SELECT AVG(price) FROM sales WHERE category = 'Bakery'"
    only averages the Bakery rows.
*/

// 1. Connect to (or create) the database
$db = new SQLite3('store.db');

// 2. Create a 'sales' table. Each row is one sale of one product.
$db->exec("
    CREATE TABLE IF NOT EXISTS sales (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        product TEXT,
        category TEXT,
        price REAL,
        quantity INTEGER,
        sale_date DATE
    )
");

// 3. If the table is empty, insert 60 random sales
if ($db->querySingle("SELECT COUNT(*) FROM sales") == 0) {
    $products = [
        ['Apple Juice',    'Drinks', 3.50],
        ['Orange Juice',   'Drinks', 3.75],
        ['Cola',           'Drinks', 1.99],
        ['Chocolate Bar',  'Snacks', 2.25],
        ['Potato Chips',   'Snacks', 2.99],
        ['Apple Pie',      'Bakery', 8.50],
        ['Banana Bread',   'Bakery', 6.00],
        ['Croissant',      'Bakery', 2.75],
        ['Cheddar Cheese', 'Dairy',  5.49],
        ['Chocolate Milk', 'Dairy',  2.49],
    ];

    $stmt = $db->prepare("
        INSERT INTO sales (product, category, price, quantity, sale_date)
        VALUES (:product, :category, :price, :quantity, :sale_date)
    ");

    for ($i = 0; $i < 60; $i++) {
        $item = $products[array_rand($products)];
        $stmt->bindValue(':product',   $item[0]);
        $stmt->bindValue(':category',  $item[1]);
        $stmt->bindValue(':price',     $item[2]);
        $stmt->bindValue(':quantity',  rand(1, 10));
        $stmt->bindValue(':sale_date', date('Y-m-d', strtotime('-' . rand(0, 60) . ' days')));
        $stmt->execute();
        $stmt->reset();
    }
}

// 4. COUNT: how many rows?
//    querySingle() is handy here because an aggregate returns just one value.
$total_sales  = $db->querySingle("SELECT COUNT(*) FROM sales");
$bakery_sales = $db->querySingle("SELECT COUNT(*) FROM sales WHERE category = 'Bakery'");

echo "<h2>COUNT</h2>";
echo "<p>Total number of sales: $total_sales</p>";
echo "<p>Number of Bakery sales: $bakery_sales</p>";

// 5. SUM: add up a column.
//    You can also SUM a calculation. price * quantity is the money made on
//    each row, so SUM(price * quantity) is the total money made.
$units_sold    = $db->querySingle("SELECT SUM(quantity) FROM sales");
$total_revenue = $db->querySingle("SELECT SUM(price * quantity) FROM sales");

echo "<h2>SUM</h2>";
echo "<p>Total units sold: $units_sold</p>";
echo "<p>Total revenue (not rounded): $total_revenue</p>";

// 6. AVG: the average of a column.
//    Notice how messy the decimals can be.
$avg_quantity = $db->querySingle("SELECT AVG(quantity) FROM sales");
$avg_price    = $db->querySingle("SELECT AVG(price) FROM sales WHERE category = 'Drinks'");

echo "<h2>AVG</h2>";
echo "<p>Average quantity per sale: $avg_quantity</p>";
echo "<p>Average price of a Drinks sale: $avg_price</p>";

// 7. ROUND: clean up the decimals.
//    ROUND(value, 2) keeps 2 decimal places (good for money).
//    ROUND(value, 1) keeps 1. ROUND(value) or ROUND(value, 0) gives a whole number.
$revenue_rounded = $db->querySingle("SELECT ROUND(SUM(price * quantity), 2) FROM sales");
$avg_qty_1       = $db->querySingle("SELECT ROUND(AVG(quantity), 1) FROM sales");
$avg_qty_0       = $db->querySingle("SELECT ROUND(AVG(quantity)) FROM sales");

echo "<h2>ROUND</h2>";
echo "<p>Total revenue rounded to 2 decimals: $$revenue_rounded</p>";
echo "<p>Average quantity rounded to 1 decimal: $avg_qty_1</p>";
echo "<p>Average quantity rounded to a whole number: $avg_qty_0</p>";

// 8. MIN and MAX: smallest and largest values.
//    They work on numbers, and also on dates (earliest/latest) and text (alphabetical).
$cheapest   = $db->querySingle("SELECT MIN(price) FROM sales");
$priciest   = $db->querySingle("SELECT MAX(price) FROM sales");
$biggest    = $db->querySingle("SELECT MAX(quantity) FROM sales");
$first_sale = $db->querySingle("SELECT MIN(sale_date) FROM sales");
$last_sale  = $db->querySingle("SELECT MAX(sale_date) FROM sales");

echo "<h2>MIN and MAX</h2>";
echo "<p>Cheapest price: $$cheapest</p>";
echo "<p>Highest price: $$priciest</p>";
echo "<p>Most items bought in one sale: $biggest</p>";
echo "<p>First sale: $first_sale</p>";
echo "<p>Most recent sale: $last_sale</p>";

// 9. Close the database connection
$db->close();
?>

<!--
Question:

You are building a stats page for a small bookstore. Write a PHP script that:

1. Connects to (or creates) an SQLite database file called `bookstore.db`.
2. Creates a table named `orders` with columns:
   - `id` (INTEGER PRIMARY KEY AUTOINCREMENT)
   - `book_title` (TEXT)
   - `genre` (TEXT)
   - `price` (REAL)
   - `copies` (INTEGER)
   - `order_date` (DATE)
3. If the table is empty, inserts 50 random orders using at least 6 book titles
   across at least 3 genres, with prices between 8 and 40, copies between 1 and 5,
   and dates within the last 60 days.
4. Displays these stats, each with a label:
   - Total number of orders (COUNT)
   - Total copies sold (SUM)
   - Total revenue, rounded to 2 decimals (SUM + ROUND)
   - Average copies per order, rounded to 1 decimal (AVG + ROUND)
   - Cheapest and most expensive book price (MIN, MAX)
   - First and most recent order date (MIN, MAX)
5. Displays the same stats as step 4, but only for orders from the last 7 days.
-->
</body>
</html>
