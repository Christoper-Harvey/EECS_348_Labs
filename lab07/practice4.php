<html>
<body>

Your input is: <?php echo $_POST["size"]; ?><br>

<?php 

$input = $_POST["size"];

$totalString = "<table border='l' id='table'>";

for($i=1; $i<$input+1; $i++){

    $row = "<tr>";

    for($j=1; $j<$input+1; $j++){

        $mul = $i*$j;

        $row = $row."<td>$mul</td>";
    
    }

    $row = $row."</tr>";

    $totalString = $totalString.$row;

} 

$totalString."</table>";

echo($totalString);

?>

</body>
</html>

