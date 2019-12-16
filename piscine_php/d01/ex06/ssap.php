#!/usr/bin/php
<?PHP
function ft_split($arr)
{
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
$arr = ft_split($argv);
$res = [];
for ($i = 1; $i < $argc; $i++)
{
	$cur_arr = ft_split(explode(" ", $argv[$i]));
	for ($j = 0; $j < count($cur_arr); $j++)
		array_push($res, $cur_arr[$j]);
}
asort($res);
$res = array_merge($res);
for ($j = 0; $j < count($res); $j++)
	print("$res[$j]\n");
?>
