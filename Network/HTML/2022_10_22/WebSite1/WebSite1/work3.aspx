<%@ Page Language="C#" AutoEventWireup="true" CodeFile="work3.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>

            <asp:Label ID="L1" runat="server" Text="Web服务器控件不包括（）。"></asp:Label><br />
            <asp:RadioButton ID="RB1" Text ="A.Wizard" runat="server" GroupName="GP1"  /><br />
            <asp:RadioButton ID="RB2" Text ="B.input" runat="server" GroupName="GP1"/><br />
            <asp:RadioButton ID="RB3" Text ="C.AdRotator" runat="server" GroupName="GP1"/><br />
            <asp:RadioButton ID="RB4" Text ="D.Calender" runat="server" GroupName="GP1"/>
            <br />
            <asp:Button ID="Button1" runat="server" Text="确定" OnClick ="pr" />
            <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
        </div>
    </form>
</body>
</html>
