<html>
<head>
    <title>SQL Triggers Example</title>
</head>

<body>
    <?php
    /*
    SQL Triggers are special database functions that automatically execute
    when a specific event occurs (INSERT, UPDATE, DELETE).

    Purpose of SQL Triggers:
    - Automate tasks such as logging or validation.
    - Enforce data integrity.
    - Monitor database changes without modifying application code.

    Example Scenario:
    - We track email changes in a 'users' table using a 'logs' table.
    - BEFORE an update, the old email is stored in a log table.
    */

    // Step 1: Create or connect to the SQLite database
    $db = new SQLite3('triggers.db');

    // Step 2: Create the 'users' table
    $db->exec("DROP TABLE IF EXISTS users");
    $db->exec("CREATE TABLE users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT,
        email TEXT
    )");

    // Step 3: Create the 'email_log' table
    $db->exec("DROP TABLE IF EXISTS email_log");
    $db->exec("CREATE TABLE email_log (
        log_id INTEGER PRIMARY KEY AUTOINCREMENT,
        user_id INTEGER,
        old_email TEXT,
        new_email TEXT,
        changed_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        FOREIGN KEY (user_id) REFERENCES users(id)
    )");

    // Step 4: Create a Trigger that logs email updates
    $db->exec("DROP TRIGGER IF EXISTS before_email_update");
    $db->exec("CREATE TRIGGER before_email_update
        BEFORE UPDATE ON users
        FOR EACH ROW
        BEGIN
            INSERT INTO email_log (user_id, old_email, new_email)
            VALUES (OLD.id, OLD.email, NEW.email);
        END;");

    // Step 5: Insert sample data into 'users' table
    $db->exec("INSERT INTO users (name, email) VALUES ('Alice', 'alice@example.com')");
    $db->exec("INSERT INTO users (name, email) VALUES ('Bob', 'bob@example.com')");

    // Step 6: Perform an UPDATE to trigger the logging
    $db->exec("UPDATE users SET email = 'alice.new@example.com' WHERE id = 1");

    // Step 7: Retrieve and display the email log
    $result = $db->query("SELECT users.name, email_log.old_email, email_log.new_email, email_log.changed_at
                           FROM email_log
                           INNER JOIN users ON email_log.user_id = users.id");

    echo "<h2>Email Change Log</h2>";
    echo "<table border='1'>";
    echo "<tr><th>Name</th><th>Old Email</th><th>New Email</th><th>Changed At</th></tr>";

    while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
        echo "<tr>";
        echo "<td>" . $row['name'] . "</td>";
        echo "<td>" . $row['old_email'] . "</td>";
        echo "<td>" . $row['new_email'] . "</td>";
        echo "<td>" . $row['changed_at'] . "</td>";
        echo "</tr>";
    }

    echo "</table>";

    // Step 8: Close the database connection
    $db->close();
    ?>

  <!--
    Question:

    You are tasked with creating a simple payroll system that tracks employee salary updates.
    Write a PHP script that does the following:

    1. Create or connect to an SQLite database file called payroll.db.
    2. Create two tables:
       - employees: Contains the following columns:
         * id: An INTEGER that is the primary key and auto-increments.
         * name: A TEXT field for the employee's full name.
         * salary: A REAL field for the employee's current salary.
       - salary_log: Contains the following columns:
         * log_id: An INTEGER that is the primary key and auto-increments.
         * employee_id: An INTEGER field that references the id in the employees table.
         * old_salary: A REAL field storing the previous salary.
         * new_salary: A REAL field storing the updated salary.
         * changed_at: A TIMESTAMP that records the update time (default to CURRENT_TIMESTAMP).
    3. Create a trigger that automatically logs salary changes whenever an employee’s salary is updated.
    4. Insert the following data into the employees table:
       - Name: "John Doe", Salary: 50000
       - Name: "Jane Smith", Salary: 60000
    5. Perform an UPDATE statement to change John Doe’s salary to 55000.
    6. Retrieve and display the salary change log in an HTML table.
  -->
</body>
</html>
