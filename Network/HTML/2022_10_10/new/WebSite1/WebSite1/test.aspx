<%@ Page Language="C#" AutoEventWireup="true" CodeFile="test.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
     <select id="pid" onchange="gradeChange()">
        <option value="1">选项一</option>
        <option value="2">选项二</option>
    </select>

    <script type="text/JavaScript">
        function gradeChange() {
            var objS = document.getElementById("pid");
            var grade = objS.options[objS.selectedIndex].value;
            alert(grade);
        }
    </script>
</body>
</html>
