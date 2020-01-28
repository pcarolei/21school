<?PHP
class Controller_Login extends Controller
{
	function __construct()
	{
		$this->model = new Model_Login();
		$this->view = new View();
	}
	function action_index()
	{
		if (isset($_POST['login']) && isset($_POST['password']))
		{
			$login = htmlspecialchars($_POST['login']);
			$password = htmlspecialchars($_POST['password']);
			$res = $this->model->check_credentials($login, $password);
			if ($res === true)
			{
				$data['login_status'] = 'logged_in';
				$_SESSION['login'] = $login;
			}
			else
				$data['login_status'] = "wrong_credentials";
		}
		else
			$data['login_status'] = "";
		$this->view->generate('login_view.php', 'template_view.php', $data);
	}
}
?>
