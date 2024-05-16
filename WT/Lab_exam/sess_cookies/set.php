<?php
    session_start();
    $attName = 'Hobby';
    $hobby = 'Football';
    $_SESSION['username'] = 'juned';
    $_SESSION['age'] = 19;

    setcookie($attName, $hobby, time() + 3600 *24);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1>Cookie and sessions have been set</h1>
</body>
</html>