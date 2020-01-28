<?PHP
class Model_Register extends Model
{
	protected $db;
	public function __construct()
	{
		$this->db = MyPDO::instance();
	}
	public function check_credentials($email, $login)
	{
		if (!filter_var($email, FILTER_VALIDATE_EMAIL))
		{
			$res['email_is_valid'] = false;
			return ($res);
		}
		$res['email_is_valid'] = true;
		$res['email_available'] = false;
		$res['login_available'] = false;
		$sql = "SELECT id FROM users WHERE email = ?";
		$res_email = (array)$this->db->run($sql, [$email])->fetch();
		$sql = "SELECT id FROM users WHERE login = ?";
		$res_login = (array)$this->db->run($sql, [$login])->fetch();
		if ($res_email['id'] === NULL)
			$res['email_available'] = true;
		if ($res_login['id'] === NULL)
			$res['login_available'] = true;
		return ($res);
	}
	public function verify_email($email)
	{
		$code = rand(pow(10, 3), pow(10, 4) - 1);
		mail($email, "Verification code", "$code");
		return ($code);
	}
	public function register($email, $login, $password)
	{
		$hashed_password = hash("whirlpool", $password);
		$sql = "INSERT INTO users(login, password, email) VALUES(?, ?, ?)";
		$res = $this->db->run($sql, [$login, $hashed_password, $email]);
		$_SESSION['registration_complete'] = true;
	}
}
?>
