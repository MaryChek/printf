<?php
session_start();
$login = $_GET['login'];
$passwd = $_GET['passwd'];
$_SESSION['$loggued_on_user'] = "";
include("auth.php");
if (auth($login, $passwd)) {
    echo "OK\n";
    $_SESSION['$loggued_on_user'] = $login;
}
else
    echo "ERROR\n";
