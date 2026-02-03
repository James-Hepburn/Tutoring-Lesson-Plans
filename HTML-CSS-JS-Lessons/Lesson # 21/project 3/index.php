<?php
// Connect to SQLite
$db = new PDO('sqlite:flashcards.db');

// Create table and seed if not exists
$db->exec("CREATE TABLE IF NOT EXISTS flashcards (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    question TEXT NOT NULL,
    answer TEXT NOT NULL
)");

$count = $db->query("SELECT COUNT(*) FROM flashcards")->fetchColumn();
if ($count == 0) {
    $sample = [
        ['What is the capital of France?', 'Paris'],
        ['What is 9 + 10?', '19'],
        ['What’s the largest ocean?', 'Pacific Ocean'],
        ['What is the boiling point of water?', '100°C'],
        ['Who wrote Hamlet?', 'William Shakespeare'],
        ['What planet is known as the Red Planet?', 'Mars'],
        ['What’s the fastest land animal?', 'Cheetah'],
        ['What’s H2O?', 'Water'],
        ['How many continents are there?', '7'],
        ['What’s the square root of 64?', '8']
    ];
    $stmt = $db->prepare("INSERT INTO flashcards (question, answer) VALUES (?, ?)");
    foreach ($sample as $card) {
        $stmt->execute($card);
    }
}

// Pagination
$perPage = 5;
$page = isset($_GET['page']) ? max(1, intval($_GET['page'])) : 1;
$offset = ($page - 1) * $perPage;

$total = $db->query("SELECT COUNT(*) FROM flashcards")->fetchColumn();
$pages = ceil($total / $perPage);

$cards = $db->query("SELECT * FROM flashcards LIMIT $perPage OFFSET $offset")->fetchAll(PDO::FETCH_ASSOC);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Flashcard App</title>
    <style>
        body {
            font-family: Arial;
            background: #fefefe;
            text-align: center;
            margin: 40px;
        }
        .flashcard {
            background: #fff8dc;
            border: 2px solid #f0c36d;
            padding: 20px;
            margin: 10px auto;
            width: 60%;
            border-radius: 10px;
            box-shadow: 2px 2px 5px #aaa;
        }
        .answer {
            display: none;
            margin-top: 10px;
            color: #333;
        }
        .btn {
            padding: 8px 16px;
            margin-top: 10px;
            cursor: pointer;
            background: #ffcc70;
            border: none;
            border-radius: 5px;
        }
        .nav {
            margin-top: 30px;
        }
        .nav a {
            text-decoration: none;
            margin: 0 10px;
            font-weight: bold;
            color: #333;
        }
    </style>
    <script>
        function toggleAnswer(id) {
            var el = document.getElementById('answer-' + id);
            el.style.display = el.style.display === 'none' ? 'block' : 'none';
        }
    </script>
</head>
<body>
    <h1>Flashcards</h1>
    <?php foreach ($cards as $card): ?>
        <div class="flashcard">
            <div><strong>Q:</strong> <?= htmlspecialchars($card['question']) ?></div>
            <button class="btn" onclick="toggleAnswer(<?= $card['id'] ?>)">Show Answer</button>
            <div class="answer" id="answer-<?= $card['id'] ?>"><strong>A:</strong> <?= htmlspecialchars($card['answer']) ?></div>
        </div>
    <?php endforeach; ?>

    <div class="nav">
        <?php if ($page > 1): ?>
            <a href="?page=<?= $page - 1 ?>">&laquo; Prev</a>
        <?php endif; ?>
        Page <?= $page ?> of <?= $pages ?>
        <?php if ($page < $pages): ?>
            <a href="?page=<?= $page + 1 ?>">Next &raquo;</a>
        <?php endif; ?>
    </div>
</body>
</html>
