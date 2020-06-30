#!/usr/bin/php
<?php
function ft_split($string)
{
    $str = preg_split('/\s+/', trim($string));
    sort($str);
    print_r($str);
}
