using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab_2
{
    public partial class Form1 : Form
    {

        double angleX, angleY;
        Bitmap btmp;
        Graphics grph;
        Triangle[] tr_fig = new Triangle[12];
        Point3D pUP1, pUP2, pUP3, pUP4, pDW1, pDW2, pDW3, pDW4;
        bool first = true;
        int pre_w = 913;
        int pre_h = 765;
        float scalex = 1;
        float scaley = 1;

        private void plus_size_Click(object sender, EventArgs e)
        {
            
            scalex *= 1.2f;
            Graphics.FromImage(pictureBox1.Image).Clear(BackColor);
            Update();
        }

        private void min_size_Click(object sender, EventArgs e)
        {
            scalex /= 1.2f;
            Graphics.FromImage(pictureBox1.Image).Clear(BackColor);
            Update();
        }

        private void Form1_Resize(object sender, EventArgs e)
        {

        }
        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            pUP1 = new Point3D(-150*scalex, -150*scalex, 0);
            pUP2 = new Point3D(150*scalex, -150*scalex, 0);
            pUP3 = new Point3D(150*scalex, 150*scalex, 0);
            pUP4 = new Point3D(-150*scalex, 150*scalex, 0);
            pDW1 = new Point3D(0, 75*scalex, 150*scalex);
            pDW2 = new Point3D(0, -75*scalex, 150*scalex);

            tr_fig[0] = new Triangle(pUP1, pUP2, pUP3, grph, 1);
            tr_fig[1] = new Triangle(pUP1, pUP3, pUP4, grph, 1);
            tr_fig[2] = new Triangle(pUP1, pDW2, pUP2, grph, 1);
            tr_fig[3] = new Triangle(pUP2, pDW2, pUP3, grph, 1);
            tr_fig[4] = new Triangle(pUP3, pDW2, pDW1, grph, 1);
            tr_fig[5] = new Triangle(pUP3, pDW1, pUP4, grph, 1);
            tr_fig[6] = new Triangle(pDW2, pUP4, pDW1, grph, 1);
            tr_fig[7] = new Triangle(pDW2, pUP1, pUP4, grph, 1);

            for (int i = 0; i < 8; i++)
            {
                tr_fig[i].tr_draw(angleX, angleY);
            }
            pictureBox1.Image = btmp;
            trBar_angleX.Value = 100;
            trBar_angleY.Value = 100;
        }

        public Form1()
        {
            InitializeComponent();
        }
        int scale = 1;
        private void Form1_Load(object sender, EventArgs e)
        {
            btmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            grph = Graphics.FromImage(btmp);
            grph.TranslateTransform(pictureBox1.Width / 2, pictureBox1.Height / 2);
            grph.ScaleTransform(1, -1);
            angleX = angleY = 1;
            
            scale = pictureBox1.Width / 812;
            if (scale != 0)
                {
                pUP1 = new Point3D(-150 * scale, -150 * scale, 0);
                pUP2 = new Point3D(150 * scale, -150 * scale, 0);
                pUP3 = new Point3D(150 * scale, 150 * scale, 0);
                pUP4 = new Point3D(-150 * scale, 150 * scale, 0);
                pDW1 = new Point3D(0, 75 * scale, 150 * scale);
                pDW2 = new Point3D(0, -75 * scale, 150 * scale);
                /*pDW3 = new Point3D(150, 150, -150);
                pDW4 = new Point3D(-150, 150, -150);*/
                /*tr_fig[0] = new Triangle(pUP1, pDW1, pUP2, grph, 1);
                tr_fig[1] = new Triangle(pDW1, pDW2, pUP2, grph, 1);
                tr_fig[2] = new Triangle(pUP1, pDW1, pDW4, grph, 1);
                tr_fig[3] = new Triangle(pUP1, pUP4, pDW4, grph, 1);
                tr_fig[4] = new Triangle(pDW4, pDW3, pUP3, grph, 1);
                tr_fig[5] = new Triangle(pDW4, pUP4, pUP3, grph, 1);
                tr_fig[6] = new Triangle(pDW3, pDW2, pUP2, grph, 1);
                tr_fig[7] = new Triangle(pDW3, pUP3, pUP2, grph, 1);
                tr_fig[8] = new Triangle(pUP1, pUP4, pUP2, grph, 1);
                tr_fig[9] = new Triangle(pUP3, pUP4, pUP2, grph, 1);
                tr_fig[10] = new Triangle(pDW1, pDW4, pDW2, grph, 2);
                tr_fig[11] = new Triangle(pDW3, pDW4, pDW2, grph, 2);*/
                tr_fig[0] = new Triangle(pUP1, pUP2, pUP3, grph, 1);
                tr_fig[1] = new Triangle(pUP1, pUP3, pUP4, grph, 1);
                tr_fig[2] = new Triangle(pUP1, pDW2, pUP2, grph, 1);
                tr_fig[3] = new Triangle(pUP2, pDW2, pUP3, grph, 1);
                tr_fig[4] = new Triangle(pUP3, pDW2, pDW1, grph, 1);
                tr_fig[5] = new Triangle(pUP3, pDW1, pUP4, grph, 1);
                tr_fig[6] = new Triangle(pDW2, pUP4, pDW1, grph, 1);
                tr_fig[7] = new Triangle(pDW2, pUP1, pUP4, grph, 1);


                //tr_fig[8] = new Triangle(pUP1, pDW2, pUP2, grph, 1);
                for (int i = 0; i < 8; i++)
                {
                    tr_fig[i].tr_draw(angleX, angleY);
                }
                pictureBox1.Image = btmp;
                trBar_angleX.Value = 100;
                trBar_angleY.Value = 100;
            }
        }

        private void trBar_angleY_Scroll(object sender, EventArgs e)
        {
            angleY = (double)(trBar_angleY.Value) / 100;
            main_draw();
        }

        private void trBar_angleX_Scroll(object sender, EventArgs e)
        {
            angleX = (double)(trBar_angleX.Value) / 100;
            main_draw();
        }

        private void main_draw()
        {
            grph.Clear(pictureBox1.BackColor);
            label1.Text = angleX.ToString();
            label2.Text = angleY.ToString();
            label1.Visible = true;
            label2.Visible = true;
            for (int i = 0; i < 8; i++)
            {
                tr_fig[i].tr_draw(angleX, angleY);
            }
            pictureBox1.Image = btmp;
        }
    }
}
