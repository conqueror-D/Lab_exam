<?php

    function addIndi($number){
        $sum = 0;

        $str = (string) $number;

        for($i = 0; $i<strlen($str); $i++){
            $sum+= (int) $str[$i];
        }
        return $sum;
    }

    function checkPali($string){
        $arr = str_split($string);
        $revArr = array_reverse($arr);
        $revStr = implode('', $revArr);

        if($revStr === $string)return true;
        return false;
    }

    $number = 34958;
    $sum = addIndi($number);

    $string = 'banana';
    $isPali = checkPali($string);

    echo "Sum of all the digits of ". $number . " is ". $sum . "<br>";

    if($isPali){
        echo $string . " is a plainrome";
    }else{
        echo $string ." is not a plaindrome";
    }
?>