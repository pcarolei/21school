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
delete_item_by_name($_GET["name"]);
echo "<script>window.location = '/admin_panel.php' </script>";

?>
