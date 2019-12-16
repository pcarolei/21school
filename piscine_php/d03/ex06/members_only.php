<?PHP
if ($_SERVER["PHP_AUTH_USER"] === "zaz"
 && $_SERVER["PHP_AUTH_PW"] === "Ilovemylittleponey")
{
	header("Content-Type: text/html");
	$img_data = base64_encode(file_get_contents("../img/42.png"));
	echo "<html><body>\n";
	echo "Hello Zaz<br />\n";
	echo '<img src="data:image/png;base64,';
	echo $img_data;
	echo "'>\n";
	echo "</body></html>\n";
}
else
{
	header("HTTP/1.1 401 Unauthorized");
	header("Date: Tue, 26 Mar 2013 09:42:42 GMT");
	header("Server: Apache");
	header("WWW-Authenticate: Basic realm=''Member Area''");
	header("Content-Type: text/html");
	header("Content-Length: 72");
	header("Connection: close");
	echo "<html><body>That area is accessible for members only</body></html>\n";
}
?>
