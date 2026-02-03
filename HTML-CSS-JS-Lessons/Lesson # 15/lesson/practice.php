<html>
<head>
  
</head>
  
<body>

  <!-- 
  QUESTION: Ask the user for their percentage grade and convert it into the corresponding letter grade:

  A = 80 to 100
  B = 70 to 79
  C = 60 to 69
  D = 50 to 59
  F = 0 to 49
  -->

  <!-- post is used to send data to the server -->
  <form method = "post" action = "practice.php">
    <label>Enter your grade (in %): </label>
    <input type = "number" min = "0" max = "100" name = "percentage">
    <button type = "submit">Submit</button>
  </form>
  
  <p id = "grade"></p>

  <?php
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    function getGrade () {
      $grade = intval ($_POST ["percentage"]);
      $output = "";

      if ($grade >= 80 && $grade <= 100) {
        $output = "A";
      } else if ($grade >= 70 && $grade <= 79) {
        $output = "B";
      } else if ($grade >= 60 && $grade <= 69) {
        $output = "C";
      } else if ($grade >= 50 && $grade <= 59) {
        $output = "D";
      } else {
        $output = "F";
      }

      return $output;
    }

    $letter = getGrade ();
    echo "<p>" . $letter . "</p>";
  }
  ?>

</body>
</html>
