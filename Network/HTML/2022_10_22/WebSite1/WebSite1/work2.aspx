<%@ Page Language="C#" AutoEventWireup="true" CodeFile="work2.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        
        <div>
            <asp:Label ID="LYear" runat="server" Text="学年:"></asp:Label>
            <asp:DropDownList ID="Year" runat="server"  AutoPostBack="True">
            </asp:DropDownList>
            <asp:Label ID="LTerm" runat="server" Text="学期:" ></asp:Label>
            <asp:DropDownList ID="Term" runat="server"  AutoPostBack="True">
            </asp:DropDownList>
            <asp:Label ID="LCollege" runat="server" Text="分院:"></asp:Label>
            <asp:DropDownList ID="College" runat="server" OnSelectedIndexChanged="CollegeEx" AutoPostBack="True" >
            </asp:DropDownList>
            <asp:Label ID="LTeacher" runat="server" Text="教师:"></asp:Label>
            <asp:DropDownList ID="Teacher" runat="server"  AutoPostBack="True">
            </asp:DropDownList>
            

        </div>
    </form>
</body>
</html>
