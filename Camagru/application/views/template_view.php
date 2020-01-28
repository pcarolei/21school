<!DOCTYPE html>
<html>
<head>
	<title>Camagru aka Gachizator</title>
 	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<script defer src="https://use.fontawesome.com/releases/v5.3.1/js/all.js"></script>
 	<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.8.0/css/bulma.min.css">
 	<link rel="stylesheet" href="public/css/styles.css">
</head>
<body>
	<header>
		<nav>
			<a href="/">Main </a>
			<?PHP
				if ($_SESSION['login'])
				{
					echo "<a href='/exit'>Exit </a>";
					echo "<a href='/reset'>Reset password </a>";
					echo "<a href='/modify'>Modify acc </a>";
					echo "<a href='/create'>Create </a>";
				}
				else
				{
					echo "<a href='/login'>Login </a>";
					echo "<a href='/register'>Register </a>";
				}
			?>
			<a href="/gallery">Gallery</a>
		</nav>
	</header>
	<?PHP include 'application/views/' . $content_view; ?>
	<footer>
		<p>Created by: pcarolei</p>
		<p>Contact info:
			<a href="mailto:peppermintcarolei@gmail.com">
				peppermintcarolei@gmail.com
			</a>
		</p>
	</footer>
</body>
</html>
