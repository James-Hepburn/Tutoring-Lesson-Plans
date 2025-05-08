<?php
$db = new SQLite3('data.db');

// Create tables
$db->exec("CREATE TABLE IF NOT EXISTS employees (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    weekly_hours REAL DEFAULT 0,
    overtime_status TEXT DEFAULT 'Normal'
)");

$db->exec("CREATE TABLE IF NOT EXISTS timesheets (
    id INTEGER PRIMARY KEY,
    employee_id INTEGER,
    date TEXT,
    clock_in TEXT,
    clock_out TEXT,
    total_hours REAL,
    FOREIGN KEY (employee_id) REFERENCES employees(id)
)");

$db->exec("CREATE TABLE IF NOT EXISTS timesheet_log (
    log_id INTEGER PRIMARY KEY,
    timesheet_id INTEGER,
    action TEXT,
    timestamp TEXT DEFAULT CURRENT_TIMESTAMP
)");

// Create triggers (only once)
$db->exec("CREATE TRIGGER IF NOT EXISTS calculate_hours_insert
AFTER INSERT ON timesheets
BEGIN
    UPDATE timesheets
    SET total_hours = 
        (strftime('%s', NEW.clock_out) - strftime('%s', NEW.clock_in)) / 3600.0
    WHERE id = NEW.id;

    UPDATE employees
    SET weekly_hours = weekly_hours + (
        (strftime('%s', NEW.clock_out) - strftime('%s', NEW.clock_in)) / 3600.0
    )
    WHERE id = NEW.employee_id;
END;");

$db->exec("CREATE TRIGGER IF NOT EXISTS check_overtime
AFTER UPDATE OF weekly_hours ON employees
WHEN NEW.weekly_hours > 40
BEGIN
    UPDATE employees
    SET overtime_status = 'Overtime'
    WHERE id = NEW.id;
END;");

$db->exec("CREATE TRIGGER IF NOT EXISTS log_timesheet_update
AFTER UPDATE ON timesheets
BEGIN
    INSERT INTO timesheet_log (timesheet_id, action)
    VALUES (OLD.id, 'Updated');
END;");

// Handle new employee form
if (isset($_POST['new_employee'])) {
    $name = $_POST['name'];
    $db->exec("INSERT INTO employees (name) VALUES ('$name')");
}

// Handle new timesheet form
if (isset($_POST['new_timesheet'])) {
    $eid = $_POST['employee_id'];
    $date = $_POST['date'];
    $in = $_POST['clock_in'];
    $out = $_POST['clock_out'];
    $db->exec("INSERT INTO timesheets (employee_id, date, clock_in, clock_out)
               VALUES ('$eid', '$date', '$in', '$out')");
}

// Fetch data
$employees = $db->query("SELECT * FROM employees");
$timesheets = $db->query("
    SELECT t.*, e.name FROM timesheets t
    JOIN employees e ON e.id = t.employee_id
    ORDER BY t.date DESC
");
?>

<!DOCTYPE html>
<html>
<head>
  <title>Timesheet Tracker</title>
  <style>
    body { font-family: sans-serif; padding: 20px; max-width: 800px; margin: auto; }
    table { width: 100%; border-collapse: collapse; margin-bottom: 30px; }
    th, td { border: 1px solid #ccc; padding: 8px; }
    th { background-color: #eee; }
    form { margin-bottom: 20px; }
  </style>
</head>
<body>

<h1>Timesheet Tracker</h1>

<h2>Add Employee</h2>
<form method="POST">
  <input type="text" name="name" placeholder="Employee name" required>
  <button type="submit" name="new_employee">Add</button>
</form>

<h2>Add Timesheet</h2>
<form method="POST">
  <input type="number" name="employee_id" placeholder="Employee ID" required>
  <input type="date" name="date" required>
  <input type="time" name="clock_in" required>
  <input type="time" name="clock_out" required>
  <button type="submit" name="new_timesheet">Submit</button>
</form>

<h2>Employees</h2>
<table>
  <tr><th>ID</th><th>Name</th><th>Weekly Hours</th><th>Status</th></tr>
  <?php while ($row = $employees->fetchArray()) { ?>
    <tr>
      <td><?= $row['id'] ?></td>
      <td><?= htmlspecialchars($row['name']) ?></td>
      <td><?= round($row['weekly_hours'], 2) ?></td>
      <td><?= $row['overtime_status'] ?></td>
    </tr>
  <?php } ?>
</table>

<h2>Timesheets</h2>
<table>
  <tr><th>ID</th><th>Employee</th><th>Date</th><th>Clock In</th><th>Clock Out</th><th>Total Hours</th></tr>
  <?php while ($row = $timesheets->fetchArray()) { ?>
    <tr>
      <td><?= $row['id'] ?></td>
      <td><?= htmlspecialchars($row['name']) ?></td>
      <td><?= $row['date'] ?></td>
      <td><?= $row['clock_in'] ?></td>
      <td><?= $row['clock_out'] ?></td>
      <td><?= round($row['total_hours'], 2) ?></td>
    </tr>
  <?php } ?>
</table>

</body>
</html>
