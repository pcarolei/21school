<?PHP
class House
{
	public function introduce()
	{
		$houseName = static::getHouseName();
		$houseMotto = static::getHouseMotto();
		$houseSeat = static::getHouseSeat();
		print("House $houseName of $houseSeat : \"$houseMotto\"" . PHP_EOL);
	}
}
?>
