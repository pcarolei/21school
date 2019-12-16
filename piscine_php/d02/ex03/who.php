#!/usr/bin/php
<?PHP
date_default_timezone_set('Europe/Moscow');
$str = shell_exec("w -h | sed 's/|/ /' | awk '{print $1, $2, $3, $4}'");
$str = preg_replace("/[[:blank:]]+/", " ", $str);
$str = preg_replace("/s0/", "ttys0", $str);
$date = date('M-d');
$date = preg_replace("/-/", " ", $date);
$str = preg_replace("/-/", " $date", $str);
print($str);
?>
