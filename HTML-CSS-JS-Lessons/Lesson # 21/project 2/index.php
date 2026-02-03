<?php
$db = new SQLite3('games.db');

$db->exec("DROP TABLE IF EXISTS games");

$db->exec("CREATE TABLE games (
    id INTEGER PRIMARY KEY,
    title TEXT,
    genre TEXT,
    platform TEXT,
    image TEXT
)");

$count = $db->querySingle("SELECT COUNT(*) FROM games");

if ($count == 0) {
  $games = [
      ["The Legend of Zelda: Breath of the Wild", "Adventure", "Switch", "https://wallpapercat.com/w/full/9/2/c/904450-2160x3840-mobile-4k-legend-of-zelda-breath-of-the-wild-background.jpg"],
      ["God of War", "Action", "PS5", "https://upload.wikimedia.org/wikipedia/en/a/a7/God_of_War_4_cover.jpg"],
      ["Hollow Knight", "Metroidvania", "PC", "https://upload.wikimedia.org/wikipedia/en/thumb/0/04/Hollow_Knight_first_cover_art.webp/274px-Hollow_Knight_first_cover_art.webp.png"],
      ["Stardew Valley", "Simulation", "Switch", "https://upload.wikimedia.org/wikipedia/en/thumb/f/fd/Logo_of_Stardew_Valley.png/250px-Logo_of_Stardew_Valley.png"],
      ["Elden Ring", "RPG", "PC", "https://upload.wikimedia.org/wikipedia/en/b/b9/Elden_Ring_Box_art.jpg"],
      ["Animal Crossing: New Horizons", "Simulation", "Switch", "https://i.ebayimg.com/images/g/aNgAAOSwVChgEZxF/s-l1200.jpg"],
      ["Spider-Man: Miles Morales", "Action", "PS5", "https://image.api.playstation.com/vulcan/ap/rnd/202008/1423/cZaoNGoCXpClHpljuPVPSUlw.jpg"],
      ["Minecraft", "Sandbox", "Multi-platform", "https://i.pinimg.com/474x/d2/45/9d/d2459de3246eb8a7d3504903d200f26c.jpg"],
      ["Hades", "Rogue-like", "Switch", "https://www.rpgfan.com/wp-content/uploads/2020/08/Hades-Cover-Art.jpg"],
      ["Red Dead Redemption 2", "Adventure", "PC", "https://upload.wikimedia.org/wikipedia/en/4/44/Red_Dead_Redemption_II.jpg"],
      ["Cuphead", "Platformer", "Xbox", "https://cdn.mobygames.com/covers/1122773-cuphead-windows-apps-front-cover.jpg"],
      ["Celeste", "Platformer", "PC", "https://upload.wikimedia.org/wikipedia/commons/thumb/6/68/Celeste_box_art_cropped.png/1200px-Celeste_box_art_cropped.png"]
  ];

  $stmt = $db->prepare("INSERT INTO games (title, genre, platform, image) VALUES (?, ?, ?, ?)");
  foreach ($games as $g) {
      $stmt->bindValue(1, $g[0]);
      $stmt->bindValue(2, $g[1]);
      $stmt->bindValue(3, $g[2]);
      $stmt->bindValue(4, $g[3]);
      $stmt->execute();
  }
}

// Pagination setup
$perPage = 4;
$page = isset($_GET['page']) ? max(1, (int)$_GET['page']) : 1;
$offset = ($page - 1) * $perPage;

// Get total count
$totalGames = $db->querySingle("SELECT COUNT(*) FROM games");
$totalPages = ceil($totalGames / $perPage);

// Get games for this page
$result = $db->query("SELECT * FROM games LIMIT $perPage OFFSET $offset");
$games = [];
while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
    $games[] = $row;
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Game Gallery</title>
    <style>
      body {
          font-family: Arial, sans-serif;
          background-color: #1f1f2e;
          color: #f0f0f0;
          text-align: center;
          padding: 20px;
          margin: 0;
      }

      h1 {
          margin-bottom: 30px;
      }

      .gallery {
          display: grid;
          grid-template-columns: repeat(2, 1fr);
          gap: 20px;
          max-width: 800px;
          margin: 0 auto;
      }

      .game-card {
          background-color: #2b2b3d;
          padding: 15px;
          border-radius: 10px;
          box-shadow: 0 0 10px #00000088;
      }

        .game-card img {
            width: 200px;
            height: 300px;
            object-fit: cover;
            border-radius: 6px;
            display: block;
            margin: 0 auto;
        }


      .pagination {
          margin-top: 25px;
      }

      .pagination a {
          color: #fff;
          background-color: #444;
          padding: 8px 12px;
          margin: 0 4px;
          text-decoration: none;
          border-radius: 5px;
      }

      .pagination a:hover {
          background-color: #666;
      }

      .pagination .active {
          background-color: #8e44ad;
          font-weight: bold;
      }

    </style>
</head>
<body>
    <h1>Video Game Gallery</h1>
    <div class="gallery">
        <?php foreach ($games as $game): ?>
            <div class="game-card">
                <img src="<?php echo $game['image']; ?>" alt="<?php echo $game['title']; ?>">
                <h3><?php echo $game['title']; ?></h3>
                <p><strong>Genre:</strong> <?php echo $game['genre']; ?></p>
                <p><strong>Platform:</strong> <?php echo $game['platform']; ?></p>
            </div>
        <?php endforeach; ?>
    </div>

    <div class="pagination">
        <?php if ($page > 1): ?>
            <a href="?page=<?php echo $page - 1; ?>">&laquo; Prev</a>
        <?php endif; ?>

        <?php for ($i = 1; $i <= $totalPages; $i++): ?>
            <a href="?page=<?php echo $i; ?>" <?php if ($i == $page) echo 'class="active"'; ?>>
                <?php echo $i; ?>
            </a>
        <?php endfor; ?>

        <?php if ($page < $totalPages): ?>
            <a href="?page=<?php echo $page + 1; ?>">Next &raquo;</a>
        <?php endif; ?>
    </div>
</body>
</html>
