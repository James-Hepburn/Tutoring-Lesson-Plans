<?php
$upload_dir = 'uploads/';
$metadata_file = 'metadata.json';

if (!is_dir ($upload_dir)) {
  mkdir ($upload_dir);
}

if (isset ($_POST ['submit'])) {
  $uploader = $_POST ['uploader'];
  $file = $_FILES ['image'];

  if ($file ['error'] === 0 && getimagesize ($file ['tmp_name'])) {
    $filename = uniqid () . '-' . basename ($file ['name']);
    $target_file = $upload_dir . $filename;

    if (move_uploaded_file ($file ['tmp_name'], $target_file)) {
      $metadata = [
        'filename' => $filename,
        'uploader' => $uploader,
        'timestamp' => date ('Y-m-d H:i:s')
      ];

      $metadata_array = file_exists ($metadata_file) ? json_decode (file_get_contents ($metadata_file), true) : [];
      $metadata_array [] = $metadata;

      file_put_contents ($metadata_file, json_encode ($metadata_array, JSON_PRETTY_PRINT));

      echo "Image uploaded successfully!";
    } else {
      echo "Failed to upload image.";
    }
  } else {
    echo "Invalid image file.";
  }
}

$gallery_images = file_exists ($metadata_file) ? json_decode (file_get_contents ($metadata_file), true) : [];
?>

<html>
<head>
  <title>Public Image Gallery</title>

  <style>
    body {
      font-family: Arial, sans-serif;
      display: flex;
      flex-direction: column;
      align-items: center;
      justify-content: center;
      min-height: 100vh;
      margin: 0;
      padding: 20px;
      background-color: #f0f0f0;
    }

    h1 {
      text-align: center;
      color: #333;
    }

    form {
      display: flex;
      flex-direction: column;
      align-items: center;
      background-color: white;
      padding: 20px;
      border-radius: 10px;
      box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.1);
      margin-bottom: 30px;
      width: 100%;
      max-width: 500px;
    }

    label {
      margin-bottom: 5px;
      font-weight: bold;
    }

    input[type="text"],
    input[type="file"] {
      margin-bottom: 15px;
      padding: 10px;
      width: 100%;
      border: 1px solid #ccc;
      border-radius: 5px;
    }

    button {
      padding: 10px 20px;
      background-color: #4CAF50;
      color: white;
      border: none;
      border-radius: 5px;
      cursor: pointer;
    }

    button:hover {
      background-color: #45a049;
    }

    .gallery {
      width: 100%;
      max-width: 800px;
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(150px, 1fr));
      gap: 20px;
    }

    .gallery-item {
      text-align: center;
      background-color: white;
      padding: 10px;
      border-radius: 10px;
      box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.1);
    }

    .gallery-item img {
      max-width: 100%;
      border-radius: 10px;
    }

    p {
      margin: 5px 0;
      color: #555;
    }
  </style>
</head>
  
<body>
  <h1>Public Image Gallery</h1>

  <form action = "index.php" method = "POST" enctype = "multipart/form-data">
    <label>Your Name:</label>
    <input type = "text" name = "uploader" required>
    <label>Upload an Image:</label>
    <input type = "file" name = "image" accept = "image/*" required>
    <button type = "submit" name = "submit">Upload</button>
  </form>

  <h2>Uploaded Images</h2>
  
  <div class = "gallery">
    <?php if (empty ($gallery_images)): ?>
      <p>No images uploaded yet.</p>
    <?php else: ?>
      <?php foreach ($gallery_images as $image): ?>
        <div class = "gallery-item">
          <img src = "<?php echo $upload_dir . $image ['filename']; ?>">
          <p>Uploaded by: <?php echo $image ['uploader']; ?></p>
          <p>Uploaded on: <?php echo $image ['timestamp']; ?></p>
        </div>
      <?php endforeach; ?>
    <?php endif; ?>
  </div>
</body>
</html>
