<%@ Page Language="C#" AutoEventWireup="true" CodeFile="work2.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <div>
     <img id="img" src="./img/1.png" alt="" />
        <br />
    <button type ="button" id = "1">1</button>
        <br />
    <button type ="button" id = "2">2</button>
        <br />
    <button type ="button" id = "3">3</button>
    </div>


    <script type ="text/javascript">
        var A = document.getElementById("1");
        var B = document.getElementById("2");
        var C = document.getElementById("3");
        var img = document.getElementById("img")
        var imgArr = ["./img/1.png", "./img/2.png", "./img/3.png"];


        A.onclick = function () {
            img.src = imgArr[0];
        };
        B.onclick = function () {
            img.src = imgArr[1];
        };
        C.onclick = function () {
            img.src = imgArr[2];
        };
    </script>





</body>



</html>
