<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            用户名：<asp:TextBox ID="txtName" runat="server"></asp:TextBox>
            <asp:RequiredFieldValidator ID="rfvName" runat="server" ControlToValidate ="txtName" ErrorMessage="请输入用户名"
                setFocusOnError ="true">*</asp:RequiredFieldValidator>
            <br />
            密码：<asp:TextBox ID="txtPW" runat="server"></asp:TextBox>
            <asp:RequiredFieldValidator ID="rfvPW" runat="server" ControlToValidate ="txtPW" ErrorMessage="请输入密码"
                setFocusOnError ="true">*</asp:RequiredFieldValidator>
            <br />
            确认密码：<asp:TextBox ID="txtPWAgain" runat="server"></asp:TextBox>
            <asp:RequiredFieldValidator ID="rfvPWA" runat="server" ControlToValidate ="txtPWAgain" ErrorMessage="请输入一致密码"
                setFocusOnError ="true">*</asp:RequiredFieldValidator>
            <asp:CompareValidator ID="cvPWA" runat="server" 
                ControlToCompare ="txtPW"
                ControlToValidate ="txtPWAgain"
                ErrorMessage="密码不一致"
                setFocusOnError ="true"></asp:CompareValidator>
            <br />
            生日：<asp:TextBox ID="txtBrith" runat="server"></asp:TextBox>
            <br />
            <asp:RequiredFieldValidator ID="rfvBrith" runat="server" ControlToValidate ="txtBrith" ErrorMessage="YYYY-MM-DD"
                setFocusOnError ="true">*</asp:RequiredFieldValidator>
            <asp:RangeValidator ID ="range" runat="server" 
                ControlToValidate ="txtBrith"
                ErrorMessage="1900-1-1到2020-1-1"
                MaximumValue ="2020-1-1"
                MinimumValue ="1900-1-1"
                Type="Date"
                setFocusOnError ="true"
                ></asp:RangeValidator>
            <br />


            电话：<asp:TextBox ID="txtPhone" runat="server"></asp:TextBox>
            <asp:RequiredFieldValidator ID="rfvPhone" runat="server" ControlToValidate ="txtPhone" ErrorMessage="XXX-XXXXXXXX"
                setFocusOnError ="true">*</asp:RequiredFieldValidator>
            <asp:RegularExpressionValidator ID ="RegularExpressionValidator1" runat="server"
                ControlToValidate ="txtPhone"
                ErrorMessage="YYYY-MM-DD"
                setFocusOnError ="true"
                ValidationExpression ="\d{3}-\{8}"
                ></asp:RegularExpressionValidator>

            <br />
            身份证：<asp:TextBox ID="txtID" runat="server"></asp:TextBox>
             <asp:RequiredFieldValidator ID="rfvID" runat="server" ControlToValidate ="txtID" ErrorMessage="身份证号请输入"
                setFocusOnError ="true">*</asp:RequiredFieldValidator>
            <asp:CustomValidator ID="cvID" runat ="server"
                ControlToValidate ="txtID" ErrorMessage="错误的身份证号"
                OnServerValidate ="Check_ID" SetFocusOnError="true"></asp:CustomValidator>
            <br />
            <asp:Button ID="Button1" runat="server" Text="Button"  OnClick="Click_Button"/>
            <br />
            <asp:ValidationSummary ID="vaSummary" runat="server"
                ShowMessageBox ="true" ShowSummary ="false" />
            <asp:Label ID="Msg" runat="server" Text=""></asp:Label>
            <br />

        </div>
    </form>
</body>
</html>
