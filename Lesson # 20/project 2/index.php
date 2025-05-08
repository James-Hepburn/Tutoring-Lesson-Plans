<?php
$db = new SQLite3('grades.db');
$db->exec("PRAGMA foreign_keys = ON");

// CHECK if students table exists
$tableCheck = $db->querySingle("SELECT name FROM sqlite_master WHERE type='table' AND name='students'");
if (!$tableCheck) {
    // INIT TABLES
    $db->exec("CREATE TABLE students (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT,
        grade_math REAL,
        grade_science REAL,
        grade_english REAL
    )");

    $db->exec("CREATE TABLE grade_log (
        log_id INTEGER PRIMARY KEY AUTOINCREMENT,
        student_id INTEGER,
        subject TEXT,
        old_grade REAL,
        new_grade REAL,
        changed_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        FOREIGN KEY (student_id) REFERENCES students(id)
    )");

    $db->exec("CREATE TABLE status_flags (
        student_id INTEGER PRIMARY KEY,
        status TEXT,
        FOREIGN KEY (student_id) REFERENCES students(id)
    )");

    // INSERT sample data
    $db->exec("INSERT INTO students (name, grade_math, grade_science, grade_english) VALUES
        ('Alice Johnson', 78, 92, 88),
        ('Bob Lee', 45, 52, 67),
        ('Clara Wang', 88, 91, 93)
    ");

    // CREATE triggers for grade logging
    $subjects = ['math', 'science', 'english'];
    foreach ($subjects as $subject) {
        $db->exec("CREATE TRIGGER log_{$subject}_grade
            BEFORE UPDATE ON students
            FOR EACH ROW
            WHEN OLD.grade_{$subject} != NEW.grade_{$subject}
            BEGIN
                INSERT INTO grade_log (student_id, subject, old_grade, new_grade)
                VALUES (OLD.id, '{$subject}', OLD.grade_{$subject}, NEW.grade_{$subject});
            END;
        ");
    }

    // CREATE trigger for academic status
    $db->exec("CREATE TRIGGER update_status
        AFTER UPDATE ON students
        FOR EACH ROW
        BEGIN
            INSERT INTO status_flags (student_id, status)
            VALUES (
                NEW.id,
                CASE
                    WHEN NEW.grade_math < 50 OR NEW.grade_science < 50 OR NEW.grade_english < 50 THEN 'Failing'
                    WHEN NEW.grade_math >= 85 AND NEW.grade_science >= 85 AND NEW.grade_english >= 85 THEN 'Honour Roll'
                    ELSE 'Passing'
                END
            )
            ON CONFLICT(student_id) DO UPDATE SET
                status = excluded.status;
        END;
    ");
}

// HANDLE FORM SUBMIT
if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $id = $_POST['id'];
    $math = $_POST['grade_math'];
    $science = $_POST['grade_science'];
    $english = $_POST['grade_english'];
    $stmt = $db->prepare("UPDATE students SET grade_math = ?, grade_science = ?, grade_english = ? WHERE id = ?");
    $stmt->bindValue(1, $math);
    $stmt->bindValue(2, $science);
    $stmt->bindValue(3, $english);
    $stmt->bindValue(4, $id);
    $stmt->execute();
    header("Location: " . $_SERVER['PHP_SELF']);
    exit();
}

// GET DATA
$students = $db->query("SELECT s.*, sf.status FROM students s LEFT JOIN status_flags sf ON s.id = sf.student_id");
$logs = $db->query("SELECT l.*, s.name FROM grade_log l JOIN students s ON l.student_id = s.id ORDER BY changed_at DESC");
?>

<!DOCTYPE html>
<html>
<head>
    <title>Student Grades Portal</title>
    <style>
        body { font-family: Arial; background: #f5f5f5; padding: 20px; }
        h2 { margin-top: 40px; }
        table { border-collapse: collapse; width: 100%; background: #fff; margin-top: 10px; }
        th, td { border: 1px solid #ccc; padding: 8px; text-align: center; }
        form { display: inline-block; }
        input[type='number'] { width: 60px; }
    </style>
</head>
<body>

<h1>📚 Student Grades Portal</h1>

<h2>All Students</h2>
<table>
    <tr>
        <th>Name</th>
        <th>Math</th>
        <th>Science</th>
        <th>English</th>
        <th>Status</th>
        <th>Edit Grades</th>
    </tr>
    <?php while ($s = $students->fetchArray(SQLITE3_ASSOC)): ?>
        <tr>
            <form method="POST">
                <td><?= htmlspecialchars($s['name']) ?></td>
                <td><input type="number" name="grade_math" value="<?= $s['grade_math'] ?>" required></td>
                <td><input type="number" name="grade_science" value="<?= $s['grade_science'] ?>" required></td>
                <td><input type="number" name="grade_english" value="<?= $s['grade_english'] ?>" required></td>
                <td><?= $s['status'] ?? 'Not Set' ?></td>
                <td>
                    <input type="hidden" name="id" value="<?= $s['id'] ?>">
                    <input type="submit" value="Update">
                </td>
            </form>
        </tr>
    <?php endwhile; ?>
</table>

<h2>📋 Grade Change Log</h2>
<table>
    <tr>
        <th>Student</th>
        <th>Subject</th>
        <th>Old Grade</th>
        <th>New Grade</th>
        <th>Changed At</th>
    </tr>
    <?php while ($l = $logs->fetchArray(SQLITE3_ASSOC)): ?>
        <tr>
            <td><?= htmlspecialchars($l['name']) ?></td>
            <td><?= ucfirst($l['subject']) ?></td>
            <td><?= $l['old_grade'] ?></td>
            <td><?= $l['new_grade'] ?></td>
            <td><?= $l['changed_at'] ?></td>
        </tr>
    <?php endwhile; ?>
</table>

</body>
</html>
