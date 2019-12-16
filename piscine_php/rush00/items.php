<?PHP
function get_items_by_category($category)
{
	$fd = fopen("items.csv", "r");
	$items = array();
	$item = fgetcsv($fd, 1000, ";");
	while (($item = fgetcsv($fd, 1000, ";")) !== false)
	{
		if ($item[0] == $category)
			array_push($items, $item);
	}
	fclose($fd);
	return ($items);
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
?>
