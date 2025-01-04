<?php

// Grab User submitted information
$Mid = $_REQUEST["mid"];
$ROUND = $_REQUEST["round"];
$DATE = $_REQUEST["date"];
$HOUR = $_REQUEST["hour"];
$Min = $_REQUEST["minute"];
$MTid = $_REQUEST["mtid"];


// Create connection #servername, username, password, db 
$conn = mysqli_connect("localhost", "root", "","FreeToPlay");
// Check connection
if (!$conn) {
   die("Connection failed: " . mysqli_connect_error());
}
//echo "Connected successfully";

//mysql_select_db("tourney2",$con);

// $username = stripcslashes($username);
// $password = stripcslashes($password);
// $username = mysqli_real_escape_string($conn, $username);
// $password = mysqli_real_escape_string($conn, $password);


$sql = "SELECT T_ID, Tment_name, O_ID FROM tournament";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo "Tournament ID:" . $row["T_ID"]. " Tournament Name:" . $row["Tment_name"]. " Organizer ID:" . $row["O_ID"]. "<br>";
  }
} else {
  echo "0 results";
}
echo "<br>";

$sql = "INSERT INTO matches VALUES 
    ($ROUND, 'undecided', '$DATE', $HOUR, $Min, $Mid, $MTid)";
 
if ($conn->query($sql) === TRUE) {
    echo "record inserted successfully <br>";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}
$sql = "SELECT Round, Date, Hour, Minute, M_ID, T_ID FROM matches";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo "Tournament ID:" . $row["T_ID"]. " Match ID:" . $row["M_ID"]. " round:" . $row["Round"]. " date:" . $row["Date"]. " Match Time:" . $row["Hour"]. ":" . $row["Minute"]. "<br>";
  }
} else {
  echo "0 results";
}
echo "<br>";


$sql = "SELECT Player_Name, Seed, P_ID, T_ID, M_ID FROM player";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo "Tournament ID:" . $row["T_ID"]. " Match ID:" . $row["M_ID"]. " Player ID:" . $row["P_ID"]. " Player Name:" . $row["Player_Name"]. " Player Seed:" . $row["Seed"]. "<br>";
  }
} else {
  echo "0 results";
}
echo "<br>";

$conn->close();

?>