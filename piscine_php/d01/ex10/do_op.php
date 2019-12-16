#!/usr/bin/php
<?PHP
if ($argc !== 4)
{
	print("Incorrect Parameters\n");
	exit();
}
$n1 = (float)(trim($argv[1]));
$n2 = (float)(trim($argv[3]));
$op = trim($argv[2]);
if ($op === "+")
	$res = $n1 + $n2;
if ($op === "-")
	$res = $n1 - $n2;
if ($op === "*")
	$res = $n1 * $n2;
if ($op === "/")
	$res = $n1 / $n2;
if ($op === "%")
	$res = $n1 % $n2;
print("$res\n");
?>
