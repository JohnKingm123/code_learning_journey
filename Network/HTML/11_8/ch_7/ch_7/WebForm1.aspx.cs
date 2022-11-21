using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace chap_7
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string connectionString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=D:\\Code_Storge\\GitHub_Local\\Network\\HTML\\11_8\\ch_7\\ch_7\\App_Data\\Database1.mdf;Integrated Security=True";
            SqlConnection connection = new SqlConnection(connectionString);
            SqlCommand command = connection.CreateCommand();
            command.CommandText = "select * from S";

            connection.Open();
            SqlDataReader dr = command.ExecuteReader();

            GV1.DataSource = dr;
            GV1.DataBind();



        }
    }
}