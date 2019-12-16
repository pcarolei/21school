#!/usr/bin/php
<?PHP
if ($argc != 2)
	exit;
$fd = fopen($argv[1], 'r');
if ($fd === false)
	exit;
while ($line = fgets($fd))
{
	$text_to_echo = preg_replace_callback(
		"/<a[\s]+([^>]+)>((?:.(?!\<\/a\>))*.)<\/a>/",
		function($matches)
		{
			preg_match('/.+?(?=<)/', $matches[2], $in_a);
			if (count($in_a) != 0)
				$nstr = str_replace($in_a[0], strtoupper($in_a[0]), $matches[2]);
			else
				$nstr = str_replace($matches[2], strtoupper($matches[2]), $matches[0]);
			$a = explode("title=", $nstr);
			preg_match('/".*?"/', $a[0].$a[1], $out0);
			$nstr = preg_replace('/".*?"/', strtoupper($out0[0]), $nstr);
			return ($nstr);
		},
	$line);
	print("$text_to_echo");
}
?>
