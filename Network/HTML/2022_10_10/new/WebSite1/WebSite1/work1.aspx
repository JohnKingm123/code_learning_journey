<%@ Page Language="C#" AutoEventWireup="true" CodeFile="work1.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
  <style>
      .dropdown {
      position:relative;
      display:inline-block;
      }

      .dropdown-content {
       display: none;
       position: absolute;

      }
      .dropdown:hover .dropdown-content {
         display: block;
       }
  </style>

    <div class = "dropdown">
        <span>主菜单1</span>
        <div class ="dropdown-content">
            <ul type ="disc">
                <li>item1</li>
                <li>item2</li>
                <li>item3</li>
                <li>item4</li>
            </ul>


        </div>




    </div>

  
</body>
</html>
