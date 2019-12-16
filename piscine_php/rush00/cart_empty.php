<?PHP
session_start();
$_SESSION["cart"] = array();
$_COOKIE["order"] = array();
echo "<script>window.location = '/cart.php' </script>";
?>
