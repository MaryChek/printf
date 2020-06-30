#!/usr/bin/php
<?php
function print_rez($arr, $c) {
    $arr = explode($c, $arr);
    if (is_numeric($arr[0]) && is_numeric($arr[1])) {
        if ($c == '+')
            $rez = ($arr[0] + $arr[1]);
        else if ($c == '-')
            $rez = ($arr[0] - $arr[1]);
        else if ($c == '*')
            $rez = ($arr[0] * $arr[1]);
        else if ($c == '/')
            $rez = ($arr[0] / $arr[1]);
        else
            $rez = ($arr[0] % $arr[1]);
        print ("$rez\n");
    }
    else
        print("Syntax Error\n");
}

if ($argc == 2) {
    $str = preg_replace('/\s+/', '', trim($argv[1]));
    if (strpos($str, "+")) {
        print_rez($str, "+");
    }
    else if (strpos($str, "-")) {
        print_rez($str, '-');
    }
    else if (strpos($str, "*")) {
        print_rez($str, '*');
    }
    else if (strpos($str, "/")) {
        print_rez($str, '/');
    }
    else if (strpos($str, "%")) {
        print_rez($str, '%');
    }
    else
        print("Syntax Error\n");
}
else
    print("Incorrect Parameters\n");