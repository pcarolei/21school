<?PHP
if ($data['login_status'] === "logged_in")
{
	echo "
	<script>
		window.location='/';
	</script>";
}
?>
<h1>Registration Page</h1>
<p>
	<form action="" method="POST" id="register_form">
		<input type="email" placeholder="email" name="email" />
		<input pattern="[A-Za-z]{3}" type="text" placeholder="login" name="login" />
		<input type="password" placeholder="password" name="password" />
	</form>
	<button type="submit" form="register_form">Submit</button>
	<br />
	<br />
	<a href='/login'>Login</a>
</p>
<?PHP
if ($data['weak_pass'] === true)
	echo "<p style='color:red'> This password is weak!</p>";
if ($data['email_is_valid'] === false)
	echo "<p style='color:red'> This email is invalid!</p>";
if ($data['email_available'] === false)
	echo "<p style='color:red'> This email already in use!</p>";
if ($data['login_available'] === false)
	echo "<p style='color:red'> This login already in use!</p>";
if ($data['code_was_sent'] === true)
	echo "
		<p>Verification code was sent to your email. Enter it below<p>
		<form action='code_verification' method='POST' id='enter_code_form'>
		<input type='text' placeholder='code' name='verification_code' />
		</form>
		<button type='submit' form='enter_code_form'>Submit</button>
"
?>
