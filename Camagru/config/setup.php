<?PHP
include "database.php";
$pdo = new PDO($dsn, $db_user, $db_pass, $options);
$pdo->exec("CREATE DATABASE IF NOT EXISTS $db CHARACTER SET utf8 COLLATE utf8_general_ci");
$pdo->exec("USE $db");

$users_tab =
"CREATE TABLE IF NOT EXISTS users(
	id INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	login VARCHAR(30) NOT NULL,
	password VARCHAR(4096) NOT NULL,
	email VARCHAR(255) NOT NULL,
	notify BOOLEAN NOT NULL DEFAULT TRUE
)";
$pdo->exec($users_tab);

$images_tab =
"CREATE TABLE IF NOT EXISTS images(
	id INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	login VARCHAR(30) NOT NULL,
	filename VARCHAR(4096) NOT NULL,
	date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
)";
$pdo->exec($images_tab);

$comments_tab =
"CREATE TABLE IF NOT EXISTS comments(
	id INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	comment VARCHAR(4096) NOT NULL,
	filename VARCHAR(4096) NOT NULL,
	author VARCHAR(4096) NOT NULL,
	receiver VARCHAR(4096) NOT NULL
)";
$pdo->exec($comments_tab);
