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
        if (!IsPostBack) 
        {
            BindYear();
            BindTerm();
            BindCollege();
            BindTeacher();
        }
    }

    protected void BindYear() {
        Year.Items.Clear();
        int start = DateTime.Now.Year - 10;
        int end = DateTime.Now.Year;
        for (int i = start+1; i <= end; i++) {

            Year.Items.Add(new ListItem((i - 1).ToString() + "-" + i.ToString()));

        }
    
    }
    protected void BindTerm() {
        Term.Items.Clear();
        int i = 1;
        for (;i<=2;i++) {
            Term.Items.Add(new ListItem(i.ToString()));
        }
    
    }
    protected void BindCollege() {
        College.Items.Clear();
        College.Items.Add(new ListItem("计算机学院"));
        College.Items.Add(new ListItem("外国语学院"));
        College.Items.Add(new ListItem("机电学院"));
    }

    protected void CollegeEx(object sender ,EventArgs e) {
        BindTeacher();
    }
    
    
    
    protected void BindTeacher() {
        Teacher.Items.Clear();
        switch (College.SelectedValue) {
            case "计算机学院":
                Teacher.Items.Add(new ListItem("张三"));
                Teacher.Items.Add(new ListItem("李四"));
                Teacher.Items.Add(new ListItem("王五"));
                break;

            case "外国语学院" :
                Teacher.Items.Add(new ListItem("Alice"));
                Teacher.Items.Add(new ListItem("Peter"));

                break;

            case "机电学院":
                Teacher.Items.Add(new ListItem("马里欧"));
                Teacher.Items.Add(new ListItem("路易吉"));
                break;
       
        }
    
    }



}
