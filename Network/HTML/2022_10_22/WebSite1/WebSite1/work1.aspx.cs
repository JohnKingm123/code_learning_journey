using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{


    static string Num1 = "0";
    static string Num2 = "0";
    static string sign = "";
    static string sum = "";
   
    protected void Page_Load(object sender, EventArgs e)
    {
        
    }

    protected void CB1 (object sender, EventArgs e){

        sum = "1";
        T1.Text = sum;
    }
    protected void CB2(object sender, EventArgs e)
    {

        sum = "2";
        T1.Text = sum;
    }
    protected void CB3(object sender, EventArgs e)
    {

        sum = "3";
        T1.Text = sum;
    }
    protected void CB_P(object sender, EventArgs e)
    {
        if (sign.Length == 1)
        {
            Count();
            Num1 = T1.Text;
            sign = "+";

        }
        else 
        {
            Num1 = T1.Text;
            T1.Text = "";
            sum = "";
            sign = "+";
        
        
        }
    }
    protected void CB_D(object sender, EventArgs e)
    {
        if (sign.Length == 1)
        {
            Count();
            Num1 = T1.Text;
            sign = "-";

        }
        else
        {
            Num1 = T1.Text;
            T1.Text = "";
            sum = "";
            sign = "-";


        }
    }

    protected void CBC(object sender, EventArgs e)
    {

        Num1 = "0";
        Num2 = "0";
        sign = "";
        sum = "";
        T1.Text = "";
    
    }

    protected void CB_E(object sender, EventArgs e) 
    {
        Count();
 
    }

    protected void Count()
    {
        Num2 = T1.Text;
        if (Num2 == "")
        {
            Num2 = "0";  
        }
        switch (sign)
        {
            case "+":
                T1.Text = (int.Parse(Num1) + int.Parse(Num2)).ToString();
                Num1 = "0";
                Num2 = "0";
                sign = "";
                sum = "";
                
                break;
            case "-":
                T1.Text = (int.Parse(Num1) - int.Parse(Num2)).ToString();
                Num1 = "0";
                Num2 = "0";
                sign = "";
                sum = "";
                break;        
        }


    }



}