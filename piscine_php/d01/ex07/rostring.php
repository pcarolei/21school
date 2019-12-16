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
$str = $argv[1];
if (!$str[0])
	exit;
$arr = ft_split_no_sort($str);
array_push($arr, $arr[0]);
unset($arr[0]);
$res = implode(" ", $arr);
print("$res\n");
?>
