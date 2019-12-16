<?PHP
include "items.php";
session_start();
$names = array_keys($_SESSION["cart"]);
$cart = $_SESSION["cart"];
$overall_total = 0;
$can_i_buy = 1;

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
		<title>CART</title>
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
		<div class = 'row'>
			<div class = 'leftcolumn'>
					<h2>&#x1f6d2 Cart</h2>
					<?php
					if ($_GET['name'] && $_GET['mod'])
					{
						$n = $_GET['name'];
						$m = intval($_GET['mod']);
					}
					foreach ($names as $name)
					{
						if ($_SESSION['cart'][$name] == 0)
							continue;
						$item = get_item_by_name($name);
						$how_much = $cart[$name];
						if ($n == $name)
							$how_much += $m;
						if ($how_much == 0)
							continue;
						if ($how_much > $item[2])
							$can_i_buy = 0;
						$price = $item[3];
						$total = $price * $how_much;
						$overall_total += $total;
						$img_path = "assets/$item[4]";
						echo "<div class='cart-item'>
							<div class='photo' style='width: 120px; height:120px'>
								<img src=$img_path />
							</div>
							<div class='info'>
								<h4 style='margin-bottom: 0px;''>$name</h4>
								<p>$price$</p>
							</div>
							<div class='counter'>
								<a class='more-less' style='margin-right:20px;' href='cart.php?name=$name&mod=-1' target='_self'>-1</a>
								$how_much
								<a class='more-less' style='margin-left:20px;'href='cart.php?name=$name&mod=1' target='_self'>+1</a>
							</div>
							<div class = 'total-price'>
								<h3>$total$</h3>
							</div>
						</div>"; 
					}
					?>
			</div>
			<div class='rightcolumn'>
				<p>Overall</p></ br>
				<?php
				echo "<h2>$overall_total $</h2>";
				?>
				<a href='archive.php' target='_self'><button> Archive order </button></a></ br>
				<a href='cart_empty.php' target='_self'><button> Delete order </button></a></ br>
				<?php
				if ($n && $m && ($_SESSION['cart'][$n] > 0))
					$_SESSION['cart'][$n] += $m;
				if (!$_SESSION['cart'])
					$can_i_buy = 0;
				if ($can_i_buy === 1)
					echo "<a href='validate.php' target='_self'><button> Validate order </button></a>";
				else
					echo "<a disabled href='validate.php' target='_self'><button disabled> Validate order </button></a>";
				?>
			</div>
		</div>
	</body>
</html>