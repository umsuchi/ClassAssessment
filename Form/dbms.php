<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "umsuchi";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} else {
    echo "Connected successfully";
}

$Name = $_POST['name'];
$SerialNo = $_POST['serial_no'];
$Age = $_POST['age'];
$Gender = $_POST['gender'];
$Contact = $_POST['contact'];
$sql = "INSERT INTO patient_info (name, serial_no, age, gender, contact) 
VALUES ('$Name', '$SerialNo', '$Age', '$Gender', '$Contact')";

if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>