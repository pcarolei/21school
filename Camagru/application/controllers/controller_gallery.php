<?PHP
class Controller_Gallery extends Controller
{
	function __construct()
	{
		$this->view = new View();
		$this->model = new Model_Gallery();
	}
	function action_index()
	{
		$images = $this->model->get_all_images();
		$cmt = $this->model->get_all_comments();
		$data['images'] = $images;
		$data['comments'] = $cmt;
		$this->view->generate('gallery_view.php', 'template_view.php', $data);
	}
	function action_comment()
	{
		/* if (isset($_POST['author']) && isset($_POST['comment']) && isset($_POST['filename']) */
		if (isset($_POST['author']) && isset($_POST['filename'])
			&& isset($_POST['receiver']))
		{
			$comment = htmlspecialchars($_POST['comment']);
			$this->model->add_comment($_POST['author'], $comment, $_POST['filename'],
			$_POST['receiver']);
		}
		echo "
			<script>
				window.location='/gallery';
			</script>";
	}
	function action_inclim()
	{
		echo "
			<script>
				window.location='/gallery';
				document.location.reload(true);
				window.location='/gallery';
			</script>";
	}
}
?>
