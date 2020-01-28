<?PHP
/* $db_host = 'localhost'; */
$db_host = '127.0.0.1';
$db = 'camagru_db';
$db_user = 'camagru';
$db_pass = 'camagru';
$db_charset = 'utf8';
$dsn = "mysql:host=$db_host;charset=$db_charset";
$options = [
	PDO::ATTR_ERRMODE				=>	PDO::ERRMODE_EXCEPTION,
	PDO::ATTR_EMULATE_PREPARES		=>	false,
	PDO::ATTR_DEFAULT_FETCH_MODE	=>	PDO::FETCH_ASSOC,
];
?>
