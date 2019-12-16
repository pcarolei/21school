<?PHP
function write_to_csv($user_data, $csv_filename)
{
	$fd = fopen("$csv_filename", "a");
	fputcsv($fd, $user_data, ";");
	fclose($fd);
}
function name_unused_check($name)
{
	$fd = fopen("items.csv", "r");
	$item = fgetcsv($fd, 1000, ";");
	while (($item = fgetcsv($fd, 1000, ";")) !== false)
	{
		$used_name = $item[0];
		if ($used_name === $name)
			return (false);
	}
	fclose($fd);
	return (true);
}
function name_nodelimiter_check($name)
{
	if (strstr($name, ";") !== false)
		return (false);
	return (true);
}
function create_item_entry($category, $name, $quantity, $price, $img_file)
{
//	TODO: input validation
	if (name_unused_check($name) && name_nodelimiter_check($name))
		return (array($category, $name, $quantity, $price, $img_file));
	return (NULL);
}
session_start();
print_r($_POST);
$category = $_POST["category"];
$name = $_POST["name"];
$quantity = $_POST["quantity"];
$price = $_POST["price"];
$img_file = $_POST["img_file"];
$is_admin = $_POST["admin"];
$item_entry = create_item_entry($category, $name, $quantity, $price, $img_file);
if ($item_entry !== NULL)
	write_to_csv($item_entry, "items.csv");
if ($is_admin == "admin")
	echo "<script>window.location = '/admin_panel.php' </script>";
else
	echo "<script>window.location = '/' </script>";
?>
