<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>This or That?</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      text-align: center;
      padding: 50px;
    }

    button {
      padding: 15px 30px;
      margin: 20px;
      font-size: 18px;
      cursor: pointer;
    }

    h1 {
      font-size: 36px;
      margin-bottom: 20px;
    }

    .input-container {
      display: flex;
      flex-direction: column;
      align-items: center;
      margin-bottom: 30px;
    }

    .input-container label {
      font-size: 20px;
      margin-bottom: 10px;
    }

    .button-group {
      display: flex;
      justify-content: center;
    }

    .result {
      font-size: 18px;
      margin-top: 10px;
    }
  </style>
</head>

<body>
  <h1>This or That?</h1>

  <?php
    // File to store the votes
    $file = 'votes.txt';

    // Initialize the vote counts if the file does not exist
    if (!file_exists($file)) {
      $votes = [
        'question-1-option-1' => 0,
        'question-1-option-2' => 0,
        'question-2-option-1' => 0,
        'question-2-option-2' => 0,
        'question-3-option-1' => 0,
        'question-3-option-2' => 0,
        'question-4-option-1' => 0,
        'question-4-option-2' => 0,
        'question-5-option-1' => 0,
        'question-5-option-2' => 0,
        'question-6-option-1' => 0,
        'question-6-option-2' => 0,
        'question-7-option-1' => 0,
        'question-7-option-2' => 0
      ];
      file_put_contents($file, json_encode($votes));
    } else {
      // Read the votes from the file
      $votes = json_decode(file_get_contents($file), true);
    }

    // Check if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
      // For each question, check if a button was clicked and update the vote count
      if (isset($_POST['question-1'])) {
        $option = $_POST['question-1'];
        $votes["question-1-$option"] += 1;
      }

      if (isset($_POST['question-2'])) {
        $option = $_POST['question-2'];
        $votes["question-2-$option"] += 1;
      }

      if (isset($_POST['question-3'])) {
        $option = $_POST['question-3'];
        $votes["question-3-$option"] += 1;
      }

      if (isset($_POST['question-4'])) {
        $option = $_POST['question-4'];
        $votes["question-4-$option"] += 1;
      }

      if (isset($_POST['question-5'])) {
        $option = $_POST['question-5'];
        $votes["question-5-$option"] += 1;
      }

      if (isset($_POST['question-6'])) {
        $option = $_POST['question-6'];
        $votes["question-6-$option"] += 1;
      }

      if (isset($_POST['question-7'])) {
        $option = $_POST['question-7'];
        $votes["question-7-$option"] += 1;
      }

      // Save the updated votes to the file
      file_put_contents($file, json_encode($votes));
    }
  ?>

  <form method="post">
    <div class="input-container">
      <label>1. How do you pronounce gif?</label>
      <div class="button-group">
        <button type="submit" name="question-1" value="option-1">Gif</button>
        <button type="submit" name="question-1" value="option-2">Jif</button>
      </div>
      <p class="result">
        Gif: <?php echo $votes['question-1-option-1']; ?> votes | 
        Jif: <?php echo $votes['question-1-option-2']; ?> votes
      </p>
    </div>

    <div class="input-container">
      <label>2. What came first, the chicken or the egg?</label>
      <div class="button-group">
        <button type="submit" name="question-2" value="option-1">Chicken</button>
        <button type="submit" name="question-2" value="option-2">Egg</button>
      </div>
      <p class="result">
        Chicken: <?php echo $votes['question-2-option-1']; ?> votes | 
        Egg: <?php echo $votes['question-2-option-2']; ?> votes
      </p>
    </div>

    <div class="input-container">
      <label>3. Is pineapple on pizza good?</label>
      <div class="button-group">
        <button type="submit" name="question-3" value="option-1">Yes</button>
        <button type="submit" name="question-3" value="option-2">No</button>
      </div>
      <p class="result">
        Yes: <?php echo $votes['question-3-option-1']; ?> votes | 
        No: <?php echo $votes['question-3-option-2']; ?> votes
      </p>
    </div>

    <div class="input-container">
      <label>4. Are hotdogs a sandwich?</label>
      <div class="button-group">
        <button type="submit" name="question-4" value="option-1">Yes</button>
        <button type="submit" name="question-4" value="option-2">No</button>
      </div>
      <p class="result">
        Yes: <?php echo $votes['question-4-option-1']; ?> votes | 
        No: <?php echo $votes['question-4-option-2']; ?> votes
      </p>
    </div>

    <div class="input-container">
      <label>5. Xbox or Playstation?</label>
      <div class="button-group">
        <button type="submit" name="question-5" value="option-1">Xbox</button>
        <button type="submit" name="question-5" value="option-2">Playstation</button>
      </div>
      <p class="result">
        Xbox: <?php echo $votes['question-5-option-1']; ?> votes | 
        Playstation: <?php echo $votes['question-5-option-2']; ?> votes
      </p>
    </div>

    <div class="input-container">
      <label>6. iPhone or Android?</label>
      <div class="button-group">
        <button type="submit" name="question-6" value="option-1">iPhone</button>
        <button type="submit" name="question-6" value="option-2">Android</button>
      </div>
      <p class="result">
        iPhone: <?php echo $votes['question-6-option-1']; ?> votes | 
        Android: <?php echo $votes['question-6-option-2']; ?> votes
      </p>
    </div>

    <div class="input-container">
      <label>7. Does a straw have one hole or two?</label>
      <div class="button-group">
        <button type="submit" name="question-7" value="option-1">One</button>
        <button type="submit" name="question-7" value="option-2">Two</button>
      </div>
      <p class="result">
        One: <?php echo $votes['question-7-option-1']; ?> votes | 
        Two: <?php echo $votes['question-7-option-2']; ?> votes
      </p>
    </div>
  </form>

</body>
</html>
