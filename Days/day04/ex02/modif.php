<?php
if ($_POST['submit'] == "OK") {
    if ($_POST['oldpw'] != "" && $_POST['newpw'] != "" && $_POST['login'] != "") {
        $content = file_get_contents("../private/passwd");
        $users = unserialize($content);
        $old_pass = hash("whirlpool", $_POST['oldpw']);
        foreach ($users as &$usr_inf) {
            if ($usr_inf['login'] == $_POST['login']) {
                if ($usr_inf['passwd'] != $old_pass) {
                    echo "ERROR\n";
                }
                else {
                    $usr_inf['passwd'] = hash("whirlpool", $_POST['newpw']);
                    $content = serialize($users);
                    file_put_contents("../private/passwd", $content);
                    echo "OK\n";
                }
                exit;
            }
        }
    }
    echo "ERROR\n";
    exit;
}