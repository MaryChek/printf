<?php
function auth($login, $passwd) {
    if (file_exists("../private/passwd")) {
        $passwd = hash("whirlpool", $passwd);
        $content = file_get_contents("../private/passwd");
        $users = unserialize($content);
        foreach ($users as $key => $usr_inf) {
            if ($usr_inf['login'] == $login && $usr_inf['passwd'] == $passwd) {
                return true;
            }
        }
    }
    return false;
}