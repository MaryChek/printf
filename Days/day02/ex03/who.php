#!/usr/bin/php
<?php
date_default_timezone_set('Europe/Moscow');
$file = fopen("/var/run/utmpx", "r");
while ( $utmpx = fread( $file, 628 ) ){
    $unpack = unpack("a256a/a4b/a32c/id/ie/I2f/a256g/i16h", $utmpx);
    $array[$unpack['c']] = $unpack;
}
foreach ( $array as $value ){
    if ( $value['e'] == 7 ){
        echo trim( $value['a'] ) ."\t ";
        echo trim( $value['c'] ) ."  " ;
        echo date ('M' ,$value['f1'] )."  ";
        echo date ('j' ,$value['f1'] )." ";
        echo date ('H:i' ,$value['f1'] )."\n";
    }
}