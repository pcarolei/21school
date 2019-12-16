<?PHP
function delete_order($login, $order)
{
	$fd = fopen("orders.csv", "r");
	$new_csv = array();
	$flag = 1;
	while (($elem = fgetcsv($fd, 1000, ";")) !== false)
	{
		$used_lg = $elem[0];
		$used_od = $elem[1];
		echo "used_lg = ";var_dump($used_lg);
		echo "<br />";
		echo "used_od = ";var_dump($used_od);
		echo "<br />";
		echo "order = ";var_dump($order);
		echo "<br />";
		if ((($used_lg === $login) && ($used_od === $order)) && ($flag == 1))
		{
			echo "---------";
			echo "<br />";
			$flag = 0;
		}
		else
		{
			echo "+++++++++";
			echo "<br />";
			array_push($new_csv, $elem);
		}
	}
	fclose($fd);
	$fd = fopen("orders.csv", "w");
	echo "new_csv = ";print_r($new_csv);
	foreach ($new_csv as $fields)
		fputcsv($fd, $fields, ";");
	fclose($fd);
}
delete_order($_POST["login"], $_POST["order"]);
echo "<script>window.location = '/admin_panel.php' </script>";
?>
