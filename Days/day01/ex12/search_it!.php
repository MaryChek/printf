#!/usr/bin/php
<?php
if ($argc > 2) {
    for ($i = 2; $i < $argc; $i++) {
        $arr = explode(":", $argv[$i]);
        if (count($arr) == 2 && $arr[0] === $argv[1]) {
            $rez = $arr[1];
            $find = 1;
        }
    }
    if ($find == 1)
        print("$rez\n");
}