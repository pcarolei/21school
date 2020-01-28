<?PHP
if (isset($_SESSION['login']))
{
	echo "
	<script>
		window.location='/';
	</script>";
}
?>
<h1>Login Page</h1>
<p>
	<form action="" method="POST" id="login_form">
		<input type="text" placeholder="login" name="login" />
		<input type="password" placeholder="password" name="password" />
	</form>
	<button type="submit" form="login_form">Submit</button>
	<br />
	<a href='/register'>Registration</a>
</p>
<?PHP
if ($data['login_status'] === "logged_in")
{
	echo "
	<script>
		window.location='/';
	</script>";
}
else if ($data['login_status'] === "wrong_credentials")
	echo '<p style="color:red">Wrong login/password</p>';
else if ($_SESSION['registration_complete'] === true)
{
	echo '<p style="color:green">Registration complete!</p>';
	echo '<p style="color:green">Now you can log in</p>';
	$_SESSION['registration_complete'] = NULL;
}
?>
