<h3>Create your images here</h3>
<p>WIP</p>
<?PHP
if (!isset($_SESSION['login']))
{
	echo "
	<script>
		window.location='/login';
	</script>";
}
require_once('superposable.php');
require_once('webcam_display.php');
require_once('thumbnails.php');
?>
