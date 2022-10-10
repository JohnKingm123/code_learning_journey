<%@ Page Language="C#" AutoEventWireup="true" CodeFile="work4.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
<style>
    .T {
    font-family:STSong;
    text-decoration:none;
    font-style:normal;
    font-weight:normal;
    }
</style>




</head>
<body>



    <input id="B" type="checkbox" />粗体
    <input id="I" type="checkbox" />斜体
    <input id="U" type="checkbox" />下划线
    <br />
    <input id="1" type ="radio" name ="fm" checked="checked"/>宋体
    <input id="2" type ="radio" name ="fm" />楷体
    <input id="3" type ="radio" name ="fm" />黑体
    <br />

    <p id="T" >Hello World!你好:D</p>



    <script>

        var B = document.getElementById("B");
        var I = document.getElementById("I");
        var U = document.getElementById("U");
        var X = document.getElementById("1");
        var Y = document.getElementById("2");
        var Z = document.getElementById("3");

        var T = document.getElementById("T");

        X.onclick = function () {
            T.style.fontFamily="STSong"
        }
        Y.onclick = function () {
            T.style.fontFamily = "STKaiTi"
        }
        Z.onclick = function () {
            T.style.fontFamily = "SimHei"
        }

        B.onclick = function () {
            if (B.checked) { T.style.fontWeight = "bolder"; }
            else { T.style.fontWeight = "normal"; }  
        }
        U.onclick = function () {
            if (U.checked) { T.style.textDecoration = "underline"; }
            else { T.style.textDecoration = "none"; }
        }
        I.onclick = function () {
            if (I.checked) { T.style.fontStyle = "italic"; }
            else { T.style.fontStyle = "normal"; }
        }

    </script>


</body>
</html>
