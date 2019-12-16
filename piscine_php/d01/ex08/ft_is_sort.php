<?PHP
function ft_is_sort($arr)
{
	$s_arr = $arr;
	asort($s_arr);
	if ($arr === $s_arr)
		return (true);
	return (false);
}
?>
