<%@ Page Language="C#" AutoEventWireup="true" CodeFile="work1.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
        
  
        <span>简易计算器</span>
        <p>
            <asp:TextBox ID="T1" runat="server" style="margin-bottom: 0px"></asp:TextBox>
        </p>
        <p>
            <asp:Button ID="B1" runat="server" Text="1"  OnClick ="CB1"/>
            <asp:Button ID="B2" runat="server" Text="2" OnClick ="CB2"/>
            <asp:Button ID="B3" runat="server" Text="3" OnClick ="CB3" />
            <asp:Button ID="BC" runat="server" Text="C" OnClick ="CBC"/>
            <br />
            <asp:Button ID="B4" runat="server" Text="+" OnClick ="CB_P"/>
            <asp:Button ID="B5" runat="server" Text="-" OnClick ="CB_D"/>
            <asp:Button ID="B6" runat="server" Text="=" OnClick ="CB_E"/>
        </p>
    
        </div>




    </form>


</body>
</html>
