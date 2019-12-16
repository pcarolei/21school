<?PHP
session_start();
?>
<html>
<head>
	<title>LOGIN PAGE</title>
	<link href="https://fonts.googleapis.com/css?family=Oswald:400,500,600,700&display=swap" rel="stylesheet">
	<link href="https://fonts.googleapis.com/css?family=Roboto+Mono:400,700&display=swap" rel="stylesheet">
	<link rel="stylesheet" href="styles.css">
</head>
<body>
	<div class="sheet">
		<h2>LOG IN TO PLACE YOUR ORDER</h2>
		<div class="label">login</div>
		<form action="login_handler.php" method="POST">
		<input type = "text" name = "login" placeholder = "enter login" value = "" /><br/>
		<div class="label">password</div>
		<input type = "password" name = "passwd" placeholder = "enter password" value = "" /><br/>
		<div><input type = "submit" name = "submit" value = "Let me in"/></div>
		</form>
		<a href="create.php">I’M NEW TO THIS SITE </a>
	</div>
</body>
</html>
