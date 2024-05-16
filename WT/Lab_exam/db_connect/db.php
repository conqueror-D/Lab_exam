<?php
    $severname = 'localhost';
    $username = 'root';
    $password = '';
    $dbname = 'wt_lab';

    $conn = mysqli_connect($severname, $username, $password, $dbname);

    //Create operation

    // $sql = 'CREATE TABLE users (
    //     username varchar(255) not null,
    //     age int not null,
    //     password varchar(255) not null
    // )';

    if($conn){
        echo "Connected successfully!";
    }else{
        echo "Cant connect";
        die("Connection failed: " . mysqli_connect_error());
    }
    echo "<br>";

    // try{
    //     if(mysqli_query($conn, $sql)){
    //         echo "Created a table";
    //     }else{
    //         echo "Cannot create a table";
    //     }
    // }catch(Exception $err){
    //     echo $err;
    // }


    //Inserting into the table

    // $name = 'juned';
    // $pass = 'juned@123';
    // $age = 19;
    // $stmt = $conn->prepare('INSERT INTO users VALUES(?, ?, ?)');
    // $stmt->bind_param("sis", $name, $age, $pass);

    // echo "<br>";
    // if($stmt->execute()){
    //     echo "values inserted successfully";
    // }else{
    //     echo "cant insert";
    // }

    //Reading.......
    // $sql = 'select * from users';

    // $res = mysqli_query($conn, $sql);

    // if($res){
    //     if(mysqli_num_rows($res) >0){
    //         while($row = mysqli_fetch_assoc($res)){
    //             echo 'Name '. $row['username'] . '<br>  Age '. $row['age'];
    //         }
    //     }else{
    //         echo "Not enough rows";
    //     }
    // }else{
    //     echo "There is some problem";
    // }

    //Updating.......

    // $username = 'juned';
    // $newAge = 20;

    // $stmt = $conn->prepare('UPDATE users SET age = ? where username = ?');
    // $stmt->bind_param('is', $newAge, $username);

    // if($stmt->execute()){
    //     echo "Updated successfully";
    // }else{
    //     echo 'Cannot update';
    // }

    //deleting........
    // $username = 'juned';
    // $stmt = $conn->prepare('DELETE FROM users WHERE username = ?');
    // $stmt->bind_param('s', $username);

    // if($stmt->execute()){
    //     echo "Delete succesfully";
    // }else{
    //     echo "Cannot delete";
    // }

    //Dropping the table 

    $sql = 'DROP TABLE users';
    if(mysqli_query($conn, $sql)){
        echo "Table dropped successfully";
    }else{
        echo "Cannot drop!";
    }
?>