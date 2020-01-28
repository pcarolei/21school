<?PHP
class Controller_Register extends Controller
{
	function __construct()
	{
		$this->model = new Model_Register();
		$this->view = new View();
	}
	function action_index()
	{
		if (isset($_POST['email']) && isset($_POST['login'])
				&& isset($_POST['password']))
		{
			$email = htmlspecialchars($_POST['email']);
			$login = htmlspecialchars($_POST['login']);
			$password = htmlspecialchars($_POST['password']);
			$data = $this->model->check_credentials($email, $login);
			if (!preg_match('~[0-9]+~', $password))
				$data['weak_pass'] = true;
		}
		if (($data['email_is_valid'] === true) && 
			($data['email_available'] === true) &&
			(preg_match('~[0-9]+~', $password)))
		{
			$code = $this->model->verify_email($email);
			$data['code_was_sent'] = true;
			$_SESSION['email'] = $email;
			$_SESSION['login'] = $login;
			$_SESSION['password'] = $password;
			$_SESSION['verification_code'] = $code;
		}
		$this->view->generate('register_view.php', 'template_view.php', $data);
	}
}
?>
