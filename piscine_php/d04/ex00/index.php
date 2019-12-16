<?PHP
session_start();
$login = $_GET['login'];
$passwd = $_GET['passwd'];
if ($login && $login != NULL && (empty($login) == false) &&
	$passwd && $passwd != NULL && (empty($passwd) == false) &&
	($_GET['submit'] === 'OK'))
{
	$_SESSION['login'] = $_GET['login'];
	$_SESSION['passwd'] = $_GET['passwd'];
}
$login = $_SESSION['login'];
$passwd = $_SESSION['passwd'];
echo "<html><body\n";
echo "<form id='form' method='get'>\n";
echo "	Username: <input form='form' type='text' name='login' value='$login' />\n";
echo "	<br />\n";
echo "	Password <input form='form' type='password' name='passwd' value='$passwd' />\n";
echo "	<button type='submit' value='OK' />\n";
echo "</form>\n";
echo "</body></html>";
?>
