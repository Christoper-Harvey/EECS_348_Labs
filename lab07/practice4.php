<html>
<body>

Your input is: <?php echo $_GET["size"]; ?><br>

<table border='l'><tr><td></td></tr></table>

<?php for($i=0; $i<$_GET["size"]; $i++){

    echo($i);

} ?>

</body>
</html>



<!-- <table border=1><tr><td></td><td>1</td><td>2</td><td>3</td><td>4</td><td>5</td></tr><tr><td>1</td><td>1</td><td>2</td><td>3</td><td>4</td><td>5</td></tr><tr><td>2</td><td>2</td><td>4</td><td>6</td><td>8</td><td>10</td></tr><tr><td>3</td><td>3</td><td>6</td><td>9</td><td>12</td><td>15</td></tr><tr><td>4</td><td>4</td><td>8</td><td>12</td><td>16</td><td>20</td></tr><tr><td>5</td><td>5</td><td>10</td><td>15</td><td>20</td><td>25</td></tr> -->