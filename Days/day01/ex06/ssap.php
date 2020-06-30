#!/usr/bin/php
<?php
if ($argc > 1) {
    $str = array();
    for ($i = 1; $i < $argc; $i++) {
        $arr = preg_split('/\s+/', trim($argv[$i]));
        $str = array_merge($str, $arr);
    }
    sort($str);
    for ($i = 0; $i < count($str); $i++){
        print("$str[$i]\n");
    }
}
