<?PHP
class Controller_Modify extends Controller
{
	function __construct()
	{
		$this->model = new Model_Modify();
		$this->view = new View();
	}
	/* function action_index() */
	/* { */
		/* $this->view->generate('modify_view.php', 'template_view.php', $data); */
	/* } */
	/* function action_modify() */
	function action_index()
	{
		if (isset($_POST['email']) && isset($_POST['login']) && isset($_POST['password']) &&
		isset($_POST['notify']))
		{
			$email = htmlspecialchars($_POST['email']);
			$login = htmlspecialchars($_POST['login']);
			$password = htmlspecialchars($_POST['password']);
			$notify = htmlspecialchars($_POST['notify']);
		}
		if (isset($_SESSION['login']))
		{
			$user = $_SESSION['login'];
			$res = $this->model->change_entry($user, $email, $login, $password, $notify);
			if ($res === false)
			{
				if (isset($_POST['login']))
					$data['wrong_credentials_modif'] = true;
				$this->view->generate('modify_view.php', 'template_view.php', $data);
			}
			else
			{
				echo "
				<script>
				window.location='/exit';
			</script>";
			}

		}
		else
			$this->view->generate('modify_view.php', 'template_view.php', $data);
	}
}
?>
