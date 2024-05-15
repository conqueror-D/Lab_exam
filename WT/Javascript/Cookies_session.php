<?php
    $cookie_name = 'Name';
    $cookie_value = 'Juned';
    setcookie( $cookie_name, $cookie_value, time() + 3600 *24 *30);
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=\, initial-scale=1.0" />
    <title>Document</title>
  </head>
  <body>
    
    <?php
      if(isset($_COOKIE($cookie_name))){
        echo "Cookie named '". $cookie_name. "' is set!!" ;
        echo "Value: ". $_COOKIE[$cookie_name];
      }else{
        echo "No cookies set yet!";
      }
    ?>
  </body>
</html>
