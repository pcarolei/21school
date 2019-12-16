<?PHP
include "items.php";
include "generate_categories_list.php";
session_start();
$greeting = "Guest";
$href = "login.php";
if ($_SESSION["logged_in_user"] != "")
{
	$greeting = $_SESSION["logged_in_user"];
	$href = "logout.php";
}
if (isset($_SESSION["cart"]) === false)
	$_SESSION["cart"] = array();
if ((isset($_COOKIE["order"]) === true) && ($_SESSION["cookie_activated"] != "true"))
{
	$cart = $_SESSION["cart"];
	parse_str($_COOKIE["order"], $order);
	$names = array_keys($order);
	foreach ($names as $name)
		$cart[$name] = $order[$name];
	$_SESSION["cart"] = $cart;
	$_SESSION["cookie_activated"] = "true";
}
?>
<html>
<head>
    <title>PERFECT ONLINE SHOP</title>
	<base href="/" target="_blank" />
    <link href="https://fonts.googleapis.com/css?family=Oswald:400,500,600,700&display=swap" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Roboto+Mono:400,700&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <div class="header">
        <a href="index.php" target="_self">Perfect online shop</a>
		<a href="<?= $href ?>" style="float:right" target='_self'>
			&#x1f916  Hello, <?= $greeting ?>
		<?PHP
			if ($_SESSION["access_rights"] === "admin")
				echo "<a href='/admin_panel.php' target='_self'> Admin Panel </a>";
		?>
		</a>
        <a style="float:right" target='_self' href="cart.php">&#x1f6d2 Cart </a>
	</div>
	<div class="welcome">
			<h1 style='margin-bottom: 20px;'>PERFECT ONLINE SHOP</h1>
			<p>We sell perfection!</p>
    </div>
    <div class ="content">
		<?PHP
		// $items1 = array(get_item_by_name("rb1"), get_item_by_name("rb2"), get_item_by_name("rb3"));
		$categories = generate_categories_list();
		foreach($categories as $cur_cat)
		{
		echo "<h2>$cur_cat</h2>";
			if ($cur_cat != "Bestsellers")
				$items = get_items_by_category($cur_cat);
			foreach ($items as $item)
			{
				$img_path = "assets/$item[4]";
				$name = "$item[1]";
				echo "<div class='item-list'>
				<div class='photo' style='width: 120px; height:120px'>
					<img src='$img_path'/><br />
				</div>
				<b>$item[1]</b><br />
				<b>quantity $item[2]</b><br />
				<b>$item[3]$</b>
				";

				echo "<br />";
				if ($item[2] > 0)
				{
					echo "<a
							target='_self'
							href='add_to_cart.php?name=$name'
						>
							ADD TO CART
						</a>";
					echo "</div>";
				}
				else
				{
					echo "<a
							disabled
							target='_self'
							href='add_to_cart.php?name=$name'
						>
							OUT OF STOCK
						</a>";
					echo "</div>";

				}
			}
		}
	
    
	
				$items = array(get_item_by_name("Bracelet"), get_item_by_name("Sumka"), get_item_by_name("Smenka"), get_item_by_name("Sumka2"));
				echo "<div><h2 style='margin-top:140px;'>Bestsellers</h2>";
					foreach ($items as $item)
					{
						// $name = "$item[1]";
						// echo "<div
						// 	class='item-list'
						// >";
						// echo "<img
						// src='$img_path'
						// />";
						// echo "<br />";
						// echo "<b>name = $item[1]</b>";
						// echo "<br />";
						// echo "<b>quantity = $item[2]</b>";
						// echo "<br />";
						// echo "<b>price = $item[3]</b>";
						// $img_path = "assets/$item[4]";
						$name = "$item[1]";
						$img_path = "assets/$item[4]";
						echo "<div
							class='item-list' style='margin-bottom: 40px;'
						>
						<div class='photo' style='width: 120px; height:120px'>
						<img
						src='$img_path'
						/>
						</div>
						<br /><b>$item[1]</b><br /><b>quantity $item[2]</b><b>$item[3]$</b><br />";
						if ($item[2] > 0)
						{
							echo "<a
									target='_self'
									href='add_to_cart.php?name=$name'
								>
									ADD TO CART
								</a>";
							echo "</div>";
						}
						else
						{
							echo "<a
									disabled
									target='_self'
									href='add_to_cart.php?name=$name'
								>
									OUT OF STOCK
								</a>";
							echo "</div>";

						}
					}
	?>
	</div>
</body>
</html>
