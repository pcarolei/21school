#!/usr/bin/php
<?PHP
function is_al($a)
{
	$o = ord($a);
	if (($o >= 65 && $o <= 90) || ($o >= 97 && $o <= 122))
		return (true);
	return (false);
}
function cmp($a, $b)
{
	for ($i = 0; $i < min(strlen($a), strlen($b)); $i++)
	{
		$sa = 0;
		$sb = 0;
		if (is_numeric($a[$i]))
			$sa = 2;
		else if (is_al($a[$i]))
			$sa = 3;
		else
			$sa = 1;
		if (is_numeric($b[$i]))
			$sb = 2;
		else if (is_al($b[$i]))
			$sb = 3;
		else
			$sb = 1;
		if ($sa > $sb)
			return (-1);
		if ($sa < $sb)
			return (1);
		if ($sa == $sb)
		{
			if ($sa == 2 || $sa == 1)
			{
				if ($a[$i] == $b[$i])
					continue;
				else
					return (ord($a[$i]) - ord($b[$i]));
			}
			else
			{
				if ($a[$i] == $b[$i] || abs(ord($a[$i]) - ord($b[$i])) == 32)
					continue;
				else
				{
					$oa = ord($a[$i]);
					$ob = ord($b[$i]);
					if ($oa >= 97)
						$oa -= 32;
					if ($ob >= 97)
						$ob -= 32;
					return ($oa - $ob);
				}
			}
		}
	}
	return (1);
}

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
	return ($arr);
}
$res = [];
for ($i = 1; $i < $argc; $i++)
{
	$cur_arr = ft_split(explode(" ", $argv[$i]));
	for ($j = 0; $j < count($cur_arr); $j++)
		array_push($res, $cur_arr[$j]);
}
usort($res, cmp);
for ($j = 0; $j < count($res); $j++)
	print("$res[$j]\n");
?>
