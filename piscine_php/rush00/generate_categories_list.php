<?PHP
function generate_categories_list()
{
	$fd = fopen("items.csv", "r");
	$item = fgetcsv($fd, 1000, ";");
	$categories = array();
	while (($item = fgetcsv($fd, 1000, ";")) !== false)
	{
		$cur_cat = $item[0];
		array_push($categories, $cur_cat);
	}
	$categories = array_unique($categories);
	fclose($fd);
	sort($categories);
	return ($categories);
}
?>
