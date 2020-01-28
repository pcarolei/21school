<?PHP
if (!isset($_SESSION['login']))
{
	echo "
	<script>
		window.location='/';
	</script>";
}
?>
<h1>Modify Page</h1>
<p>
	<form action="" method="POST" id="modify_form">
		<input type="email" placeholder="email" name="email" />
		<input type="text" placeholder="login" name="login" />
		<input type="password" placeholder="password" name="password" />
		<input type="text" placeholder="notify me(0/1)" name="notify" />
	</form>
	<button type="submit" form="modify_form">Submit</button>
	<br />
</p>
<?PHP
if ($data['wrong_credentials_modif'])
{
	echo "<p>WRONG CREDENTIALS TO MODIFY ACCAUNT!</p>";
	$data['wrong_credentials_modif'] = NULL;
}
?>
