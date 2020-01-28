<?PHP
class Controller_Create extends Controller
{
	function __construct()
	{
		$this->view = new View();
		$this->model = new Model_Create();
	}
	function action_index()
	{
		$this->view->generate('create_view.php', 'template_view.php', $data);
	}
	function action_create()
	{
		$res = $this->model->create_result_image();
		echo $res;
	}
	function action_delete()
	{
		$res = $this->model->delete_result_image();
	}
}
?>
