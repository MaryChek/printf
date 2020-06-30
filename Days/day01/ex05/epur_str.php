#!/usr/bin/php
<?php
if ($argc == 2) {
    $str = preg_replace('/\s+/', ' ', trim($argv[1]));
    print("$str\n");
}
