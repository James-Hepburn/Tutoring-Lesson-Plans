<!DOCTYPE html>
<html>
<head>
    <title>Recipe Manager</title>
    <style>
        body {
            font-family: 'Georgia', serif;
            background-color: #fefae0;
            margin: 0;
            padding: 20px;
            color: #283618;
        }
        h1, h2 {
            color: #606c38;
        }
        form {
            background-color: #fff;
            border: 2px solid #dda15e;
            padding: 20px;
            margin-bottom: 30px;
            border-radius: 10px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);
        }
        input[type="text"], input[type="number"], input[type="submit"] {
            margin: 10px 0;
            padding: 10px;
            width: 95%;
            border: 1px solid #606c38;
            border-radius: 5px;
        }
        input[type="submit"] {
            background-color: #606c38;
            color: white;
            border: none;
            cursor: pointer;
        }
        input[type="submit"]:hover {
            background-color: #283618;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
            background-color: #fff;
        }
        table, th, td {
            border: 1px solid #dda15e;
        }
        th, td {
            padding: 15px;
            text-align: left;
        }
        th {
            background-color: #dda15e;
            color: white;
        }
    </style>
</head>
<body>
    <?php
    // Connect to SQLite database
    $db = new SQLite3('recipes.db');

    // Create tables for recipes and ingredients
    $db->exec("CREATE TABLE IF NOT EXISTS recipes (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT NOT NULL,
        description TEXT
    )");

    $db->exec("CREATE TABLE IF NOT EXISTS ingredients (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        recipe_id INTEGER NOT NULL,
        name TEXT NOT NULL,
        quantity TEXT NOT NULL,
        FOREIGN KEY (recipe_id) REFERENCES recipes(id)
    )");

    // Pre-built recipes
    $db->exec("INSERT OR IGNORE INTO recipes (id, name, description) VALUES
        (1, 'Spaghetti Bolognese', 'A classic Italian pasta dish with rich meat sauce.'),
        (2, 'Pancakes', 'Fluffy and delicious breakfast pancakes.');");

    $db->exec("INSERT OR IGNORE INTO ingredients (recipe_id, name, quantity) VALUES
        (1, 'Spaghetti', '200g'),
        (1, 'Ground Beef', '300g'),
        (1, 'Tomato Sauce', '1 cup'),
        (1, 'Onion', '1, diced'),
        (1, 'Garlic', '2 cloves, minced'),
        (2, 'Flour', '1 cup'),
        (2, 'Milk', '1 cup'),
        (2, 'Eggs', '2'),
        (2, 'Sugar', '2 tbsp'),
        (2, 'Baking Powder', '1 tsp');");

    // Add a new recipe
    if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['add_recipe'])) {
        $name = $_POST['name'];
        $description = $_POST['description'];
        $db->exec("INSERT INTO recipes (name, description) VALUES ('$name', '$description')");
    }

    // Add a new ingredient
    if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['add_ingredient'])) {
        $recipe_id = $_POST['recipe_id'];
        $ingredient_name = $_POST['ingredient_name'];
        $quantity = $_POST['quantity'];
        $db->exec("INSERT INTO ingredients (recipe_id, name, quantity) VALUES ('$recipe_id', '$ingredient_name', '$quantity')");
    }

    // Fetch recipes
    $recipes = $db->query("SELECT * FROM recipes");

    echo "<h1>Recipe Manager</h1>";

    // Form to add a recipe
    echo "<h2>Add Recipe</h2>";
    echo "<form method='POST'>
        Recipe Name: <input type='text' name='name' required><br>
        Description: <input type='text' name='description'><br>
        <input type='submit' name='add_recipe' value='Add Recipe'>
    </form>";

    // Form to add an ingredient
    echo "<h2>Add Ingredient</h2>";
    echo "<form method='POST'>
        Recipe ID: <input type='number' name='recipe_id' required><br>
        Ingredient Name: <input type='text' name='ingredient_name' required><br>
        Quantity: <input type='text' name='quantity' required><br>
        <input type='submit' name='add_ingredient' value='Add Ingredient'>
    </form>";

    // Display recipes and their ingredients
    echo "<h2>All Recipes</h2>";
    while ($recipe = $recipes->fetchArray(SQLITE3_ASSOC)) {
        echo "<h3>" . htmlspecialchars($recipe['name']) . "</h3>";
        echo "<p>" . htmlspecialchars($recipe['description']) . "</p>";
        echo "<table>";
        echo "<tr><th>Ingredient</th><th>Quantity</th></tr>";

        $ingredients = $db->query("SELECT * FROM ingredients WHERE recipe_id = " . $recipe['id']);
        while ($ingredient = $ingredients->fetchArray(SQLITE3_ASSOC)) {
            echo "<tr>";
            echo "<td>" . htmlspecialchars($ingredient['name']) . "</td>";
            echo "<td>" . htmlspecialchars($ingredient['quantity']) . "</td>";
            echo "</tr>";
        }
        echo "</table>";
    }

    $db->close();
    ?>
</body>
</html>
