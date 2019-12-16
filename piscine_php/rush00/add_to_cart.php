<?PHP
session_start();

$cart = $_SESSION["cart"];
$name = $_GET["name"];
if (!$cart[$name])
	$cart[$name] = 1;
else
	$cart[$name]++;
$_SESSION["cart"] = $cart;
echo "<script>window.location = '/' </script>";
?>
