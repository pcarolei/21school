<?PHP
include "auth.php";
function check_login_passwd($login, $passwd)
{
	if ($login == NULL || !$login || (empty($login) === true) ||
		$passwd == NULL || !$passwd || (empty($passwd) === true))
		return (false);
	return (true);
}
session_start();
$login = $_GET["login"];
$passwd = $_GET["passwd"];
if (check_login_passwd($login, $passwd) === false || auth($login, $passwd) === false)
{
	$_SESSION["loggued_on_user"] = "";
	echo "ERROR\n";
}
else
{
	$_SESSION["loggued_on_user"] = $login;
	echo "OK\n";
}
?>
