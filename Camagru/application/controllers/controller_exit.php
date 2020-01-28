<?PHP
class Controller_Exit extends Controller
{
	function action_index()
	{
		$_SESSION['login'] = NULL;
		echo "
		<script>
			window.location='/';
		</script>";
	}
}
?>
