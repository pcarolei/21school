<?PHP
foreach ($_GET as $var)
{
	$key = array_search($var, $_GET);
	echo "$key: $var\n";
}
?>
