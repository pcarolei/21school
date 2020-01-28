<?PHP
class Model_Create extends Model
{
	protected $db;
	public function __construct()
	{
		$this->db = MyPDO::instance();
	}
	private function get_superp_by_id($id)
	{
		if ($id == '1')
			return ("images/kazuya.png");
		if ($id == '2')
			return ("images/aniki.png");
		return ("images/kosugi.png");
	}
	private function write_to_base($filename)
	{
		$login = $_SESSION['login'];
		$sql = "INSERT INTO images(login, filename) VALUES(?, ?)";
		$res = $this->db->run($sql, [$login, $filename]);
	}
	private function delete_from_base($login, $filename)
	{
		$sql = "DELETE FROM images WHERE login=? AND filename=?";
		$res = $this->db->run($sql, [$login, $filename]);
	}
	public function create_result_image()
	{
		$supr_id = $_POST['superposable'];
		$encoded_img = $_POST['image'];
		$encoded_img = str_replace('data:image/png;base64,', '', $encoded_img);
		$encoded_img = str_replace(' ', '+', $encoded_img);
		$decoded_img = base64_decode($encoded_img);
		$sp_file = $this->get_superp_by_id($supr_id);
		$jpg = imagecreatefromstring($decoded_img);
		$png = imagecreatefrompng($sp_file);
		$jpg = imagescale($jpg, 250, 250);
		$png = imagescale($png, 250, 250);
		imagecopy($jpg, $png, 0, 0, 0, 0, 250, 250);
		if (!file_exists("images/" . $_SESSION['login']))
			mkdir("images/" . $_SESSION['login']);
		$img_file = "images/" . $_SESSION['login'] . "/" . time();
		imagepng($jpg, $img_file, 0);
		$this->write_to_base($img_file);
		return $img_file;
	}
	public function delete_result_image()
	{
		$filename = $_POST['filename'];
		$login = $_SESSION['login'];
		$this->delete_from_base($login, $filename);
	}
}
?>
