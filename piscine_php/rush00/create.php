<?PHP
session_start();
?>
<html>
    <head>
        <link href="https://fonts.googleapis.com/css?family=Oswald:400,500,600,700&display=swap" rel="stylesheet">
        <link href="https://fonts.googleapis.com/css?family=Roboto+Mono:400,700&display=swap" rel="stylesheet">
        <title>CREATE ACCOUNT</title>
        <link rel="stylesheet" href="styles.css">
    </head>

    <body>
        <div class="sheet">
            <h2>SIGN UP TO PLACE YOUR ORDER</h2>
            <div class="label">login</div>
			<form action="create_user.php" id="form" method="POST">
			<input
				type="text"
				name="login"
				placeholder="enter login"
				value=""
			/>
			<br/>
            <div class="label">password</div>
			<input
				type="password"
				name="passwd"
				placeholder="enter password"
				value=""
			/>
			<br/>
            <div><input type="submit" name="submit" value="OK"/></div>
			</form>
            <a href="login.php">ALREADY HAVE AN ACCOUNT?</a>
        </div>
	</body>
</html>
