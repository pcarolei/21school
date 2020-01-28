const videoPlayer = document.querySelector('#player');
const canvasElement = document.querySelector('#canvas');
const captureButton = document.querySelector('#capture-btn');
const sendButton = document.querySelector('#send-btn');
const imagePicker = document.querySelector('#image-picker');
const imagePickerArea = document.querySelector('#pick-image');
const newImages = document.querySelector('#newImages');

// Image dimensions
const width = 250;
const height = 250;
let	zIndex = 1;
//	
let	checkedBox = "1";

checkboxManager = (id) =>
{
	if ((document.getElementById('opt1').checked == true) ||
		(document.getElementById('opt2').checked == true) ||
		(document.getElementById('opt3').checked == true))
		isChecked = true;
	else
	{
		console.log("FALSE FALSE!");
		isChecked = false;
	}
	document.getElementById('send-btn').disabled = !isChecked;
	if (isChecked)
	{
		if (id != "opt1")
			document.getElementById('opt1').checked = !isChecked;
		if (id != "opt2")
			document.getElementById('opt2').checked = !isChecked;
		if (id != "opt3")
			document.getElementById('opt3').checked = !isChecked;
	}
	checkedBox = id[3];
}

window.addEventListener("load", (event) => startMedia());
const startMedia = () =>
{
	if (!('mediaDevices' in navigator))
    	navigator.mediaDevices = {};
	if (!('getUserMedia' in navigator.mediaDevices))
	{
		navigator.mediaDevices.getUserMedia = (constraints) =>
		{
			const getUserMedia = navigator.webkitGetUserMedia || navigator.mozGetUserMedia;
			if (!getUserMedia)
          		return Promise.reject(new Error('getUserMedia is not supported'));
			else
				return new Promise((resolve, reject) => getUserMedia.call(navigator, constraints, resolve, reject));
    	};
	}

  	navigator.mediaDevices.getUserMedia({video: true})
	.then((stream) =>
	{
		videoPlayer.srcObject = stream;
		videoPlayer.style.display = 'block';
		imagePickerArea.style.display = 'block';
    })
	.catch((err) =>
	{
		imagePickerArea.style.display = 'block';
  	});
};

imagePicker.addEventListener('change', (event) =>
{
	// videoPlayer.style.visibility = 'hidden';
	canvasElement.style.display = 'block';
	const context = canvasElement.getContext('2d');
	var reader = new FileReader();
	reader.onload = (event) => 
	{
		var img = new Image();
		img.onload = () => context.drawImage(img, 0, 0, canvas.width, canvas.height);
		img.src = event.target.result;
	}
	reader.readAsDataURL(event.target.files[0]);
});

captureButton.addEventListener('click', (event) =>
{
	canvasElement.style.display = 'block';
	const context = canvasElement.getContext('2d');
	context.drawImage(videoPlayer, 0, 0, canvas.width, canvas.height);
	// videoPlayer.srcObject.getVideoTracks().forEach((track) => {
    	// track.stop(); 
  	// });
	// videoPlayer.style.visibility = 'hidden';
});

deleteImage = (filename) => {
	const xhr = new XMLHttpRequest();
	xhr.open('POST', '/Create/delete');
	xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	const data = "filename=" + filename;
	xhr.send(data);
	let thumb = document.getElementById(filename);
	thumb.remove();
};

sendButton.addEventListener('click', (event) =>
{
	let picture = canvasElement.toDataURL('image/png');
	const xhr = new XMLHttpRequest();
	xhr.open('POST', '/Create/create');
	xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	xhr.onreadystatechange = function() {
		if ((this.readyState == 4) && (this.status == 200))
		{
			new_thumb = document.createElement("img");
			document.getElementById("thumbnail_root").appendChild(new_thumb);
			new_thumb.setAttribute("src", this.response);
			new_thumb.setAttribute("id", this.response);
			new_thumb.setAttribute("onClick", `deleteImage("${this.response}")`);
		}
	}
	const data = "superposable=" + checkedBox + "&image=" + picture;
	xhr.send(data);
});

const createImage = (src, alt, title, width, height, className) =>
{
    let newImg = document.createElement("img");

    if(src !== null)       newImg.setAttribute("src", src);
    if(alt !== null)       newImg.setAttribute("alt", alt);
    if(title !== null)     newImg.setAttribute("title", title);
    if(width !== null)     newImg.setAttribute("width", width);
    if(height !== null)    newImg.setAttribute("height", height);
    if(className !== null) newImg.setAttribute("class", className);

    return newImg;
}
