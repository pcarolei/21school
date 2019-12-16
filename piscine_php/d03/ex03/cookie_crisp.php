<?PHP
$action = $_GET["action"];
$name = $_GET["name"];
if ($action === "set")
{
	$value = $_GET["value"];
	setcookie($name, $value, time() + 2*24*60*60);
}
if ($action === "get")
{
	$value = $_COOKIE[$name];
	if ($value)
		echo $value."\n";
}
if ($action === "del")
	setcookie($name, "", time() - 3600);
?>
