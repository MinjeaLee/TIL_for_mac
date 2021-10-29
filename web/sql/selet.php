<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ªÔªœ≈ÿ sql Ω∫≈Õµ</title>
</head>
<body>
    <?php
        $conn = mysqli_connect(
        'localhost',
        'root',
        '111111',
        'opentutorials');
        echo "<h1>single row</h1>";
        $sql = "SELECT * FROM topic WHERE id = 19";
        $result = mysqli_query($conn, $sql);
        $row = mysqli_fetch_array($result);
        echo '<h2>'.$row['title'].'</h2>';
        echo $row['description'];
        echo "<h1>multi row</h1>";
        $sql = "SELECT * FROM topic";
        $result = mysqli_query($conn, $sql);
        while($row = mysqli_fetch_array($result)) {
        echo '<h2>'.$row['title'].'</h2>';
        echo $row['description'];
        }
    ?>
</body>
</html>