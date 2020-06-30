#!/usr/bin/php
<?php
if ($argc == 2 && file_exists($argv[1])) {
    $html = $argv[1];
    $sContent = file_get_contents($html);
    $sContent = preg_replace_callback('/(<a href=.+?>.*?<\/a>)/si',
        function($matches)
        {
            $res = preg_replace_callback('/(<.+? title=")(.+?)(".?>)/',
                function ($title)
                {
                    $title[2] = strtoupper($title[2]);
                    return $title[1].$title[2].$title[3];
                }, $matches[0]);
            $res = preg_replace_callback('/>(.+?)</si',
                function ($links)
                {
                    $links[1] = strtoupper($links[1]);
                    return ">".$links[1]."<";
                }, $res);
        return $res;
    } ,$sContent);
    echo $sContent;
}