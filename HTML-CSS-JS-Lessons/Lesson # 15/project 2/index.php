<html>
<head>
  <title>To Do List</title>

  <style>
    body {
      font-family: Arial, sans-serif;
      background-color: #f4f4f4;
      margin: 0;
      padding: 0;
      display: flex;
      justify-content: center;
      align-items: center;
      height: 100vh;
    }

    h1 {
      color: #333;
    }

    .container {
      width: 90%;
      max-width: 600px;
      background: #fff;
      border-radius: 8px;
      box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1);
      padding: 20px;
      box-sizing: border-box;
    }

    form {
      display: flex;
      margin-bottom: 20px;
    }

    input[type="text"] {
      flex: 1;
      padding: 10px;
      border: 1px solid #ddd;
      border-radius: 4px;
      font-size: 16px;
    }

    button[type="submit"] {
      padding: 10px 20px;
      border: none;
      border-radius: 4px;
      background-color: #007bff;
      color: white;
      font-size: 16px;
      cursor: pointer;
      margin-left: 10px;
    }

    button[type="submit"]:hover {
      background-color: #0056b3;
    }

    ul {
      list-style: none;
      padding: 0;
    }

    li {
      background: #f9f9f9;
      border: 1px solid #ddd;
      border-radius: 4px;
      margin-bottom: 10px;
      padding: 10px;
      display: flex;
      justify-content: space-between;
      align-items: center;
    }

    form.inline-form {
      display: inline;
    }

    .delete-button {
      background-color: #dc3545;
      border: none;
      color: white;
      padding: 5px 10px;
      border-radius: 4px;
      cursor: pointer;
    }

    .delete-button:hover {
      background-color: #c82333;
    }
  </style>
</head>
  
<body>
  <div class = "container">
    <h1>To Do List</h1>
  
    <form method = "post" action = "index.php">
      <input type = "text" placeholder = "New task" name = "task">
      <button type = "submit">Add Task</button>
    </form>
    
    <?php 
      $file = "tasks.txt";
      $tasks = get_tasks ($file);
  
      function get_tasks ($file) {
        if (file_exists ($file)) {
          return file ($file, FILE_IGNORE_NEW_LINES);
        } else {
          return [];
        }
      }
  
      function save_tasks ($file, $tasks) {
        file_put_contents ($file, implode (PHP_EOL, $tasks)); // joins the list into a string, each on a new line
      }
  
      if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset ($_POST ['task'])) {
        $tasks [] = $_POST ['task'];
        save_tasks ($file, $tasks);
      }
  
      if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset ($_POST ['delete'])) {
        $del = intval ($_POST ['delete']);
        if (isset ($tasks [$del])) {
          unset ($tasks [$del]);
          $tasks = array_values ($tasks); // reindex the list
          save_tasks ($file, $tasks);
        }
      }
  
      if (empty ($tasks)) {
        echo "<p>No tasks available.</p>";
      } else {
        echo "<ul>";
        foreach ($tasks as $index => $task) {
          echo "<li>";
          echo $task; 
          echo "<form method='post' style='display:inline;'>";
          echo "<input type='hidden' name='delete' value='$index'>";
          echo "<button type='submit'>Delete</button>";
          echo "</form>";
          echo "</li>";
        }
        echo "</ul>";
      }
    ?> 
  </div>
</body>
</html>
