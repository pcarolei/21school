var	list = [];
restore();
function get_data()
{
	return ($.get(
		"select.php",
		function(resp)
		{
			data = resp;
		}
	))
}
function restore()
{
	let d_data;
	let data = get_data();
	$.when(data).done(data => {
		console.log(data);
		let arr = data.split(";");
		console.log(arr);
		for (elem in arr)
		{
			if (arr[elem] == "")
				continue;
			let str = arr[elem].split("=");
			let id = str[0];
			let text = str[1];
			//console.log("id = ", id, "text = ", text);
			old_elem(id, text);
		}
	});
}
function next_id()
{
	let max = get_max();
	if (list.length == 0)
		return (0);
	let id;
	id = parseInt(max) + 1;
	console.log("max = ", max, "id = ", id);
	return (id);
}
function get_max()
{
	let max;

	max = 0;
	for (i = 0; i < list.length; i++)
	{
		if (list[i] > max)
			max = list[i];
	}
	return (max);
}
function insertAfter(newNode, referenceNode, parentNode)
{
	referenceNode.parentNode.insertBefore(newNode, referenceNode.nextSibling);
	//referenceNode.parentNode.insertBefore(newNode, referenceNode.nextSibling);
}
function old_elem(id, text)
{
	if (text === undefined)
		return ;
	cur_id = parseInt(id);
	//let span = document.createElement("li");
	//span.innerHTML = text;
	let span = $("<li></li>").text(text);
	//let first = document.getElementById("first");
	//let root = document.getElementById("ft_list");
	root = $("#ft_list")[0];
	$(root).prepend(span);
	//insertAfter(span, first, root);
	//span.setAttribute("id", cur_id);
	$(span).attr("id", cur_id);
	//span.setAttribute("onclick", "remove(".concat(cur_id, ")"));
	$(span).attr("onclick", "remove(".concat(cur_id, ")"));
	let name = "".concat("name_", cur_id);
	list.push(cur_id);
}

function new_elem(id, text)
{
	console.log("NEW ELEM ------------------");
	for (property in list)
		console.log(JSON.stringify(list[property]));
	let flag = false;
	if (!text)
	{
		flag = true;
		text = prompt("");
		if (text === "")
			return ;
	}
	if (!id)
		cur_id = next_id();
	else
		cur_id = parseInt(id);
	//let span = document.createElement("li");
	//span.innerHTML = text;
	let span = $("<li></li>").text(text);
	let first;
	//console.log("cur_id = ", cur_id);
	if (cur_id === 0)
	{
		//first = document.getElementById("first");
		first = $("#first")[0];
		console.dir(first);
	}
	else
	{
	//	console.log("list = ", list);
		//max = Math.max(...list);
		max = get_max();
		max = "" + max;
		//first = document.getElementById(max);
		first = $("#first")[0];
	//	console.log("max = ", max);
		//console.dir("first = ", first);
	}
	//let root = document.getElementById("ft_list");
	let root = $("#ft_list")[0];
	//let new_e = root.insertBefore(span, first);
	$(root).prepend(span);
	//span.setAttribute("id", cur_id);
	$(span).attr("id", cur_id);
	//span.setAttribute("onclick", "remove(".concat(cur_id, ")"));
	$(span).attr("onclick", "remove(".concat(cur_id, ")"));

	//console.log(document.cookie);
	//console.log("id = ", cur_id);
	let name = "".concat("name_", cur_id);
	//console.log("name = ", name);
	list.push(cur_id);
	if (flag === true)
		setCookie(name, text, {});
	$.post(
		"insert.php",
		{
			"id": cur_id, 
			"text": text
		},
		function(result) {
		}
	);
}
function remove(id)
{
	if (!confirm('Are you sure you want to delete this elem?'))
		return ;
	//let elem = document.getElementById(id);
	let elem = $("#" + id)[0];
	//let root = document.getElementById("ft_list");
	let root = $("#ft_list");
	//root.removeChild(elem);
	$(elem).remove();
	//let index = list.indexOf(id);
	//console.log("index = ", index);
	//let name = "".concat("name_", id);
	//deleteCookie(name);
	//if (index > -1)
		//list.splice(index, 1);
	return ($.get(
		"delete.php", {"id": id}
	))
}
function getCookie(name)
{
	let matches = document.cookie.match(new RegExp(
    	"(?:^|; )" + name.replace(/([\.$?*|{}\(\)\[\]\\\/\+^])/g, '\\$1') + "=([^;]*)"
  	));
	//return (matches ? decodeURIComponent(matches) : undefined);
	return (matches ? matches : undefined);
}
function setCookie(name, value, options)
{
	let updatedCookie = encodeURIComponent(name) + "=" + encodeURIComponent(value);
	for (let optionKey in options)
	{
		updatedCookie += "; " + optionKey;
		let optionValue = options[optionKey];
		if (optionValue !== true)
		{
			updatedCookie += "=" + optionValue;
		}
	}
	document.cookie = updatedCookie;
}
function deleteCookie(name)
{
	options = {"max-age": -1};
	setCookie(name, "", options);
}
