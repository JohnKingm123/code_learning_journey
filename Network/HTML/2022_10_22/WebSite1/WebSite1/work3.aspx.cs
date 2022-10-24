using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    

    protected void pr(object sender,EventArgs e) {

        Checked_A();
        Checked_B();
        Checked_C();
        Checked_D();


    }

    protected void Checked_A() {
        if (RB1.Checked)
        { Label1.Text = "选择A"; }

    }
    protected void Checked_B() {
        if (RB2.Checked)
        { Label1.Text = "选择B"; }

    }
    protected void Checked_C() {
        if (RB3.Checked)
        { Label1.Text = "选择C"; }

    }
    protected void Checked_D() {
        if (RB4.Checked)
        { Label1.Text = "选择D"; }

    }


}