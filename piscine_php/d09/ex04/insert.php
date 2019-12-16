<?PHP
$fp = fopen("db.csv", "a");
$entry = array($_POST["id"], $_POST["text"]);
fputcsv($fp, $entry, ";");
fclose($fp);
?>
