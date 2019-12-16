<?PHP
session_start();
function login_check($login)
{
	$fd = fopen("users.csv", "r");
	$user = fgetcsv($fd, 1000, ";");
	while (($user = fgetcsv($fd, 1000, ";")) !== false)
	{
		$used_login = $user[0];
		if ($used_login === $login)
			return (true);
	}
	fclose($fd);
	return (false);
}
function passwd_check($passwd)
{
	$fd = fopen("users.csv", "r");
	$user = fgetcsv($fd, 1000, ";");
	while (($user = fgetcsv($fd, 1000, ";")) !== false)
	{
		$used_passwd = $user[1];
		if ($used_passwd === hash("whirlpool", $passwd));
			return (true);
	}
	fclose($fd);
	return (false);
}
function get_user_access_rights($login)
{
	$fd = fopen("users.csv", "r");
	$user = fgetcsv($fd, 1000, ";");
	while (($user = fgetcsv($fd, 1000, ";")) !== false)
	{
		$used_login = $user[0];
		if ($used_login === $login)
			return ($user[2]);
	}
	fclose($fd);
	return (NULL);
}
$login = $_POST["login"];
$passwd = $_POST["passwd"];
if ((login_check($login) === true) && (passwd_check($passwd) === true))
{
	$_SESSION["logged_in_user"] = $login;
	$_SESSION["access_rights"] = get_user_access_rights($login);
	echo "<script>window.location='/' </script>";
}
else
{
	echo "<script>window.location='/login.php' </script>";
}
?>
