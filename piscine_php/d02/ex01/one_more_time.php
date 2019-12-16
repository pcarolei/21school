#!/usr/bin/php
<?PHP
//date_default_timezone_set("Europe/Moscow");
if ($argc == 1)
	exit;
$arr = array_slice($argv, 1);
$str = implode(" ", $arr);
$arr = explode(" ", $str);
if (count($arr) != 5)
{
	echo "Wrong Format\n";
	exit;
}
$dom = (int)$arr[1];
if ($dom < 1 || $dom > 32)
{
	echo "Wrong Format\n";
	exit;
}
$y = (int)$arr[3];
if ($y < 1000 || $y > 9999)
{
	echo "Wrong Format\n";
	exit;
}
$hms = explode(":", $arr[4]);
if (count($hms) != 3)
{
	echo "Wrong Format\n";
	exit;
}
setlocale(LC_TIME, "fr_FR");
$format = "%A %e %B %Y %H:%M:%S";
$arr = strptime($str, $format);
$time = mktime($arr["tm_hour"] - 1,
               $arr["tm_min"],
			   $arr["tm_sec"],
			   $arr["tm_mon"] + 1,
			   $arr["tm_mday"],
			   $arr["tm_year"] + 1900);

print("$time\n");
?>
