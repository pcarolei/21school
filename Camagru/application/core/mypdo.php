<?PHP
class MyPDO
{
	protected static $instance;
	static $limit;
	protected $pdo;

	public function __construct()
	{
		$opt  = array(
			PDO::ATTR_ERRMODE				=> PDO::ERRMODE_EXCEPTION,
			PDO::ATTR_DEFAULT_FETCH_MODE	=> PDO::FETCH_OBJ,
			PDO::ATTR_EMULATE_PREPARES		=> FALSE,
		);
		$dsn = 'mysql:host=127.0.0.1;dbname=camagru_db;charset=utf8';
		$this->pdo = new PDO($dsn, 'camagru', 'camagru', $opt);
	}

	// a classical static method to make it universally available
	public static function instance()
	{
		if (self::$instance === null)
		{
			self::$instance = new self;
		}
		return self::$instance;
	}

	// a proxy to native PDO methods
	public function __call($method, $args)
	{
		return call_user_func_array(array($this->pdo, $method), $args);
	}

	// a helper function to run prepared statements smoothly
	public function run($sql, $args = [])
	{
		if (!$args)
		{
			 return $this->query($sql);
		}
		$stmt = $this->pdo->prepare($sql);
		$stmt->execute($args);
		return $stmt;
	}
}
?>
