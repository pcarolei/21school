<?PHP
function write_to_csv($user_data, $csv_filename)
{
	$fd = fopen("$csv_filename", "a");
	fputcsv($fd, $user_data, ";");
	fclose($fd);
}
function get_item_by_name($name)
{
	$fd = fopen("items.csv", "r");
	$item = fgetcsv($fd, 1000, ";");
	while (($item = fgetcsv($fd, 1000, ";")) !== false)
	{
		if ($item[1] == $name)
			return ($item);
	}
	fclose($fd);
	return (NULL);
}
function create_item_entry($category, $name, $quantity, $price, $img_file)
{
//	TODO: input validation
	if (name_unused_check($name) && name_nodelimiter_check($name))
		return (array($category, $name, $quantity, $price, $img_file));
	return (NULL);
}
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
function reduce_quantity($cart)
{
	$new_csv = array();
	$fd = fopen("items.csv", "r");
	while (($item = fgetcsv($fd, 1000, ";")) !== false)
			array_push($new_csv, $item);
	//echo "old_csv = ";print_r($new_csv);echo "<br />";
	$i = 0;
	foreach ($new_csv as $item)
	{
		foreach ($cart as $key => $value)
		{
			//echo "key = ";print_r($key);echo "<br />";
			//echo "value = ";print_r($value);echo "<br />";
			if ($item[1] === $key)
			{
				//echo "old_item = ";print_r($item);echo "<br />";
				$new_csv[$i][2] -= $value;
				//echo "new_item = ";print_r($item);echo "<br />";
			}
		}
		$i++;
	}
	$fd = fopen("items.csv", "w");
	foreach ($new_csv as $fields)
		fputcsv($fd, $fields, ";");
	//echo "new_csv = ";print_r($new_csv);echo "<br />";
	fclose($fd);
}
session_start();
if ($_SESSION['logged_in_user'] == '')
{
	echo "<script>window.location = '/create.php' </script>";
	exit();
}
reduce_quantity($_SESSION["cart"]);
$order = array($_SESSION["logged_in_user"], http_build_query($_SESSION["cart"]));
write_to_csv($order, "orders.csv");
$_SESSION["cart"] = array();
$_COOKIE["order"] = array();
echo "<script>window.location = '/cart.php' </script>";
?>
