<!DOCTYPE html>
<html>
<head>
    <title>Artist and Song Management</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            background-color: #f4f4f9;
            color: #333;
        }
        h1, h2 {
            color: #4CAF50;
        }
        form {
            background-color: #ffffff;
            border: 1px solid #ccc;
            border-radius: 8px;
            padding: 20px;
            margin-bottom: 20px;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
        }
        form label {
            display: block;
            margin-bottom: 8px;
            font-weight: bold;
        }
        form input, form button {
            width: 100%;
            padding: 10px;
            margin-bottom: 10px;
            border: 1px solid #ccc;
            border-radius: 4px;
            font-size: 16px;
        }
        form button {
            background-color: #4CAF50;
            color: white;
            border: none;
            cursor: pointer;
        }
        form button:hover {
            background-color: #45a049;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }
        table, th, td {
            border: 1px solid #ccc;
        }
        th, td {
            padding: 12px;
            text-align: left;
        }
        th {
            background-color: #4CAF50;
            color: white;
        }
        tr:nth-child(even) {
            background-color: #f9f9f9;
        }
        audio {
            margin-top: 10px;
        }
    </style>
</head>
<body>
    <h1>Artist and Song Management</h1>

    <?php
    $db = new SQLite3('music.db');

    $db->exec("
        CREATE TABLE IF NOT EXISTS artists (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT
        )
    ");

    $db->exec("
        CREATE TABLE IF NOT EXISTS songs (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            artist_id INTEGER,
            title TEXT,
            file_path TEXT,
            FOREIGN KEY (artist_id) REFERENCES artists(id)
        )
    ");

    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        if (isset($_POST['add_artist'])) {
            $artist_name = $_POST['artist_name'];
            $db->exec("INSERT INTO artists (name) VALUES ('$artist_name')");
            echo "<div class='message success'>Artist '$artist_name' added successfully!</div>";
        } elseif (isset($_POST['add_song'])) {
            $artist_id = $_POST['artist_id'];
            $song_title = $_POST['song_title'];
            $file_path = $_POST['file_path'];
            $db->exec("INSERT INTO songs (artist_id, title, file_path) VALUES ($artist_id, '$song_title', '$file_path')");
            echo "<div class='message success'>Song '$song_title' added successfully!</div>";
        }
    }
    ?>

    <h2>Add New Artist</h2>
    <form method="POST">
        <label>Artist Name:</label>
        <input type="text" name="artist_name" required>
        <button type="submit" name="add_artist">Add Artist</button>
    </form>

    <h2>Add New Song</h2>
    <form method="POST">
        <label>Artist ID:</label>
        <input type="number" name="artist_id" required>
        <label>Song Title:</label>
        <input type="text" name="song_title" required>
        <label>File Path (URL):</label>
        <input type="text" name="file_path">
        <button type="submit" name="add_song">Add Song</button>
    </form>

    <h2>All Artists and Songs</h2>
    <?php
    $result = $db->query("
        SELECT artists.name AS artist_name, songs.title AS song_title, songs.file_path
        FROM artists
        LEFT JOIN songs ON artists.id = songs.artist_id
    ");

    echo "<table>";
    echo "<tr><th>Artist</th><th>Song</th><th>Play</th></tr>";

    while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
        echo "<tr>";
        echo "<td>" . $row['artist_name'] . "</td>";
        echo "<td>" . ($row['song_title'] ?? 'N/A') . "</td>";
        echo "<td>";
        if (!empty($row['file_path'])) {
            if (strpos($row['file_path'], 'youtube.com') !== false || strpos($row['file_path'], 'youtu.be') !== false) {
                preg_match('/(youtu\.be\/|v=)([a-zA-Z0-9_-]+)/', $row['file_path'], $matches);
                $video_id = $matches[2] ?? '';
                if ($video_id) {
                    echo "<iframe width='200' height='150' src='https://www.youtube.com/embed/$video_id' frameborder='0' allow='accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture' allowfullscreen></iframe>";
                } else {
                    echo "Invalid YouTube link";
                }
            } else {
                echo "<audio controls><source src='" . $row['file_path'] . "' type='audio/mpeg'>Your browser does not support the audio element.</audio>";
            }
        } else {
            echo "N/A";
        }
        echo "</td>";
        echo "</tr>";
    }
    echo "</table>";
    $db->close();
    ?>
</body>
</html>
