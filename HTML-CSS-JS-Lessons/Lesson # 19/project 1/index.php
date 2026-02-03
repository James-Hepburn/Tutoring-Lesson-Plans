<?php
// Connect to SQLite database
$db = new SQLite3("sports.db");

// Create tables if they don't exist
$db->exec("CREATE TABLE IF NOT EXISTS leagues (
    id INTEGER PRIMARY KEY AUTOINCREMENT, 
    league_name TEXT NOT NULL UNIQUE
)");

$db->exec("CREATE TABLE IF NOT EXISTS teams (
    id INTEGER PRIMARY KEY AUTOINCREMENT, 
    team_name TEXT NOT NULL, 
    city TEXT NOT NULL, 
    league_id INTEGER,
    FOREIGN KEY (league_id) REFERENCES leagues(id) ON DELETE CASCADE
)");

// Seed initial leagues (MLB, NHL, NFL)
$leagues = ["MLB", "NHL", "NFL"];
foreach ($leagues as $league) {
    $db->exec("INSERT OR IGNORE INTO leagues (league_name) VALUES ('$league')");
}

// Check if teams table is empty before inserting
$teamCount = $db->querySingle("SELECT COUNT(*) FROM teams");

if ($teamCount == 0) {
    $initialTeams = [
        ["New York Yankees", "New York", 1], ["Los Angeles Dodgers", "Los Angeles", 1], ["Chicago Cubs", "Chicago", 1], // MLB
        ["Toronto Maple Leafs", "Toronto", 2], ["Boston Bruins", "Boston", 2], ["Chicago Blackhawks", "Chicago", 2], // NHL
        ["New England Patriots", "Boston", 3], ["Green Bay Packers", "Green Bay", 3], ["Dallas Cowboys", "Dallas", 3] // NFL
    ];

    foreach ($initialTeams as $team) {
        $db->exec("INSERT INTO teams (team_name, city, league_id) VALUES ('$team[0]', '$team[1]', $team[2])");
    }
}


// Handle adding a new team
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["add_team"])) {
    $team_name = $db->escapeString($_POST["team_name"]);
    $city = $db->escapeString($_POST["city"]);
    $league_id = intval($_POST["league_id"]);

    $db->exec("INSERT INTO teams (team_name, city, league_id) VALUES ('$team_name', '$city', $league_id)");
    header("Location: index.php");
    exit;
}

// Fetch leagues
$leaguesResult = $db->query("SELECT * FROM leagues");

// Fetch teams if a league is selected
$teams = [];
if (isset($_GET["league_id"])) {
    $league_id = intval($_GET["league_id"]);
    $teams = $db->query("SELECT * FROM teams WHERE league_id = $league_id");
}

// Fetch team details if a team is selected
$teamDetails = null;
if (isset($_GET["team_id"])) {
    $team_id = intval($_GET["team_id"]);
    $teamDetails = $db->querySingle("SELECT * FROM teams WHERE id = $team_id", true);
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sports League Tracker</title>
    <style>
        body { font-family: Arial, sans-serif; max-width: 600px; margin: auto; padding: 20px; background: #f8f8f8; }
        h2, h3 { color: #333; }
        a { text-decoration: none; color: blue; }
        a:hover { text-decoration: underline; }
        ul { list-style: none; padding: 0; }
        li { background: white; margin: 5px 0; padding: 8px; border-radius: 5px; }
        form { margin-top: 10px; }
        input, select, button { margin-top: 5px; padding: 5px; width: 100%; }
        button { background: blue; color: white; border: none; cursor: pointer; }
        button:hover { background: darkblue; }
    </style>
</head>
<body>

    <h2>Sports League Tracker</h2>

    <!-- League List -->
    <h3>Leagues</h3>
    <ul>
        <?php
        $leaguesResult = $db->query("SELECT * FROM leagues");
        while ($league = $leaguesResult->fetchArray(SQLITE3_ASSOC)) {
            echo "<li><a href='index.php?league_id={$league['id']}'>{$league['league_name']}</a></li>";
        }
        ?>
    </ul>

    <!-- Teams List (If a League is Selected) -->
    <?php if (isset($_GET["league_id"])) { ?>
        <h3>Teams in <?= htmlspecialchars($db->querySingle("SELECT league_name FROM leagues WHERE id = $league_id")) ?></h3>
        <ul>
            <?php while ($team = $teams->fetchArray(SQLITE3_ASSOC)) { ?>
                <li>
                    <a href="index.php?league_id=<?= $league_id ?>&team_id=<?= $team['id'] ?>"><?= htmlspecialchars($team['team_name']) ?></a>
                </li>
            <?php } ?>
        </ul>
    <?php } ?>

    <!-- Team Details (If a Team is Selected) -->
    <?php if ($teamDetails) { ?>
        <h3>Team Details</h3>
        <p><strong>Team:</strong> <?= htmlspecialchars($teamDetails['team_name']) ?></p>
        <p><strong>City:</strong> <?= htmlspecialchars($teamDetails['city']) ?></p>
        <a href="index.php?league_id=<?= $teamDetails['league_id'] ?>">Back to Teams</a>
    <?php } ?>

    <!-- Add a New Team Form -->
    <h3>Add a Team</h3>
    <form method="post">
        <input type="text" name="team_name" placeholder="Team Name" required>
        <input type="text" name="city" placeholder="City" required>
        <select name="league_id" required>
            <option value="">Select League</option>
            <?php
            $leaguesDropdown = $db->query("SELECT * FROM leagues");
            while ($league = $leaguesDropdown->fetchArray(SQLITE3_ASSOC)) {
                echo "<option value='{$league['id']}'>{$league['league_name']}</option>";
            }
            ?>
        </select>
        <button type="submit" name="add_team">Add Team</button>
    </form>

</body>
</html>
