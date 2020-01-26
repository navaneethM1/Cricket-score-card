<html>
<head>
	<title>C Project</title>
</head>
<style type="text/css">
	
	h1{
		font-size: 40px;
		text-align: center;
	}
	caption{
		font-size: 35px;
	}
	table{
		margin-left:130px;
		float: left;
		border:solid;
		border-collapse: collapse;
	}
	th{
		font-size: 30px;
		border: solid;
	}
	td{
		border: solid;
		padding:70;
		font-size: 25px;
	}
</style>
<body bgcolor="#add8e6">
	
	<h1>Cricket Score Card</h1>



	<table>
	<caption><b>Batting Team</b></caption>
	<tr>
	<th>Batsman</th>
	<th>Runs</th>
	<th>Balls</th>
	</tr>
	
	<?php
		$myfile = fopen("score.txt","r");
		fgets($myfile);
		$bat1 = fgets($myfile);
		$bat1 = explode(" ", $bat1);
		$bat2 = fgets($myfile);
		$bat2 = explode(" ", $bat2);
		$bat3 = fgets($myfile);
		$bat3 = explode(" ", $bat3);
		$bow1 = fgets($myfile);
		$bow1 = explode(" ", $bow1);
		$bow2 = fgets($myfile);
		$bow2 = explode(" ", $bow2);
		$bow3 = fgets($myfile);
		$bow3 = explode(" ", $bow3);

		
	print "<tr>";
	print "<td>$bat1[0]</td>";print "<td>$bat1[1]</td>";print "<td>$bat1[2]</td>";
	print "</tr>";
	print "<tr>";
	print "<td>$bat2[0]</td>";print "<td>$bat2[1]</td>";print "<td>$bat2[2]</td>";
	print "</tr>";
	print "<tr>";
	print "<td>$bat3[0]</td>";print "<td>$bat3[1]</td>";print "<td>$bat3[2]</td>";
	print "</tr>";
	?>
	</table>
		<div>
<table>
	<caption><b>Bowling Team</b></caption>
	<tr>
	<th>Bowler</th>
	<th>Runs</th>
	<th>Wicket</th>
	<th>Overs</th>
	</tr>
	
	<?php
		$myfile = fopen("score.txt","r");
		fgets($myfile);
		$bat1 = fgets($myfile);
		$bat1 = explode(" ", $bat1);
		$bat2 = fgets($myfile);
		$bat2 = explode(" ", $bat2);
		$bat3 = fgets($myfile);
		$bat3 = explode(" ", $bat3);
		$bow1 = fgets($myfile);
		$bow1 = explode(" ", $bow1);
		$bow2 = fgets($myfile);
		$bow2 = explode(" ", $bow2);
		$bow3 = fgets($myfile);
		$bow3 = explode(" ", $bow3);
		
		
	print "<tr>";
	print "<td>$bow1[0]</td>";print "<td>$bow1[1]</td>";print "<td>$bow1[2]</td>";print "<td>$bow1[3]</td>";
	print "</tr>";
	print "<tr>";
	print "<td>$bow2[0]</td>";print "<td>$bow2[1]</td>";print "<td>$bow2[2]</td>";print "<td>$bow2[3]</td>";
	print "</tr>";
	print "<tr>";
	print "<td>$bow3[0]</td>";print "<td>$bow3[1]</td>";print "<td>$bow3[2]</td>";print "<td>$bow3[3]</td>";
	print "</tr>";
	?>
	</table>

</div>

<?php
		$myfile = fopen("score.txt","r");
		$ts = fgets($myfile);
		print "<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>";
		print "<h1>Total Score : $ts</h1>";
		?>
	
</body>
</html>