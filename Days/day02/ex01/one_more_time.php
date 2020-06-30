#!/usr/bin/php
<?php
function more_1970($hms, $day, $month, $year) {
    return mktime($hms[0], $hms[1], $hms[2], $month, $day, $year);
}

function parse_hms($str) {
    $hms = explode(':', $str);
    if (count($hms) == 3) {
        if (preg_match('/^([01][0-9]|2[0-3])$/', $hms[0])
        && preg_match('/^([0-5][0-9])$/', $hms[1])
        && preg_match('/^([0-5][0-9])$/', $hms[2])) {
            return $hms;
        }
    }
    return false;
}

function parse_day_of_month($day, $month) {
    if ((preg_match('/^(0[1-9]|[1-9]|1[1-9]|2[1-9]|3[01])$/', $day) && preg_match('/(0|2|4|6|7|9|11)/', $month))
        || (preg_match('/^(0[1-9]|[1-9]|1[1-9]|2[1-9]|30)$/', $day) && preg_match('/(3|5|8|10)/', $month))
        || (($day == 28 || $day == 29) && $month == 1)) {
            return true;
    }
    return false;
}

function parse_month($month) {
    $monthFR = array("janvier", "Janvier", "février", "Février", "mars", "Mars",
        "avril", "Avril", "mai", "Mai", "juin","Juin", "juillet",  "Juillet",
        "août", "Août", "septembre", "Septembre", "octobre", "Octobre",
        "novembre", "Novembre", "décembre", "Décembre");
    for ($i = 0; $i < 24; $i++) {
        if ($month == $monthFR[$i]) {
            return ((int)($i / 2));
        }
    }
    return false;
}

function parse_week($week) {
    $dayWeekFR = array("lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche",
    "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche");
    for ($i = 0; $i < 14; $i++) {
        if ($week == $dayWeekFR[$i])
            return $i;
    }
    return false;
}

if ($argc == 2) {
    date_default_timezone_set('Europe/Paris');
    $str = explode(' ', $argv[1]);
    if (count($str) == 5 && ($week = parse_week($str[0])) !== false
        && ($month = parse_month($str[2])) !== false
            && parse_day_of_month($str[1], $month)
                && preg_match('/^([0-9][0-9][0-9][0-9])$/', $str[3])) {
                    if (($hms = parse_hms($str[4])) !== false) {
                        $rez = more_1970($hms, $str[1], $month + 1, $str[3]);
                        if ($rez < 0)
                            print("00\n");
                        else
                            print("$rez\n");
                    }
    }
    else
        print("Wrong Format\n");
}