<?php
    session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1>Getting the session and cookies here</h1>
    <div>
        <?php 
        echo "Username is: ". $_SESSION['username'];
        echo "<br>";
        echo "Age is: " . $_SESSION['age'] . "<br>";
        echo "Hobby is: ". $_COOKIE['Hobby'];
        ?>
    </div>
</body>
</html>