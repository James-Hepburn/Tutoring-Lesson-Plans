<html>
<head>
</head>

<body>
  <?php
  // Step 1: Create or connect to the SQLite database
  $db = new SQLite3('products.db');

  // Step 2: Create a 'products' table
  $db->exec("DROP TABLE IF EXISTS products");
  $db->exec("
  CREATE TABLE IF NOT EXISTS products (
      id INTEGER PRIMARY KEY AUTOINCREMENT,
      product_name TEXT,
      price REAL,
      quantity INTEGER,
      description TEXT
  )");

  // Step 3: Check if products already exist before inserting
  $result = $db->query("SELECT COUNT(*) as count FROM products");
  $row = $result->fetchArray(SQLITE3_ASSOC);

  $db->exec("INSERT INTO products (product_name, price, quantity, description)
             VALUES ('Gaming Laptop', 1200.99, 10, 'A high-performance laptop for gaming and work')");

  $db->exec("INSERT INTO products (product_name, price, quantity, description)
             VALUES ('Wireless Mouse', 25.50, 200, 'Ergonomic wireless mouse')");

  $db->exec("INSERT INTO products (product_name, price, quantity, description)
             VALUES ('Keyboard', 45.00, 150, 'Mechanical keyboard with RGB lighting')");

  // Step 4: Update a product (Example: updating product with id=1)
  $db->exec("UPDATE products SET price = 1200.55 WHERE id = 1");

  // Step 5: Delete a product (Example: deleting product with id=3)
  $db->exec("DELETE FROM products WHERE id = 3");

  // Step 6: Retrieve the products from the database
  $result = $db->query("SELECT * FROM products");

  // Step 7: Display the products in an HTML table
  if ($result) {
      echo "<h2>Product Inventory</h2>";
      echo "<table border='1'>";
      echo "<tr><th>ID</th><th>Product Name</th><th>Price</th><th>Quantity</th><th>Description</th></tr>";

      while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
          echo "<tr>";
          echo "<td>" . $row['id'] . "</td>";
          echo "<td>" . $row['product_name'] . "</td>";
          echo "<td>$" . $row['price'] . "</td>";
          echo "<td>" . $row['quantity'] . "</td>";
          echo "<td>" . $row['description'] . "</td>";
          echo "</tr>";
      }

      echo "</table>";
  } else {
      echo "No products found.";
  }

  // Step 8: Close the database connection
  $db->close();
  ?>

</body>
</html>
