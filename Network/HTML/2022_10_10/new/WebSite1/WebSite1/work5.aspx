<%@ Page Language="C#" AutoEventWireup="true" CodeFile="work5.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
   



</head>
<body>
    <div class ="test">
        <select id="S" name="Sl" onchange="gradeChange()">
            <option value="0">0</option>
            <option value="1">1</option>
            <option value="2">2</option>
            <option value="3">3</option>
            <option value="4">4</option>
            <option value="5">5</option>
        </select>
        <br />
    <p id="tt">打分：</p>
        <p id="T1" color="red" >★</p>
        <p id="T2" >★</p>
        <p id="T3" >★</p>
        <p id="T4" >★</p>
        <p id="T5" >★</p>
        
    </div>
    


     <style>
        
        .test p {
            float:left;
            margin-left:4px;
        }

    </style>


    <script>
        var T0 = document.getElementById("T0");
        var T1 = document.getElementById("T1");
        var T2 = document.getElementById("T2");
        var T3 = document.getElementById("T3");
        var T4 = document.getElementById("T4");
        var T5 = document.getElementById("T5");

       
        var num = document.getElementById("S");
        function gradeChange() {
            
            var grade = num.options[num.selectedIndex].value;

            switch (grade) {
                case "0": T1.style.color = "black";
                    T2.style.color = "black";
                    T3.style.color = "black";
                    T4.style.color = "black";
                    T5.style.color = "black";
                    break;


                case "1": T1.style.color = "red";
                    T2.style.color = "black";
                    T3.style.color = "black";
                    T4.style.color = "black";
                    T5.style.color = "black";
                            

                    break;
                case "2": T1.style.color = "red";
                    T2.style.color = "red";
                    T3.style.color = "black";
                    T4.style.color = "black";
                    T5.style.color = "black";
                    break;
                case "3":
                    T1.style.color = "red";
                    T2.style.color = "red";
                    T3.style.color = "red";
                    T4.style.color = "black";
                    T5.style.color = "black";
                    break;
                case "4":
                    T1.style.color = "red";
                    T2.style.color = "red";
                    T3.style.color = "red";
                    T4.style.color = "red";
                    T5.style.color = "black";
                    break;
                case "5":
                    T1.style.color = "red";
                    T2.style.color = "red";
                    T3.style.color = "red";
                    T4.style.color = "red";
                    T5.style.color = "red";
                    break;



            }



        }





    </script>



</body>
</html>
