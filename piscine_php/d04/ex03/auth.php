<?PHP
function auth($login, $passwd)
{
	$db = unserialize(file_get_contents("../private/passwd"));
	$user = $db["$login"];
	if (($user["login"] === $login) && ($user["passwd"] == hash("whirlpool", $passwd)))
		return (true);
	return (false);
}
