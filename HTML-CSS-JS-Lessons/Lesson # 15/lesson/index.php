<html>
<head>
  
</head>
  
<body>

  <!-- 
  Server-Side Programming:

  - Used to retrieve, modify or generate data in response to user requests and sends the results back to the user's browser.
  - Examples of uses:
      - Processing form submissions.
      - Generating content based on user input.
      - Handling file uploads.
      - Managing user sessions and authentication.

  PHP:

  - Stands for Hypertext Preprocessor
  - Server-Side language
  -->

  <?php

  // echo outputs data to the browser
  echo "<p>Hello</p>";

  // variables can be made with a $ followed by its name
  $name = "James";
  $age = 21;

  echo "<p>" . $name . " is " . $age . "</p>";

  // if statements are the same
  if ($age >= 18) {
    echo "<p>Adult</p>";
  } else {
    echo "<p>Child</p>";
  }

  // functions are the same
  function add ($x, $y) {
    return $x + $y;
  }

  echo "<p>" . add (2, 3) . "</p>";
  ?>

</body>
</html>
