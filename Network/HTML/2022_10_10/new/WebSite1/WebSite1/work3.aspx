<%@ Page Language="C#" AutoEventWireup="true" CodeFile="work3.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>



</head>
<body>
    <div>
        <img src="./img/1.png" alt="" />
        <button type ="button" id = "last"><</button>
        <button type ="button" id = "next">></button>
    </div>

        <script type ="text/javascript">
            var last = document.getElementById("last");
            var next = document.getElementById("next");
            var img = document.getElementsByTagName("img")[0];
            //img标签
            var imgArr = ["./img/1.png", "./img/2.png", "./img/3.png"];
            //图片路径
            var index = 0;
            //索引

            next.onclick = function () {
                index++;
                if (index > imgArr.length - 1) { index = 0; }
                img.src = imgArr[index];
            };

            last.onclick = function () {
                index--;
                if (index < 0) { index = img.length - 1; }
                img.src = imgArr[index];
            };

        </script>
</body>
</html>
