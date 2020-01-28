<?PHP
class Controller_reset extends Controller
{
	function __construct()
	{
		$this->view = new View();
		$this->model = new Model_Reset();
	}
	function action_index()
	{
		$this->model->reset_password();
		echo "
			<script>
			window.location='/exit';
			</script>";
	}
}
?>
