<?PHP
function delete_entry_by_id($id)
{
	$fd = fopen("db.csv", "r");
	$new_csv = array();
	while (($item = fgetcsv($fd, 1000, ";")) !== false)
	{
		$used_id = $item[0];
		if ($used_id !== $id)
			array_push($new_csv, $item);
	}
	fclose($fd);
	$fd = fopen("db.csv", "w");
	foreach ($new_csv as $fields)
		fputcsv($fd, $fields, ";");
	fclose($fd);
}

delete_entry_by_id($_GET["id"]);
?>
