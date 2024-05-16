<?php

    $states = array('Juned', 'Kansas' , 'nikas', 'kisses', 'kolomuani', 'kylian', 'rohan');

    $ans = array();

    foreach ($states as $state) {
        $state = strtolower($state);

        if(substr($state, 0, 1)=== 'k' && substr($state, -1) === 's'){
            $ans = $state;
        }
    }

    if($ans){
        echo "Found your words!". ans;
    }else{
        echo "Couldnt find the words";
    }
?>
