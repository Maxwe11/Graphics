using System;
using System.Collections.Generic;
using System.Linq;
using System.Drawing;
using System.Windows.Forms;

namespace gr1
{
    class RealScreenConv
    { 
        public static float cX = 100, cY = 100;
        public static float zoom = 3;
        public static float wgtHeight = 400, wgtWidth = 400;

        public static float GetScreenX(double x)
        {
            return (float)x * zoom + cX;
        }
        public static float GetScreenY(double y)
        {
            return wgtHeight - (float)y * zoom - cY;
        }
    }
    class Point
    {
        private double x;
        private double y;

        public Point(double x, double y)
        {
            this.x = x;
            this.y = y;
        }
        public Point(decimal x, decimal y)
        {
            this.x = (double)x;
            this.y = (double)y;
        }
        public double X
        {
            get
            {
                return x;
            }
            set
            {
                x = value;
            }
        }

        public double Y
        {
            get
            {
                return y;
            }
            set
            {
                y = value;
            }
        }

        public float SX
        {
            get
            {
                return RealScreenConv.GetScreenX(x);
            }
            set
            { 
            
            }
        }
        public float SY
        {
            get
            {
                return RealScreenConv.GetScreenY(y);
            }
            set
            { 
            
            }
        }
    }
    class Model
    {
        public Point[] p;
        public Point[] circle;
        public Point[] circle1;
        public Point c;

        public Model()
        { }
        public Model(Point p1, Point p2, Point p3, Point p4, Point p5, Point c)
        {
            p = new Point[5] { p1, p2, p3, p4, p5 };
            SetC(c);
        }
        public void SetP(Point p1, Point p2, Point p3, Point p4, Point p5)
        {
            p = new Point[5] { p1, p2, p3, p4, p5 };
        }
        public void SetC(Point c)
        {
            this.c = c;
            int discret = 36;
            double radius = 30;
            double radius1 = 20;
            circle = new Point[discret];
            circle1 = new Point[discret];
            int i = 0;
            for (double a = 0; a < 2 * Math.PI && i < discret; a += 2 * Math.PI / discret)
            {
                circle[i] = new Point(Math.Cos(a) * radius + c.X, 
                                      Math.Sin(a) * radius + c.Y);
                circle1[i] = new Point(Math.Cos(a) * radius1 + c.X,
                                      Math.Sin(a) * radius1 + c.Y);
                i++;
            }
        }
        public void Koef(Point p1, Point p2, Point pn, ref double a, ref double b, ref double c)
        {
            a = p2.Y - p1.Y;
            b = p1.X - p2.X;
            c = -(a * p1.X + b * p1.Y);
            double d = Math.Sqrt(a * a + b * b);
            a /= d; b /= d; c /= d;
            double f = a * pn.X + b * pn.Y + c;
            if (f < 0)
            {
                a = -a;
                b = -b;
                c = -c;
            }
        }
        public double GetBeta(Point p1, Point p2, Point pn)
        {
            double a = 0, b = 0, c = 0;
            Koef(p1, p2, pn, ref a, ref b, ref c);

            return a * pn.X + b * pn.Y + c;
        }
        public Point Move(Point[] p1, Point c, int size)
        {
            double[] beta = new double[size];
            double[] A = new double[size];
            double[] B = new double[size];
            double[] C = new double[size];

            for (int i = 0; i < size - 1; i++)
            {
                Koef(p1[i], p1[i + 1], c, ref A[i], ref B[i], ref C[i]);
                beta[i] = GetBeta(p[i], p[i + 1], c);
            }
            Koef(p1[size - 1], p1[0], c, ref A[size - 1], ref B[size - 1], ref C[size - 1]);
            beta[size - 1] = GetBeta(p[size - 1], p[0], c);

            double Dx = 0, Gx = 0, Dy = 0, Gy = 0, D = 0, G = 0;
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    if (i != j)
                    {
                        Dx += Math.Pow(A[i] / beta[i] - A[j] / beta[j], 2.0);
                        Gx += (A[i] / beta[i] - A[j] / beta[j]) * (B[i] / beta[i] - B[j] / beta[j]);
                        Dy += (A[i] / beta[i] - A[j] / beta[j]) * (B[i] / beta[i] - B[j] / beta[j]);
                        Gy += Math.Pow(B[i] / beta[i] - B[j] / beta[j], 2.0);
                        D += (A[i] / beta[i] - A[j] / beta[j]) * (C[i] / beta[i] - C[j] / beta[j]);
                        G += (B[i] / beta[i] - B[j] / beta[j]) * (C[i] / beta[i] - C[j] / beta[j]);
                    }
            Point c1 = new Point(0.0, 0.0);
            c1.Y = (Gx * D / Dx - G) / (Gy - Gx * Dy / Dx);
            c1.X = (-D - Dy * c1.Y) / Dx;

            return c1;
        }
        public void Solution(Point[] p1)
        {
            c = Move(p1, c, 5);
            for (int i = 0; i < circle.Length; i++)
            {
                circle[i] = Move(p1, circle[i], 5);
                circle1[i] = Move(p1, circle1[i], 5);
            }
            this.p = p1;
        }
        public void Paint(Graphics gr)
        {
            gr.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            Pen pen = new Pen(Color.Blue);
            Pen penRed = new Pen(Color.Red);
            Pen penGreen = new Pen(Color.Green);
            Font font = new Font("Tahoma", 9f);

            gr.DrawLine(pen, p[0].SX, p[0].SY, p[1].SX, p[1].SY);
            gr.DrawLine(pen, p[1].SX, p[1].SY, p[2].SX, p[2].SY);
            gr.DrawLine(pen, p[2].SX, p[2].SY, p[3].SX, p[3].SY);
            gr.DrawLine(pen, p[3].SX, p[3].SY, p[4].SX, p[4].SY);
            gr.DrawLine(pen, p[4].SX, p[4].SY, p[0].SX, p[0].SY);
            for (int i = 0; i < p.Length; i++)
            {
                gr.DrawString("P" + (i+1).ToString(), font, Brushes.Black, p[i].SX - 15, p[i].SY - 15);
                gr.DrawEllipse(penRed, p[i].SX - 2, p[i].SY - 2, 4f, 4f);
            }
            gr.DrawEllipse(penRed, c.SX - 3, c.SY - 3, 6f, 6f);
            /*for (int i = 0; i < circle.Length - 1; i++)
            {
                gr.DrawLine(penGreen, circle[i].SX, circle[i].SY, circle[i + 1].SX, circle[i + 1].SY);
            }
            gr.DrawLine(penGreen, circle[circle.Length-1].SX, circle[circle.Length-1].SY, circle[0].SX, circle[0].SY);
            */
            for (int i = 0; i < circle.Length - 1; i++)
            {
                gr.DrawLine(penGreen, circle1[i].SX, circle1[i].SY, circle1[i + 1].SX, circle1[i + 1].SY);
            }
            gr.DrawLine(penGreen, circle1[circle1.Length - 1].SX, circle1[circle1.Length - 1].SY, circle1[0].SX, circle1[0].SY);
        }
    }
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
