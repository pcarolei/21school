#!/usr/bin/php
<?PHP
function ft_split_no_sort($str)
{
	$arr = explode(" ", $str);
	$arr_len = count($arr);
	$i = 0;
	while ($i < $arr_len)
	{
		if (ord($arr[$i]) == 0)
			unset($arr[$i]);
		$i++;
	}
	$arr = array_merge($arr);
	return ($arr);
}
if ($argc == 1)
	exit();
$str = implode(" ", ft_split_no_sort($argv[1]));
print("$str\n");
?>
