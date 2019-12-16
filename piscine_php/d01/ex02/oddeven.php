#!/usr/bin/php
<?PHP
while (true)
{
	print("Enter a number: ");
	$line = fgets(STDIN);
	if ($line === false)
	{
		print("\n");
		exit;
	}
	$fline = substr($line, 0, -1);
	if (is_numeric($fline) === false)
		print("'$fline' is not a number\n");
	else
	{
		$n = (int)$fline;
		if ($n % 2 == 0)
			echo "The number $fline is even\n";
		else
			echo "The number $fline is odd\n";
	}
}
?>
