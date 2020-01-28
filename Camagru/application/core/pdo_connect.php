<?PHP
require_once "config/database.php";
$pdo = new PDO($dsn, $db_user, $db_pass, $options);
$pdo->exec("USE $db");
function get_pdo()
{
	return $pdo;
}
/* function pdo_connect($dsn = $dsn) */
/* { */
/* 	echo "db = $db<br>"; */
/* 	return (new PDO($dsn, $db_user, $db_pass, $options)); */
/* } */
?>
