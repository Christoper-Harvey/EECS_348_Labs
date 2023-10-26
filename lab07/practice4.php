<html>
<body>

<!-- notify user of input for sanity check and because I think it looks nice. -->
Your input is: <?php echo $_POST["size"]; ?><br>

<?php 

// grab input size to create table.
$input = $_POST["size"];

// I use a string to output all of the data as it is incredibly fast and easy.
// I don't include the outer edge cases of the multiplication on purpose. Everything multiplied by 1 is 1 so I feel like it is extremly redundant and looks bad.
// So I made it only print out the "labels" for each axis. The axis's are of course also themselves multiplied by 1.

// init the starting string.
$totalString = "<table border='l' id='table'>";

// double loop through input to create a NxN matrix. First loop controlls rows.
for($i=1; $i<$input+1; $i++){

    // start a row using the html table row tag.
    $row = "<tr>";

    // second loop controlls columns.
    for($j=1; $j<$input+1; $j++){

        // get the intermitten result. I only did this as when I tried this in the row string I got an error and didn't want to troubleshoot. I'm sure you can one line this.
        $mul = $i*$j;
        // concatenate string with current row output.
        $row = $row."<td>$mul</td>";
    
    }
    // end row with the closing html tr tag. This makes it a valid row.
    $row = $row."</tr>";
    // concatenate it with total output. After all the loops we will have an almost complete table.
    $totalString = $totalString.$row;

} 
// complete the table by closing the table tag.
$totalString."</table>";

// print the result to screen. PHP/HTML automatically converts the string to valid HTML code and we get to see the table being outputted.
echo($totalString);

?>

</body>
</html>

