<?PHP
session_start();
$cart = $_SESSION["cart"];
$cookie_name = "order";
$cookie_value = http_build_query($cart);
setcookie($cookie_name, $cookie_value);
$_SESSION["cookie_activated"] = "false";
echo "<script>window.location = '/cart.php' </script>";
?>
