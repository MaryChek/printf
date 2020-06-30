#!/usr/bin/php
<?php
function cmp($s1, $s2) {
    $line = "abcdefghijklmnopqrstuvwxyz0123456789!\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~";
    if ($s1 == $s2)
        return 0;
    else {
        if (($n1 = strlen($s1)) < ($n2 = strlen($s2)))
            $n = $n1;
        else
            $n = $n2;
        for ($i = 0; $i < $n; $i++) {
            $c1 = stripos($line, $s1[$i]);
            $c2 = stripos($line, $s2[$i]);
            if ($c1 != $c2)
                return $c1 < $c2 ? -1 : 1;
        }
        if ($n1 != $n2)
            return  $n1 < $n2 ? -1 : 1;
    }
    return 0;
}

if ($argc > 1) {
    $str = array();
    for ($i = 1; $i < $argc; $i++) {
        $arr = preg_split('/\s+/', trim($argv[$i]));
        $str = array_merge($str, $arr);
    }
    usort($str, "cmp");
    for ($i = 0; $i < count($str); $i++){
        print("$str[$i]\n");
    }
}
