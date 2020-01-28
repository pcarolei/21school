<?PHP
class View
{
	//	$content_file - вид, отображающий контент страниц
	//	$template_file - общий для всех страниц шаблон
	//	$data - массив, содержащий элементы контента страницы
	//			обычно заполняется в модели
	function generate($content_view, $template_view, $data = null)
	{
		include 'application/views/' . $template_view;
	}
}
?>
