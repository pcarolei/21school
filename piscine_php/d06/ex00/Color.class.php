<?PHP
class Color
{
	public $red;
	public $green;
	public $blue;
	static $verbose = false;

	public function __construct(array $rgb)
	{
		if (array_key_exists("rgb", $rgb))
		{
			$c = intval($rgb['rgb']);
			$this->red = $c % 256;
			$this->green = ($c >> 8) % 256;
			$this->blue = ($c >> 16) % 256;
		}
		else
		{
			$this->red = intval($rgb['red']);
			$this->green = intval($rgb['green']);
			$this->blue = intval($rgb['blue']);
		}
		if (self::$verbose)
			print($this->__toString() . " constructed.\n");
	}
	public function __destruct()
	{
		if (self::$verbose)
			print($this->__toString() . " destructed.\n");
	}
	public function __toString()
	{
		$red = $this->red;
		$blue = $this->blue;
		$green = $this->green;
		$str = sprintf("Color( red: %3d, green: %3d, blue: %3d )",
				$red, $green, $blue);
		return ($str);
	}
	public static function doc()
	{
		return (file_get_contents("./Color.doc.txt"));
	}
	public function add($snd)
	{
		$new_red = $this->red + $snd->red;
		$new_green = $this->green + $snd->green;
		$new_blue = $this->blue + $snd->blue;
		$new_rgb = array('red' => $new_red,
						 'green' => $new_green,
						 'blue' => $new_blue);
		return (new Color($new_rgb));
	}
	public function sub($snd)
	{
		$new_red = $this->red - $snd->red;
		$new_green = $this->green - $snd->green;
		$new_blue = $this->blue - $snd->blue;
		$new_rgb = array('red' => $new_red,
						 'green' => $new_green,
						 'blue' => $new_blue);
		return (new Color($new_rgb));
	}
	public function mult($f)
	{
		$new_red = intval($this->red * $f);
		$new_green = intval($this->green * $f);
		$new_blue = intval($this->blue * $f);
		$new_rgb = array('red' => $new_red,
						 'green' => $new_green,
						 'blue' => $new_blue);
		return (new Color($new_rgb));
	}
}
?>
