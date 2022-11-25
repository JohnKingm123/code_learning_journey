<script>
</script>


<template >
   <div> 
    <div>
        <label>您选择的项目是：</label>
    </div>
    <div>
        
        <ol>
            <li>血压</li>
            <li>核酸</li><!--需要动态生成列表-->
        </ol><br>
        总费用：<p id="total">20元</p><!--由项目单价累加-->



       
    
    
    <p id="Date">2022-11-3</p><!--需要日期根据上一张选择-->


    </div>
</div>
</template>


<style>
p, li {
  font-size: 16px;
  line-height: 2;
  letter-spacing: 1px;
}


table {
  margin-top:10px;
  height: fit-content;
  width: 100%;
  
  

}

th{
  font-size: 20px;
  text-align: center;
  background-color: #d3d3d3;
}

td{
  text-align: right;   
  border-bottom: 5px solid rgb(246, 255, 245);
  background-color: #d3d3d3;
  border-right: 5px solid rgb(246, 255, 245);
}


div {

  width: 90%;
  margin: 50px auto;
  text-align: right;
  background-color: #add4bc;
  padding: 0 20px 20px 20px;
  border: 5px solid rgb(148, 148, 148);
  height:100%;
}

</style>


<!--<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<link rel="stylesheet" type="text/css" href="./styles/style.css">
<title>服务项目订单递交</title>
</head>
<body>
    <h1>
        医·屋健康管理系统
        
        </h1>

    <h2>您选择的项目是：</h2>
<div>
    <div>
        <ol>
            <li>血压</li>
            <li>核酸</li><!--需要动态生成列表-->
        </ol><br>
        总费用：<p id="total">20元</p><!--由项目单价累加-->



    </div>
    
    
    <p id="Date">2022-11-3</p><!--需要日期根据上一张选择-->


</div>
<div>
    <!--返回选择界面-->
    <button id="B_commit">确认</button>


</div>

<footer>
    芝士小组出品
    </footer>

</body>
</html>
-->