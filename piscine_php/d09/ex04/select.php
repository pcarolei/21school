<?PHP
$fp = fopen("db.csv", "r");
$str = "";
while ($data = fgetcsv($fp, 1000, ";"))
{
	$str = $str . $data[0] . "=" . $data[1] . ";";
}
fclose($fp);
echo $str;
?>
