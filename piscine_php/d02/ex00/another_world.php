#!/usr/bin/php
<?PHP
if ($argc == 1)
	exit;
$str = $argv[1];
$str = preg_replace('/\s+/', ' ', $str);
$str = trim($str);
print("$str\n");
?>
