<?PHP
function delete_item_by_name($name)
{
	$fd = fopen("items.csv", "r");
	$new_csv = array();
	while (($item = fgetcsv($fd, 1000, ";")) !== false)
	{
		$used_name = $item[0];
		if ($used_name !== $name)
			array_push($new_csv, $item);
	}
	fclose($fd);
	$fd = fopen("items.csv", "w");
	foreach ($new_csv as $fields)
		fputcsv($fd, $fields, ";");
	fclose($fd);
}
function write_to_csv($user_data, $csv_filename)
{
	$fd = fopen("$csv_filename", "a");
	fputcsv($fd, $user_data, ";");
	fclose($fd);
}
function create_item_entry($category, $name, $quantity, $price, $img_file)
{
//	TODO: input validation
	return (array($category, $name, $quantity, $price, $img_file));
}

session_start();
$category = $_POST["category"];
$oldname = $_POST["oldname"];
$newname = $_POST["newname"];
$quantity = $_POST["quantity"];
$price = $_POST["price"];
$img_file = $_POST["img_file"];
$is_admin = $_POST["admin"];
delete_item_by_name($oldname);
$item_entry = create_item_entry($category, $newname, $quantity, $price, $img_file);
if ($item_entry !== NULL)
	write_to_csv($item_entry, "items.csv");
echo "<script>window.location = '/admin_panel.php' </script>";
?>
