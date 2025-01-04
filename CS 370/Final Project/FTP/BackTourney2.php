<?php


// Create connection #servername, username, password, db 
$conn = mysqli_connect("localhost", "root", "","FreeToPlay");
// Check connection
if (!$conn) {
   die("Connection failed: " . mysqli_connect_error());
}

$sql = "CREATE VIEW PLAYER AS SELECT Player_Name, Seed, Round, Date, Hour, Minute From player NATURAL JOIN matches ON player.M_ID = matches.M_ID";


$sql = "SELECT Round, Date, Hour, Minute FROM matches";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo "round:" . $row["Round"]. " date:" . $row["Date"]. " Match Time:" . $row["Hour"]. ":" . $row["Minute"]. "<br>";
  }
} else {
  echo "0 results <br>";
}


$sql = "SELECT Player_Name, Seed, P_ID FROM player";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo "Player ID:" . $row["P_ID"]. " Player Name:" . $row["Player_Name"]. " Player Seed:" . $row["Seed"]. "<br>";
  }
} else {
  echo "0 results <br>";
}

$conn->close();

?>