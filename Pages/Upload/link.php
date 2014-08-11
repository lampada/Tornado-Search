<?php
header("Content-Type:text/html;charset=utf-8"); 
$con = mysql_connect(SAE_MYSQL_HOST_M.':'.SAE_MYSQL_PORT,SAE_MYSQL_USER,SAE_MYSQL_PASS); 

mysql_select_db("app_***", $con); 
$sql = "CREATE TABLE results (
FirstName varchar(15), 
LastName varchar(15), 
Age int 
)"; 
mysql_query($sql,$con); 
?>