<?PHP
class Controller_code_verification extends Controller
{
	function __construct()
	{
		$this->model = new Model_Register();
		$this->view = new View();
	}
	function action_index()
	{
		if (isset($_POST['verification_code']))
		{
			$email = $_SESSION['email'];
			$login = $_SESSION['login'];
			$password = $_SESSION['password'];
			if ($_POST['verification_code'] == $_SESSION['verification_code'])
				$this->model->register($email, $login, $password);
		}
		$this->view->generate('code_verification_view.php', 'template_view.php', $data);
	}
}
?>
