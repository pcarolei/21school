<?PHP
class Model_Login extends Model
{
	protected $db;
	public function __construct()
	{
		$this->db = MyPDO::instance();
	}
	public function check_credentials($login, $password)
	{
		$hashed_password = hash("whirlpool", $password);
		$sql = "SELECT id FROM users WHERE login = ? AND password = ?";
		$res = (array)$this->db->run($sql, [$login, $hashed_password])->fetch();
		if ($res['id'] === NULL)
			return ($hashed_password);
		$_SESSION['login'] = $login;
		return (true);
	}
}
?>
