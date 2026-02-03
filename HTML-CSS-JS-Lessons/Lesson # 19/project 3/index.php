<?php
// Connect to SQLite database
$db = new SQLite3("skills.db");

// Create tables if they don't exist
$db->exec("CREATE TABLE IF NOT EXISTS people (
    id INTEGER PRIMARY KEY AUTOINCREMENT, 
    name TEXT NOT NULL
)");

$db->exec("CREATE TABLE IF NOT EXISTS skills (
    id INTEGER PRIMARY KEY AUTOINCREMENT, 
    skill_name TEXT NOT NULL
)");

$db->exec("CREATE TABLE IF NOT EXISTS people_skills (
    person_id INTEGER, 
    skill_id INTEGER, 
    PRIMARY KEY (person_id, skill_id),
    FOREIGN KEY (person_id) REFERENCES people(id) ON DELETE CASCADE,
    FOREIGN KEY (skill_id) REFERENCES skills(id) ON DELETE CASCADE
)");

// Handle form submissions
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST["add_person"])) {
        $name = $db->escapeString($_POST["name"]);
        $db->exec("INSERT INTO people (name) VALUES ('$name')");
    }

    if (isset($_POST["add_skill"])) {
        $skill = $db->escapeString($_POST["skill"]);
        $db->exec("INSERT INTO skills (skill_name) VALUES ('$skill')");
    }

    if (isset($_POST["assign_skill"])) {
        $person_id = intval($_POST["person_id"]);
        $skill_id = intval($_POST["skill_id"]);
        $db->exec("INSERT OR IGNORE INTO people_skills (person_id, skill_id) VALUES ($person_id, $skill_id)");
    }
}

// Fetch data for dropdowns
$people = $db->query("SELECT * FROM people");
$skills = $db->query("SELECT * FROM skills");

// Filtering
$filtered_people = [];
$filtered_skills = [];

if (isset($_GET["filter_skill"]) && $_GET["filter_skill"] !== "") {
    $skill_id = intval($_GET["filter_skill"]);
    $result = $db->query("
        SELECT p.name FROM people p
        JOIN people_skills ps ON p.id = ps.person_id
        WHERE ps.skill_id = $skill_id
    ");
    while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
        $filtered_people[] = $row['name'];
    }
}

if (isset($_GET["filter_person"]) && $_GET["filter_person"] !== "") {
    $person_id = intval($_GET["filter_person"]);
    $result = $db->query("
        SELECT s.skill_name FROM skills s
        JOIN people_skills ps ON s.id = ps.skill_id
        WHERE ps.person_id = $person_id
    ");
    while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
        $filtered_skills[] = $row['skill_name'];
    }
}

// Re-fetch data for dropdowns since previous fetches exhausted them
$people_dropdown = $db->query("SELECT * FROM people");
$skills_dropdown = $db->query("SELECT * FROM skills");
$skills_filter = $db->query("SELECT * FROM skills");
$people_filter = $db->query("SELECT * FROM people");

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Skill Sharing Site</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css">
</head>
<body class="bg-light">
    <div class="container mt-4">
        <h2 class="text-center mb-4">Skill Sharing Website</h2>

        <!-- Add People & Skills -->
        <div class="row">
            <div class="col-md-6">
                <h4>Add a Person</h4>
                <form method="post">
                    <input type="text" name="name" class="form-control mb-2" placeholder="Enter name" required>
                    <button type="submit" name="add_person" class="btn btn-primary">Add Person</button>
                </form>
            </div>

            <div class="col-md-6">
                <h4>Add a Skill</h4>
                <form method="post">
                    <input type="text" name="skill" class="form-control mb-2" placeholder="Enter skill" required>
                    <button type="submit" name="add_skill" class="btn btn-success">Add Skill</button>
                </form>
            </div>
        </div>

        <hr>

        <!-- Assign Skills to People -->
        <h4>Assign Skill to a Person</h4>
        <form method="post" class="row g-2">
            <div class="col-md-4">
                <select name="person_id" class="form-select" required>
                    <option value="">Select Person</option>
                    <?php while ($row = $people_dropdown->fetchArray(SQLITE3_ASSOC)) { ?>
                        <option value="<?= $row['id'] ?>"><?= htmlspecialchars($row['name']) ?></option>
                    <?php } ?>
                </select>
            </div>

            <div class="col-md-4">
                <select name="skill_id" class="form-select" required>
                    <option value="">Select Skill</option>
                    <?php while ($row = $skills_dropdown->fetchArray(SQLITE3_ASSOC)) { ?>
                        <option value="<?= $row['id'] ?>"><?= htmlspecialchars($row['skill_name']) ?></option>
                    <?php } ?>
                </select>
            </div>

            <div class="col-md-4">
                <button type="submit" name="assign_skill" class="btn btn-warning">Assign Skill</button>
            </div>
        </form>

        <hr>

        <!-- Filter by Skill -->
        <h4>Filter People by Skill</h4>
        <form method="get">
            <select name="filter_skill" class="form-select mb-2">
                <option value="">Select Skill</option>
                <?php while ($row = $skills_filter->fetchArray(SQLITE3_ASSOC)) { ?>
                    <option value="<?= $row['id'] ?>"><?= htmlspecialchars($row['skill_name']) ?></option>
                <?php } ?>
            </select>
            <button type="submit" class="btn btn-info">Filter</button>
        </form>

        <ul class="list-group mt-2">
            <?php if (!empty($filtered_people)) { 
                foreach ($filtered_people as $name) { ?>
                    <li class="list-group-item"><?= htmlspecialchars($name) ?></li>
            <?php } } else { ?>
                <li class="list-group-item">No results found</li>
            <?php } ?>
        </ul>

        <hr>

        <!-- Filter by Person -->
        <h4>Filter Skills by Person</h4>
        <form method="get">
            <select name="filter_person" class="form-select mb-2">
                <option value="">Select Person</option>
                <?php while ($row = $people_filter->fetchArray(SQLITE3_ASSOC)) { ?>
                    <option value="<?= $row['id'] ?>"><?= htmlspecialchars($row['name']) ?></option>
                <?php } ?>
            </select>
            <button type="submit" class="btn btn-secondary">Filter</button>
        </form>

        <ul class="list-group mt-2">
            <?php if (!empty($filtered_skills)) { 
                foreach ($filtered_skills as $skill_name) { ?>
                    <li class="list-group-item"><?= htmlspecialchars($skill_name) ?></li>
            <?php } } else { ?>
                <li class="list-group-item">No results found</li>
            <?php } ?>
        </ul>

    </div>
</body>
</html>
