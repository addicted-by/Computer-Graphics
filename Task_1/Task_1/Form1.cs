using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Task_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            

        }
        Pen penx = new Pen(Color.Black);
        Pen os = new Pen(Color.LightGray);
        float a;
        float R;
        float k = 1;
        float k1 = 1;
        List<float> X = new List<float>(), Y = new List<float>();
        float phi = 0;
        private void Create_Click(object sender, EventArgs e)
        {
            if (X.Count() == 0)
            { Solve();
            }
            
            Draw();
            

        }
        private void Solve()
        {
            a = 10;
            while (phi <= (float)Math.PI)
            {
                R = (float)Math.Sqrt(a * a * (float)Math.Cos(2 * phi));
                if (Math.Abs(Math.Cos(phi)) < (float)Math.Sqrt(2) / 2)
                {
                    X.Add(0f);
                    Y.Add(0f);
                }
                else
                {
                    X.Add(R * (float)Math.Cos(phi));
                    Y.Add(R * (float)Math.Sin(phi));
                }
                phi += 0.01f;

            }
        }
        private void Draw()
        {
            for (float l = 0; l <= screen.Width; l += 20)
            {
                if (Math.Abs(l - screen.Width / 2) > 10)
                    Graphics.FromHwnd(screen.Handle).DrawLine(os, l, 0, l, screen.Height);
            }
            for (float l = 0; l <= screen.Height; l += 20)
            {
                if (Math.Abs(l - screen.Height / 2) > 10)
                    Graphics.FromHwnd(screen.Handle).DrawLine(os, 0, l, screen.Width, l);
            }
            clear = false;
            osx.Visible = true;
            Point x = new Point(screen.Height - 30, screen.Width / 2 + 10);
            osx.Location = x;
            osy.Visible = true;
            k = (float)Size.Value / 4;
            Graphics.FromHwnd(screen.Handle).DrawLine(penx, screen.Width / 2, 0, screen.Width / 2, screen.Height - 30);
            Graphics.FromHwnd(screen.Handle).DrawLine(penx, 0, screen.Height / 2, screen.Width, screen.Height / 2);
            Graphics.FromHwnd(screen.Handle).DrawLine(penx, screen.Width / 2, 0, screen.Width / 2 + 3, 10);
            Graphics.FromHwnd(screen.Handle).DrawLine(penx, screen.Width / 2, 0, screen.Width / 2 - 3, 10);
            Graphics.FromHwnd(screen.Handle).DrawLine(penx, screen.Width, screen.Height / 2, screen.Width - 10, screen.Height / 2 - 3);
            Graphics.FromHwnd(screen.Handle).DrawLine(penx, screen.Width, screen.Height / 2, screen.Width - 10, screen.Height / 2 + 3);
            k1 = (float)screen.Width / 428;
            
            
            Pen pen = new Pen(Color.Black);
            for (int i = 0; i < X.Count() - 1; i++)
            {
                Graphics.FromHwnd(screen.Handle).DrawLine(pen, k1 * k * X[i] * 120 / a + screen.Width / 2,
                    k1 * k * Y[i] * 120 / a + screen.Height / 2, k1 * k * X[i + 1] * 120 / a + screen.Width / 2,
                    k1 * k * Y[i + 1] * 120 / a + screen.Height / 2);
                Graphics.FromHwnd(screen.Handle).DrawLine(pen, k1 * k * X[i] * 120 / a + screen.Width / 2,
                    k1 * k * -1 * Y[i] * 120 / a + screen.Height / 2, k1 * k * X[i + 1] * 120 / a + screen.Width / 2,
                    k1 * k * -1 * Y[i + 1] * 120 / a + screen.Height / 2);

            }
        }
        private void Clear_Click(object sender, EventArgs e)
        {
            clear = true;
            osx.Visible = false;
            osy.Visible = false;
            Graphics.FromHwnd(screen.Handle).Clear(BackColor);
        }
       // bool is_changed = false;
        private void Form1_SizeChanged(object sender, EventArgs e)
        {
           
        }

        private void Size_Scroll(object sender, EventArgs e)
        {
            
            Graphics.FromHwnd(screen.Handle).Clear(BackColor);
            Draw();
        }
        bool clear = true;

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            osx.Visible = true;
            Point x = new Point(screen.Height - 30, screen.Width / 2 + 10);
            osx.Location = x;
            osy.Visible = true;
            Draw();
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            
            /*if (!clear)
            {
                Draw();
                base.OnPaint(e);
            }*/
        }
    }
}
