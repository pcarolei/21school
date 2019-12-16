<?PHP
function user_exists($login, $db_path)
{
	$db = unserialize(file_get_contents($db_path));
	foreach ($db as $user)
	{
		if ($user["login"] === $login)
			return (true);
	}
	return (false);
}
function check_login_passwd($login, $passwd)
{
	if ($login == NULL || !$login || (empty($login) === true) ||
		$passwd == NULL || !$passwd || (empty($passwd) === true) ||
		$_POST["submit"] !== "OK")
		return (false);
	return (true);
}
function quit()
{
	echo "ERROR\n";
	exit();
}
$login = $_POST['login'];
$passwd = $_POST['passwd'];
if (check_login_passwd($login, $passwd) === false)
	quit();
$passwd = hash("whirlpool", $_POST['passwd']);
$db_existed = true;
if (file_exists("../private") === false)
{
	mkdir("../private");
	$db_existed = false;
}
if ($db_existed === true && user_exists($login, "../private/passwd"))
	quit();
$olddb = array();
if ($db_existed === true)
{
	$olddb = unserialize(file_get_contents("../private/passwd"));
	$olddb["$login"] = array("login" => "$login", "passwd" => "$passwd");
}
else
	$olddb["$login"] = array("login" => "$login", "passwd" => "$passwd");
file_put_contents("../private/passwd", serialize($olddb));
echo "OK\n";
?>
