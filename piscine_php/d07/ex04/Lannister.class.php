<?PHP
class Lannister
{
	public function sleepWith($gf)
	{
		$gf_parent = get_parent_class($gf);
		if ($gf_parent !== "Lannister")
			print("Let's do this.\n");
		else
			print("Not even if I'm drunk !\n");
	}
}
?>
