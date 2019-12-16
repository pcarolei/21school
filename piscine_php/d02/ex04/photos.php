#!/usr/bin/php
<?PHP
function array_flatten($array)
{
	if (!is_array($array))
		return false; 
	$result = array(); 
	foreach ($array as $key => $value)
	{ 
		if (is_array($value))
			$result = array_merge($result, array_flatten($value)); 
		else
			$result = array_merge($result, array($key => $value));
	} 
	return $result; 
}

if ($argc != 2)
	exit;
$url = $argv[1];
$ch = curl_init();
$timeout = 5;
curl_setopt($ch, CURLOPT_URL, $url);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, $timeout);
$html = curl_exec($ch);
curl_close($ch);
preg_match_all('/src\s*=\s*"([^"]+)"/', $html, $matches);
$matches = array_flatten($matches);
$j = 1;
for ($i = 0; $i < count($matches); $i++)
{
	$link = $matches[$i];
	if (preg_match("/src=/", $link) === 1)
		continue;
	$link = $url.$link;
	list($scriptPath) = get_included_files();
	$fullpath = str_replace("photos.php", "$j", $scriptPath);
	$ch = curl_init($link);
	curl_setopt($ch, CURLOPT_HEADER, 0);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
	curl_setopt($ch, CURLOPT_BINARYTRANSFER,1);
	$raw=curl_exec($ch);
	curl_close($ch);
	$fp = fopen("$fullpath",'x');
	fwrite($fp, $raw);
	fclose($fp);
	$j++;
}
?>
