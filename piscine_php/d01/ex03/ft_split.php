#!/usr/bin/php

<?PHP
function ft_split($str)
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
	asort($arr);
	$arr = array_merge($arr);
	return ($arr);
}
?>
