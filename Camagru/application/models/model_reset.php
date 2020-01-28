<?PHP
class Model_Reset extends Model
{
	protected $db;
	public function __construct()
	{
		$this->db = MyPDO::instance();
	}
	public function reset_password()
	{
		function getRnd($n)
		{ 
			$characters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'; 
		    $randomString = ''; 
			for ($i = 0; $i < $n; $i++)
			{ 
		    	$index = rand(0, strlen($characters) - 1); 
			    $randomString .= $characters[$index]; 
		    } 
		    return $randomString; 
		} 
		$newpass = getRnd(10);
		$newpass_hashed = hash("whirlpool", $newpass);
		$login = $_SESSION['login'];
		$sql = "UPDATE users SET password = ? WHERE login = ?";
		$res = $this->db->run($sql, [$newpass_hashed, $login])->fetch();
		$sql = "SELECT email FROM users WHERE login = ?";
		$res = (array)$this->db->run($sql, [$login])->fetch();
		$mail = $res["email"];
		mail($mail, "Your new password", $newpass);
	}
}
?>
