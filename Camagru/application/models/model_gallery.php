<?PHP
class Model_Gallery extends Model
{
	protected $db;

	public function __construct()
	{
		$this->db = MyPDO::instance();
	}
	public function get_all_images()
	{
		$images = [];
		$sql = "SELECT filename FROM images";
		$filenames = (array)$this->db->run($sql, [])->fetchAll(PDO::FETCH_UNIQUE);
		foreach ($filenames as $file => $stdclass)
		{
			$sql = "SELECT login FROM images WHERE filename = ?";
			$logins = (array)$this->db->run($sql, [$file])->fetchAll(PDO::FETCH_COLUMN);
			foreach ($logins as $login)
			{
				$sql = "SELECT date FROM images WHERE login = ?";
				$date = $this->db->run($sql, [$login])->fetch(PDO::FETCH_COLUMN);
				$entry = [$date, $file, $login];
				array_push($images, $entry);
			}
		}
		return $images;
	}
	public function get_all_comments()
	{
		$cmt = [];
		$sql = "SELECT filename FROM comments";
		$filenames = (array)$this->db->run($sql, [])->fetchAll(PDO::FETCH_UNIQUE);
		foreach ($filenames as $file => $stdclass)
		{
			$sql = "SELECT comment FROM comments WHERE filename = ?";
			$comments = (array)$this->db->run($sql, [$file])->fetchAll(PDO::FETCH_COLUMN);
			foreach ($comments as $comment)
			{
				$sql = "SELECT author FROM comments WHERE comment = ?";
				$author = $this->db->run($sql, [$comment])->fetch(PDO::FETCH_COLUMN);
				$entry = [$file, $comment, $author];
				array_push($cmt, $entry);
			}
		}
		return $cmt;
	}
	public function notify_receiver($receiver, $comment)
	{
		$sql = "SELECT email FROM users WHERE login = ?";
		$email = (array)$this->db->run($sql, [$receiver])->fetch();
		$email = $email['email'];
		mail($email, "You have received new comment!", "<{$comment}>");
	}
	public function add_comment($author, $comment, $filename, $receiver)
	{
		echo "$comment $filename $author $receiver";
		$sql = "INSERT INTO comments(comment, filename, author, receiver) VALUES(?,?,?,?)";
		$this->db->run($sql, [$comment, $filename, $author, $receiver])->fetch();
		$this->notify_receiver($receiver, $comment);
	}
}
?>
