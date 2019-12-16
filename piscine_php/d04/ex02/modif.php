<?PHP
function oldpw_check($login, $oldpw)
{
	$db = unserialize(file_get_contents("../private/passwd"));
	$user = $db[$login];
	if ($user["passwd"] != hash("whirlpool", $oldpw))
			return (false);
	return (true);
}
function check_login_passwd($login, $oldpw, $newpw)
{
	if ($login == NULL || !$login || (empty($login) === true) ||
		$oldpw == NULL || !$oldpw || (empty($oldpw) === true) ||
		$newpw == NULL || !$newpw || (empty($newpw) === true) ||
		(oldpw_check($login, $oldpw) === false) ||
		$_POST["submit"] !== "OK")
		return (false);
	return (true);
}
function quit()
{
	echo "ERROR\n";
	exit();
}
if (file_exists("../private") === false)
	quit();
$login = $_POST['login'];
$oldpw = $_POST['oldpw'];
$newpw = $_POST['newpw'];
if (check_login_passwd($login, $oldpw, $newpw) === false)
	quit();
$db = unserialize(file_get_contents("../private/passwd"));
$newpw = hash("whirlpool", $newpw);
$db[$login] = array("login" => "$login", "passwd" => "$newpw");
file_put_contents("../private/passwd", serialize($db));
echo "OK\n";
?>
