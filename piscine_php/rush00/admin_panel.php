<?PHP
function get_all_users()
{
	$users = array();
	$fd = fopen("users.csv", "r");
	while (($user = fgetcsv($fd, 1000, ";")) !== false)
		array_push($users, $user[0]);
	fclose($fd);
	return ($users);
}
function get_all_items()
{
	$items = array();
	$fd = fopen("items.csv", "r");
	while (($item = fgetcsv($fd, 1000, ";")) !== false)
		array_push($items, $item);
	fclose($fd);
	return ($items);
}
function get_all_orders()
{
	$orders = array();
	$fd = fopen("orders.csv", "r");
	while (($order = fgetcsv($fd, 1000, ";")) !== false)
		array_push($orders, $order);
	fclose($fd);
	return ($orders);
}
session_start();
//var_dump($_SESSION);
if ($_SESSION["access_rights"] == "user")
{
	echo "<script>window.location = '/cart.php' </script>";
	exit();
}
$users = get_all_users();
foreach ($users as $user)
{
	if ($user === "login" || $user === $_SESSION["logged_in_user"])
		continue;
	echo "<div style='width: 100px'>$user</div>";
	echo "<a target='_self' href='/delete_user.php?login=$user''>";
	echo "<button>Delete</button>";
	echo "</a>";
	echo "<br/>";
	echo "<br/>";
}
echo "
<h3>create user</h3>
<form action='create_user.php' method='POST'>
<input
	type='text'
	name='login'
	placeholder='enter login'
	value=''
/>
<input
	type='password'
	name='passwd'
	placeholder='enter password'
	value=''
/>
<input
	type='hidden'
	name='admin'
	value='admin'
/>
<input type='submit' name='submit' value='OK'/>
</form>";

$items = get_all_items();
foreach ($items as $item)
{
	if ($item[0] == "category")
		continue;
	echo "category = $item[0]";
	echo "<br/>";
	echo "name = $item[1]";
	echo "<br/>";
	echo "quantity = $item[2]";
	echo "<br/>";
	echo "price = $item[3]";
	echo "<br/>";
	echo "img_file = $item[4]";
	$name = $item[0];
	echo "<br/>";
	echo "<a target='_self' href='/delete_item.php?name=$name'>";
	echo "<button>Delete</button>";
	echo "</a>";
	echo "<br/>";
	echo "
	<form action='modify_item.php' method='POST'>
	<h5>modify item</h5>
	<input
		name='category'
		value=''
		placeholder='category'
	/>
	<input
		type='hidden'
		name='oldname'
		value='$name'
		placeholder='old name'
	/>
	<input
		name='newname'
		value=''
		placeholder='new name'
	/>
	<input
		name='quantity'
		value=''
		placeholder='quantity'
	/>
	<input
		name='price'
		value=''
		placeholder='price'
	/>
	<input
		name='img_file'
		value=''
		placeholder='img_file'
	/>
	<input
		type='hidden'
		name='admin'
		value='admin'
	/>
	<input type='submit' name='submit' value='OK'/>
	</form>";
	echo "<br/>";
	echo "<br/>";
	echo "<br/>";
	echo "<br/>";
	echo "<br/>";
	echo "<br/>";
	echo "<br/>";
}

echo "
<h3>create item</h3>
<form action='create_item.php' method='POST'>
<input
	name='category'
	value=''
	placeholder='category'
/>
<input
	name='name'
	value=''
	placeholder='name'
/>
<input
	name='quantity'
	value=''
	placeholder='quantity'
/>
<input
	name='price'
	value=''
	placeholder='price'
/>
<input
	name='img_file'
	value=''
	placeholder='img_file'
/>
<input
	type='hidden'
	name='admin'
	value='admin'
/>
<input type='submit' name='submit' value='OK'/>
</form>";

echo "<h3> ORDERS </h3>";
$orders = get_all_orders();
foreach ($orders as $order)
{
	$lg = $order[0]; //login
	$od = $order[1]; //order itself
	print_r($lg);
	print_r($od);
	if ($order[0] === "login")
		continue;
	echo "<div style='width: 100px'>who ordered: $order[0]</div>";
	echo "<div style='width: 100px'>order: $order[1]</div>";
	echo "<form id='form' method='POST' action='delete_order.php'>";
	echo "<input type='hidden' value=$lg name='login'/>";
	echo "<input type='hidden' value=$od name='order'/>";
	echo "<button name='submit' type='submit' value='OK'>Delete</button>";
	echo "</form>";
	echo "<br/>";
	echo "<br/>";
}

?>
