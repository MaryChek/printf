#!/usr/bin/php
<?php
if ($argc > 1) {
    $str = preg_split('/\s+/', trim($argv[1]));
    $n = count($str);
    for ($i = 1; $i < $n; $i++){
        print("$str[$i]");
        print(" ");
    }
    print("$str[0]\n");
}
