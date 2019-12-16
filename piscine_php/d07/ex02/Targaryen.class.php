<?PHP
class Targaryen
{
	public function resistsFire()
	{
		return (False);
	}
	public function getBurned()
	{
		/* if ($this->resistsFire() === False) */
		if (static::resistsFire() === False)
			return ("burns alive");
		return ("emerges naked but unharmed");
	}
}
?>
