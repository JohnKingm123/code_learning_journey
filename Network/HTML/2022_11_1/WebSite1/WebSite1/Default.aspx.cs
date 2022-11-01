using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
   

    protected void Check_ID(object source, ServerValidateEventArgs args) {
        string strID = args.Value;
        args.IsValid = true;
        try {

            DateTime.Parse(strID.Substring(6, 4) + "-" + strID.Substring(10, 2)+ "-" + strID.Substring(12, 2));
        
        }
        catch {

            args.IsValid=false;
        
        }
    
    
    
    }
    protected void Click_Button(object sender, EventArgs e)
    {
        Msg.Text = "";
        if (Page.IsValid) {

            Msg.Text = "验证通过";


        }


    }

}