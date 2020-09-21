<?php

function isMobileDevice() {
	return preg_match("/(android|avantgo|blackberry|bolt|boost|cricket|docomo|fone|hiptop|mini|mobi|palm|phone|pie|tablet|up\.browser|up\.link|webos|wos)/i", $_SERVER["HTTP_USER_AGENT"]);
}

$dir = "public/images/gifs/";
if (isMobileDevice())
	$dir .= "mobile/";

$files = glob("$dir*.gif");
$age = date_diff(date_create("1998-12-22"), date_create())->y;


?><!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<title>PHP</title>
		Hello, today is <?php echo date('l, F jS, Y'); ?>.

		<meta property="og:type" content="website">
	</head>
	<body class="bg">
		<main>
			<header>
					PHP TEST
					
				</header>

			<div id="sections">
				<section order="0,0,0">
					<h2>Hello, I am Luis Angel Marcias de la Cruz tercero de los angeles caidos</h2>
				
				</section>

			
	</div>

		</main>
		<script type="text/javascript">
			const wallpapers = <?= json_encode($files) ?>;
		</script>
		<script type="text/javascript" src="public/js/main.js"></script>
	</body>
</html>
