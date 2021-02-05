using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace lab_2
{
    class Triangle
    {

        Graphics grph;
        Point3D fst, snd, trd;
        int type;
        Pen pen = new Pen(Color.Black);
        public Triangle(Point3D fst, Point3D snd, Point3D trd, Graphics grph, int type)
        {
            this.fst = fst;
            this.snd = snd;
            this.trd = trd;
            this.grph = grph;
            this.type = type;
        }

        public Triangle()
        {

        }

        public void tr_draw(double angle_x, double angle_y)
        {
            Point[] new_tr = new Point[3];
            Point3D fstX, fstY, sndX, sndY, trdX, trdY;

            fstX = new Point3D(fst.X, fst.Y * Math.Cos(angle_y) - fst.Z * Math.Sin(angle_y), fst.Y * Math.Sin(angle_y) + fst.Z * Math.Cos(angle_y));
            sndX = new Point3D(snd.X, snd.Y * Math.Cos(angle_y) - snd.Z * Math.Sin(angle_y), snd.Y * Math.Sin(angle_y) + snd.Z * Math.Cos(angle_y));
            trdX = new Point3D(trd.X, trd.Y * Math.Cos(angle_y) - trd.Z * Math.Sin(angle_y), trd.Y * Math.Sin(angle_y) + trd.Z * Math.Cos(angle_y));
            fstY = new Point3D(fstX.X * Math.Cos(angle_x) + fstX.Z * Math.Sin(angle_x), fstX.Y, -fstX.X * Math.Sin(angle_x) + fstX.Z * Math.Cos(angle_x));
            sndY = new Point3D(sndX.X * Math.Cos(angle_x) + sndX.Z * Math.Sin(angle_x), sndX.Y, -sndX.X * Math.Sin(angle_x) + sndX.Z * Math.Cos(angle_x));
            trdY = new Point3D(trdX.X * Math.Cos(angle_x) + trdX.Z * Math.Sin(angle_x), trdX.Y, -trdX.X * Math.Sin(angle_x) + trdX.Z * Math.Cos(angle_x));

            
            if (get_normZ(fstY,sndY,trdY) >= 0)
            {
                grph.DrawLine(pen, new Point((int)fstY.X, (int)fstY.Y), new Point((int)sndY.X, (int)sndY.Y));
                grph.DrawLine(pen, new Point((int)sndY.X, (int)sndY.Y), new Point((int)trdY.X, (int)trdY.Y));
                grph.DrawLine(pen, new Point((int)trdY.X, (int)trdY.Y), new Point((int)fstY.X, (int)fstY.Y));
            }
        }
        private double get_normZ(Point3D a, Point3D b, Point3D c) //Нормаль по Z
        {
            double n_z = 0;
            n_z = ((b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X));
            //n_z = ((b.X - a.X) * (c.Y - a.Y) - );
            return n_z;
        }
    }   

}
