#!/usr/bin/php
<?php
if ($argc > 1){
    $url = $argv[1];
    preg_match('/^(http[s]?:\/\/)?([^\/]+)/i', $url, $s);
    $host = $s[2];
    if ($s[1] == null)
        $url = "https://".$s[2];
    if (!($content = file_get_contents($url)))
        exit();
    preg_match('/<img *? src="(http[s]?:\/\/)?(.+?)"/',$content,$matches);
    if ($matches[1] == null)
        $content = $matches.$content;
    else
        $content = $matches[1].$matches[2];
    if ($content != null){
        $filename = substr(strrchr($content, "/"), 1);
        if (!is_dir($host)) {
            mkdir($host);
        }
        file_put_contents($host."/".$filename, $content);
    }
}