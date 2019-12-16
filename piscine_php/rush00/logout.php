<?PHP
session_start();
$_SESSION["logged_in_user"] = "";
$_SESSION["access_rights"] = "";
$_SESSION["cart"] = array();
echo "<script>window.location = '/' </script>";
?>
