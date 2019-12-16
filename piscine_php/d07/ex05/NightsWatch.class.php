<?PHP
class NightsWatch
{
	private $arr_recruits = array();
	public function recruit($rookie)
	{
		if (method_exists($rookie, "fight"))
			array_push($this->arr_recruits, $rookie);
	}
	public function fight()
	{
		foreach ($this->arr_recruits as $fighter)
			$fighter->fight();
	}
}
?>
