#!/usr/bin/php
<?php
$str = fopen("php://stdin", "r");
echo "Enter a number: ";
$line = trim(fgets($str));
while ($str && !feof($str))
{
    if (is_numeric($line))
    {
        if (($line % 2) == 0)
            echo "The number $line is even\n";
        else
            echo "The number $line is odd\n";
    }
    else
        echo "'$line' is not a number\n";
    echo "Enter a number: ";
    $line = trim(fgets($str));
}
echo "\n";
