<?PHP
class Model_Modify extends Model
{
	protected $db;
	public function __construct()
	{
		$this->db = MyPDO::instance();
	}
	public function change_entry($user, $email, $login, $password, $notify)
	{
		if (($notify !== "1") && ($notify !== "0"))
			return (false);
		if (!filter_var($email, FILTER_VALIDATE_EMAIL))
			return (false);
		$password_hashed = hash("whirlpool", $password);
		$sql = "SELECT * FROM users WHERE login = ?";
		$id = (array)$this->db->run($sql, [$user])->fetch();
		$id = $id['id'];
		echo "$user $login $password_hashed $email, $notify $id";
		$sql = "UPDATE users SET login=?, password=?, email=?, notify=? WHERE id=?";
		$res = (array)$this->db->run($sql, [$login, $password_hashed, $email, intval($notify), $id])->fetch();
		return ($true);
		/* $sql = "UPDATE users SET login"; */
		/* return (var_dump($_SESSION)); */
	}
}
?>
