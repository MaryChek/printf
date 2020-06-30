<?php
if ($_POST['submit'] == "OK") {
    if ($_POST['passwd'] != "" || $_POST['login'] != "") {
        if (file_exists("../private/passwd")) {
            $content = file_get_contents("../private/passwd");
            $users = unserialize($content);
            foreach ($users as $key => $usr_inf) {
                if ($usr_inf['login'] == $_POST['login']) {
                    echo "ERROR\n";
                    header('Location: create.html');
                    exit;
                }
            }
        }
        else if (!file_exists("../private"))
            mkdir("../private");
        $add_usr = array(
            'login' => $_POST['login'],
            'passwd'=> hash("whirlpool", $_POST['passwd'])
        );
        $users[] = $add_usr;
        $content = serialize($users);
        file_put_contents("../private/passwd", $content);
        header('Location: index.html');
        echo "OK\n";
    }
    else {
        echo "ERROR\n";
    }
    exit;
}