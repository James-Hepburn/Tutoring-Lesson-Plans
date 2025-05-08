<?php
// Handle user actions (register, login)
session_start();

// Step 1: Create or connect to the SQLite database
$db = new SQLite3('auth_system.db');

// Step 2: Create a 'users' table if it doesn't already exist
$db->exec("CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT NOT NULL UNIQUE,
    email TEXT NOT NULL UNIQUE,
    password TEXT NOT NULL,
    role TEXT DEFAULT 'viewer',
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
)");

// Check if admin exists, if not, insert it
$stmt = $db->prepare("SELECT * FROM users WHERE username = ?");
$stmt->bindValue(1, 'admin');
$result = $stmt->execute();

if (!$result->fetchArray()) {
  // Insert the admin user
  $db->exec("INSERT INTO users (username, email, password, role) VALUES ('admin', 'admin@example.com', 'admin_password', 'admin')");
}

// Step 3: Handle registration
if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['action']) && $_POST['action'] == 'register') {
    $username = $_POST['username'];
    $email = $_POST['email'];
    $password = $_POST['password'];

    // Check if username or email already exists
    $stmt = $db->prepare("SELECT * FROM users WHERE username = ? OR email = ?");
    $stmt->bindValue(1, $username);
    $stmt->bindValue(2, $email);
    $result = $stmt->execute();

    if ($result->fetchArray()) {
        echo "<p style='color: red;'>Username or email already exists!</p>";
    } else {
        // Insert new user
        $stmt = $db->prepare("INSERT INTO users (username, email, password, role) VALUES (?, ?, ?, 'viewer')");
        $stmt->bindValue(1, $username);
        $stmt->bindValue(2, $email);
        $stmt->bindValue(3, $password);
        $stmt->execute();
        echo "<p>Account created successfully!</p>";
    }
}

// Step 4: Handle login
if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['action']) && $_POST['action'] == 'login') {
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Fetch user from the database
    $stmt = $db->prepare("SELECT * FROM users WHERE username = ?");
    $stmt->bindValue(1, $username);
    $result = $stmt->execute();
    $user = $result->fetchArray();

    if ($user && $password === $user['password']) {
        // Set session variables
        $_SESSION['user_id'] = $user['id'];
        $_SESSION['role'] = $user['role'];
        $_SESSION['username'] = $user['username'];

        // Redirect based on role
        if ($user['role'] === 'admin') {
            header('Location: index.php?admin=true');
            exit();
        } else {
            header('Location: index.php?viewer=true');
            exit();
        }
    } else {
        echo "<p style='color: red;'>Invalid username or password!</p>";
    }
}

// Step 5: Handle Admin Dashboard View
if (isset($_SESSION['role']) && $_SESSION['role'] == 'admin') {
    echo "<h2>Admin Dashboard</h2>";
    echo "<p>Welcome, Admin!</p>";

    // Fetch and display all users
    $result = $db->query("SELECT * FROM users WHERE role = 'viewer'");
    echo "<table>";
    echo "<tr><th>Username</th><th>Email</th><th>Password</th><th>Created At</th></tr>";
    while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
        echo "<tr>";
        echo "<td>" . htmlspecialchars($row['username']) . "</td>";
        echo "<td>" . htmlspecialchars($row['email']) . "</td>";
        echo "<td>
                <span class='masked-password' 
                    onmouseover=\"this.textContent='" . htmlspecialchars($row['password']) . "'\"
                    onmouseout=\"this.textContent='" . str_repeat('*', strlen($row['password'])) . "'\">
                    " . str_repeat('*', strlen($row['password'])) . "
                </span>
              </td>";
        echo "<td>" . htmlspecialchars($row['created_at']) . "</td>";
        echo "</tr>";
    }
    echo "</table>";
}

// Step 6: Handle Viewer Dashboard View
if (isset($_SESSION['role']) && $_SESSION['role'] == 'viewer') {
    echo "<h2>Viewer Dashboard</h2>";
    echo "<p>Welcome, " . htmlspecialchars($_SESSION['username']) . "!</p>";

    // Handle password update form
    if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['action']) && $_POST['action'] == 'change_password') {
        $new_password = $_POST['new_password'];

        // Update the user's password in the database
        $stmt = $db->prepare("UPDATE users SET password = ? WHERE id = ?");
        $stmt->bindValue(1, $new_password);
        $stmt->bindValue(2, $_SESSION['user_id']);
        $stmt->execute();

        echo "<p>Password updated successfully!</p>";
    }

    // Display password change form
    echo '<h3>Change Password</h3>
        <form action="index.php" method="POST">
            <input type="hidden" name="action" value="change_password">
            <label for="new_password">New Password:</label>
            <input type="password" name="new_password" id="new_password" required>
            <input type="submit" value="Change Password">
        </form>';
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>User Authentication System</title>
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
        input[type="text"], input[type="password"], input[type="email"], input[type="submit"] {
          padding: 8px;
          margin: 5px 0 10px;
          width: 100%;
          box-sizing: border-box;
        }
        input[type="submit"] {
          background-color: #3498db;
          color: white;
          border: none;
          border-radius: 5px;
          cursor: pointer;
        }
        input[type="submit"]:hover {
          background-color: #2980b9;
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

  <?php if (!isset($_SESSION['username'])): ?>
  <h1>User Authentication System</h1>
  
  <!-- Registration Form -->
  <h2>Register</h2>
  <form action="index.php" method="POST">
      <input type="hidden" name="action" value="register">
      <label for="username">Username:</label>
      <input type="text" name="username" id="username" required>

      <label for="email">Email:</label>
      <input type="email" name="email" id="email" required>

      <label for="password">Password:</label>
      <input type="password" name="password" id="password" required>

      <input type="submit" value="Register">
  </form>

  <!-- Login Form -->
  <h2>Login</h2>
  <form action="index.php" method="POST">
      <input type="hidden" name="action" value="login">
      <label for="username">Username:</label>
      <input type="text" name="username" id="username" required>

      <label for="password">Password:</label>
      <input type="password" name="password" id="password" required>

      <input type="submit" value="Login">
  </form>
  <?php else: ?>
    <!-- Logout button -->
    <form action="logout.php" method="POST">
        <input type="submit" value="Logout">
    </form>
  <?php endif; ?>

</body>
</html>
