<!doctype html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Web app that takes pictures</title>
    <link rel="stylesheet" href="public/css/webcam_display.css">
	</head>
<body>
<div id="newImages"></div>
<video id="player" autoplay></video>
<canvas id="canvas" width="250px" height="250px"></canvas>
<button class="btn btn-primary" id="capture-btn">Capture</button>
<button class="btn btn-primary" id="send-btn">Send</button>
<div id="pick-image">
	<input type="file" accept="image/*" id="image-picker">
</div>
<script src="public/js/webcam_display.js"></script>
</body>
</html>
