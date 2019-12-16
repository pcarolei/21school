<?PHP
function delete_user_by_login($login)
{
	$fd = fopen("users.csv", "r");
	$new_csv = array();
	while (($user = fgetcsv($fd, 1000, ";")) !== false)
	{
		$used_login = $user[0];
		if ($used_login !== $login)
			array_push($new_csv, $user);
	}
	fclose($fd);
	$fd = fopen("users.csv", "w");
	foreach ($new_csv as $fields)
		fputcsv($fd, $fields, ";");
	fclose($fd);
}
session_start();
delete_user_by_login($_GET["login"]);
echo "<script>window.location = '/admin_panel.php' </script>";
?>
