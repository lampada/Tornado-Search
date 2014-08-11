<?php

	# 练习使用php进行操作数据库

	# 连接主数据库, 使用 'host', 'user', 'password'
	$link = mysql_connect(SAE_MYSQL_HOST_M.':'.SAE_MYSQL_PORT, SAE_MYSQL_USER, SAE_MYSQL_PASS);

	if($link){

		# 选择数据库
   	 	mysql_select_db(SAE_MYSQL_DB, $link);
    
    	// your code goes here
        echo "Connect success <br/>\n";
        
        // query array of 0 ~ 30
        $sql = "SELECT * FROM `result` LIMIT 0, 30 ";
        
        $result = mysql_query($sql, $link);
        
        
        /*
        result是一个多维数组,row是多维数组中的一行
        打印一行字段为'url'的数据
        */
        
        while($row =mysql_fetch_array($result)) {
 
        	echo $row['url'];
 
        	echo"<br/>";
 
        }
        
        mysql_close($link);
    	
    }else{
    	die('Could not connect: ' .mysql_error());
    }

?>