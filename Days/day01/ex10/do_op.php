#!/usr/bin/php
<?php
if ($argc == 4) {
    for ($i = 1; $i < $argc; $i++) {
        $argv[$i] = trim($argv[$i]);
    }
    if ($argv[2] == '+') {
        $rez = ($argv[1] + $argv[3]);
    }
    else if ($argv[2] == '-') {
        $rez = ($argv[1] - $argv[3]);
    }
    else if ($argv[2] == '*') {
        $rez = ($argv[1] * $argv[3]);
    }
    else if ($argv[2] == '/') {
        $rez = ($argv[1] / $argv[3]);
    }
    else if ($argv[2] == '%') {
        $rez = ($argv[1] % $argv[3]);
    }
    print("$rez\n");
}
else
    print("Incorrect Parameters\n");