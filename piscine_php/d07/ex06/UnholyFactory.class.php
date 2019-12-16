<?PHP
class UnholyFactory
{
	private $absorbed_fighters = array();
	public function absorb($candidate)
	{
		$ft = $candidate->fighter_type;
		if (get_parent_class($candidate) !== "Fighter")
			print("(Factory can't absorb this, it's not a fighter)\n");
		else if (in_array($candidate, $this->absorbed_fighters) === false)
		{
			array_push($this->absorbed_fighters, $candidate);
			print("(Factory absorbed a fighter of type $ft)\n");
		}
		else
			print("(Factory already absorbed a fighter of type $ft)\n");
	}
	public function fabricate($f_type)
	{
		foreach ($this->absorbed_fighters as $c)
		{
			if ($f_type === $c->fighter_type)
			{
				print("(Factory fabricates a fighter of type $f_type)\n");
				return ($c);
			}
		}
		print("(Factory hasn't absorbed any fighter of type $f_type)\n");
		return (NULL);
	}
}
?>
