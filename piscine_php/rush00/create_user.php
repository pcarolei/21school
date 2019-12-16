<?PHP 
session_start();
function write_to_csv($user_data, $csv_filename)
{
	$fd = fopen("$csv_filename", "a");
	fputcsv($fd, $user_data, ";");
	fclose($fd);
}
function login_unused_check($login)
{
	$fd = fopen("users.csv", "r");
	$user = fgetcsv($fd, 1000, ";");
	while (($user = fgetcsv($fd, 1000, ";")) !== false)
	{
		$used_login = $user[0];
		if ($used_login === $login)
			return (false);
	}
	fclose($fd);
	return (true);
}
function login_nodelimiter_check($login)
{
	if (strstr($login, ";") !== false)
		return (false);
	return (true);
}

function create_user_entry($login, $passwd, $acc_type)
{
//	TODO: input validation
	if (login_unused_check($login) && login_nodelimiter_check($login))
	{
		$passwd = hash("whirlpool", $passwd);
		return (array("$login", "$passwd", "$acc_type"));
	}
	return (NULL);
}
$login = $_POST["login"];
$passwd = $_POST["passwd"];
$is_admin = $_POST["admin"];
$user_entry = create_user_entry($login, $passwd, "user");
if ($user_entry !== NULL)
{
	
	write_to_csv($user_entry, "users.csv");
	if ($is_admin != "admin")
	{
		$_SESSION["logged_in_user"] = $login;
		echo "<script>window.location = '/' </script>";
	}
	else
		echo "<script>window.location = '/admin_panel.php' </script>";
}
else
{
	if ($is_admin == "admin")
		echo "<script>window.location = '/admin_panel.php' </script>";
	else
		echo "<script>window.location = '/' </script>";
}
?>
