<?PHP
class Jaime extends Lannister
{
	public function sleepWith($gf)
	{
		$gf_parent = get_parent_class($gf);
		$gf_name = get_class($gf);
		if ($gf_name === "Cersei")
			print("With pleasure, but only in a tower of Winterfell, then.\n");
		else if ($gf_parent !== "Lannister")
			print("Let's do this.\n");
		else
			print("Not even if I'm drunk !\n");
	}
}
?>
