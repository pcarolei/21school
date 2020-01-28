<p>Gallery</p>
<?PHP

$images = $data['images'];
$comments = $data['comments'];
$cant_comment = true;
if (isset($_SESSION['login']))
	$cant_comment = false;
$id = 0;
foreach ($images as $image)
{
	$id++;
	$form_id = "comment_form_$id";
	echo 	"<div class='box'>
				<p>DATE: {$image[0]}</p>
				<p>AUTHOR: {$image[2]}</p>
				<img src='{$image[1]}'/>
				<form action='gallery/comment' method='POST' id='$form_id'>
					<input type='text' placeholder='comment' name='comment' />
					<input type='hidden' name='filename' value={$image[1]} />
					<input type='hidden' name='receiver' value={$image[2]} />
					<input type='hidden' name='author' value={$_SESSION['login']} />
				</form>";
	if (!$cant_comment)
	{
		echo "
				<button type='submit' form='$form_id'>Post comment</button>";
	}
	echo "</div>";
	foreach ($comments as $comment)
	{
		if ($comment[0] === $image[1])
		{
			echo "<div class='box'>";
			echo "<p>Comment: $comment[1]</p>";
			echo "<p>Author: $comment[2]</p>";
			echo "</div>";
		}
	}
}
?>
