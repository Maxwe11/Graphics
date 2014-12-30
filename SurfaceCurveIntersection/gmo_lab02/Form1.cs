using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace gmo_lab02
{
    public partial class Form1 : Form
    {
        //----------------------------------------------
        //реализация служебных классов и функций
        //----------------------------------------------


        public class Point2d
        {
            public float x;
            public float y;
            public float[] mas;

            public Point2d(float _x, float _y)
            {
                x = _x;
                y = _y;
                mas = new float[3];
                mas[0] = _x;
                mas[1] = _y;
                mas[2] = 1;
            }

            public Point2d(float[] _mas) : this(_mas[0], _mas[1]) { }

            public Point2d() : this((float)0, (float)0) { }

            public Point2d(float[,] _mas) : this(_mas[0, 0], _mas[0, 1]) { }

            public Point2d(double _x, double _y) : this((float)_x, (float)_y) { }

        }


        public class Point3d
        {
            public float x;
            public float y;
            public float z;
            public float[] mas;

            public Point3d(float _x, float _y, float _z)
            {
                x = _x;
                y = _y;
                z = _z;
                mas = new float[4];
                mas[0] = _x;
                mas[1] = _y;
                mas[2] = _z;
                mas[3] = 1;
            }

            public Point3d(float[] _mas) : this(_mas[0], _mas[1], _mas[2]) { }

            public Point3d() : this((float)0, (float)0, (float)0) { }

            public Point3d(float[,] _mas) : this(_mas[0, 0], _mas[0, 1], _mas[0, 2]) { }

            public Point3d(double _x, double _y, double _z) : this((float)_x, (float)_y, (float)_z) { }

        }

        public class CurveB
        {
            public Point3d A;
            public Point3d B;
            public Point3d C;
            public Point3d D;

            public int N;

            public CurveB(int _N, Point3d[] args)
            {
                N = _N;
                A = args[0];
                B = args[1];
                C = args[2];
                D = args[3];
            }

            public List<Point3d> getCurve()
            {
                float step = (float)1 / (float)(N - 1);
                float u = 0;
                List<Point3d> kon = new List<Point3d>();
                while (u < (1 + step))
                {
                    float x = (float)(Math.Pow(1.0 - u, 3) * A.x + Math.Pow(1.0 - u, 2) * u * B.x + Math.Pow(u, 2) * (1.0 - u) * C.x + Math.Pow(u, 3) * D.x);
                    float y = (float)(Math.Pow(1.0 - u, 3) * A.y + Math.Pow(1.0 - u, 2) * u * B.y + Math.Pow(u, 2) * (1.0 - u) * C.y + Math.Pow(u, 3) * D.y);                    
                    float z = (float)(Math.Pow(1.0 - u, 3) * A.z + Math.Pow(1.0 - u, 2) * u * B.z + Math.Pow(u, 2) * (1.0 - u) * C.z + Math.Pow(u, 3) * D.z);
                    kon.Add(new Point3d(x, y, z));
                    u += step;
                }
                return kon;
            }

        }

        public float[,] multiply(float[,] A, float[,] B)
        {
            int m = A.GetLength(0);
            int n = A.GetLength(1);
            int k = B.GetLength(1);

            float[,] C = new float[m, k];

            for (int i = 0; i < m; i++)
                for (int j = 0; j < k; j++)
                {
                    float S = 0;
                    for (int t = 0; t < n; t++)
                    {
                        S += A[i, t] * B[t, j];
                    }
                    C[i, j] = S;
                }
            return C;
        }


        public class ShapeB
        {
            List<List<Point3d>> Points;

            static int _count_otr_ = 15; //кол-во делений отрезка между двумя краями

            public int M, N; //кол-во точек в каркасе


            public ShapeB(int _N, int _M, Point3d[] args)
            {
                Points = new List<List<Point3d>>();
                M = _M; // row
                N = _N; // column
                
                int k = 0;
                for (int i = 0; i < M; i++)
                {
                    List<Point3d> t_c = new List<Point3d>();
                    for (int j = 0; j < N; j++)
                    {
                        t_c.Add(args[k]);
                        k++;
                    }
                    Points.Add(t_c);
                }
            }

            public int factorial(int F)
            {
                int t = 1;
                for (int i = 1; i <= F; i++)
                    t *= i;
                return t;
            }

            public List<List<Point3d>> getShape()
            {
                List<List<Point3d>> Res = new List<List<Point3d>>();

                float d = 1 / (float)_count_otr_;
               
                for(float v=0; v<1+d; v+=d)
                {
                    List<Point3d> t = new List<Point3d>();
                    for(float u=0; u<1+d; u+=d)
                    {
                        float x,y,z;
                        x=y=z=0;
                        for (int i = 0; i < M; i++)
                        {
                            int denum1 = factorial(M - 1) / (factorial(i) * factorial(M - i - 1));
                            for (int j = 0; j < N; j++)
                            {
                                int denum2 = factorial(N - 1) / (factorial(j) * factorial(N - j - 1));
                                x += denum1 * (float)Math.Pow(v, i) * (float)Math.Pow(1.0 - v, M - i - 1) *
                                     denum2 * (float)Math.Pow(u, j) * (float)Math.Pow(1.0 - u, M - j - 1) * Points[i][j].x;
                                y += denum1 * (float)Math.Pow(v, i) * (float)Math.Pow(1.0 - v, M - i - 1) *
                                    denum2 * (float)Math.Pow(u, j) * (float)Math.Pow(1.0 - u, M - j - 1) * Points[i][j].y;
                                z += denum1 * (float)Math.Pow(v, i) * (float)Math.Pow(1.0 - v, M - i - 1) *
                                    denum2 * (float)Math.Pow(u, j) * (float)Math.Pow(1.0 - u, M - j - 1) * Points[i][j].z;
                            }
                        }
                        t.Add(new Point3d(x,y,z));
                    }
                    Res.Add(t);
                }

                for(float u=0; u<1+d; u+=d)
                {
                    List<Point3d> t = new List<Point3d>();
                    for(float v=0; v<1+d; v+=d)
                    {
                        float x,y,z;
                        x=y=z=0;
                        for (int i = 0; i < M; i++)
                        {
                            int denum1 = factorial(M - 1) / (factorial(i) * factorial(M - i - 1));
                            for (int j = 0; j < N; j++)
                            {
                                int denum2 = factorial(N - 1) / (factorial(j) * factorial(N - j - 1));
                                x += denum1 * (float)Math.Pow(v, i) * (float)Math.Pow(1.0 - v, M - i - 1) *
                                     denum2 * (float)Math.Pow(u, j) * (float)Math.Pow(1.0 - u, M - j - 1) * Points[i][j].x;
                                y += denum1 * (float)Math.Pow(v, i) * (float)Math.Pow(1.0 - v, M - i - 1) *
                                    denum2 * (float)Math.Pow(u, j) * (float)Math.Pow(1.0 - u, M - j - 1) * Points[i][j].y;
                                z += denum1 * (float)Math.Pow(v, i) * (float)Math.Pow(1.0 - v, M - i - 1) *
                                    denum2 * (float)Math.Pow(u, j) * (float)Math.Pow(1.0 - u, M - j - 1) * Points[i][j].z;
                            }
                        }
                        t.Add(new Point3d(x,y,z));
                    }
                    Res.Add(t);
                }

                return Res;
            }

            
        }


        public void transform(List<Point3d> kon_s, ref List<Point3d> kon_n)
        {
            float[,] trnsf1 = new float[4, 4];
            float[,] trnsfZ = new float[4, 4];
            float[,] trnsfY = new float[4, 4];
            float[,] trnsfX = new float[4, 4];
            float[,] trnsf2 = new float[4, 4];

            trnsf1[0, 0] = 1;
            trnsf1[1, 1] = 1;
            trnsf1[2, 2] = 1;
            trnsf1[3, 0] = (float)-Ev_cen_x.Value;
            trnsf1[3, 1] = (float)-Ev_cen_y.Value;
            trnsf1[3, 2] = (float)-Ev_cen_z.Value;
            trnsf1[3, 3] = 1;

            trnsf2[0, 0] = 1;
            trnsf2[1, 1] = 1;
            trnsf2[2, 2] = 1;
            trnsf2[3, 0] = (float)Ev_cen_x.Value;
            trnsf2[3, 1] = (float)Ev_cen_y.Value;
            trnsf2[3, 2] = (float)Ev_cen_z.Value;
            trnsf2[3, 3] = 1;

            float alpha = (float)Ev_rot_OX.Value * (float)Math.PI / (float)180;
            float beta = (float)Ev_rot_OY.Value * (float)Math.PI / (float)180;
            float gamma = (float)Ev_rot_OZ.Value * (float)Math.PI / (float)180;


            trnsfZ[0, 0] = 1;
            trnsfZ[1, 1] = 1;
            trnsfZ[2, 2] = 1;
            trnsfZ[3, 3] = 1;
            trnsfZ[0, 0] = (float)Math.Cos(gamma);
            trnsfZ[0, 1] = (float)Math.Sin(gamma);
            trnsfZ[1, 0] = (float)-Math.Sin(gamma);
            trnsfZ[1, 1] = (float)Math.Cos(gamma);


            trnsfY[0, 0] = 1;
            trnsfY[1, 1] = 1;
            trnsfY[2, 2] = 1;
            trnsfY[3, 3] = 1;
            trnsfY[0, 0] = (float)Math.Cos(beta);
            trnsfY[0, 2] = (float)-Math.Sin(beta);
            trnsfY[2, 0] = (float)Math.Sin(beta);
            trnsfY[2, 2] = (float)Math.Cos(beta);


            trnsfX[0, 0] = 1;
            trnsfX[1, 1] = 1;
            trnsfX[2, 2] = 1;
            trnsfX[3, 3] = 1;
            trnsfX[1, 1] = (float)Math.Cos(alpha);
            trnsfX[1, 2] = (float)Math.Sin(alpha);
            trnsfX[2, 1] = (float)-Math.Sin(alpha);
            trnsfX[2, 2] = (float)Math.Cos(alpha);


            kon_n.Clear();

            foreach (Point3d i in kon_s)
            {
                float[,] t = new float[1, 4];
                t[0, 0] = i.mas[0];
                t[0, 1] = i.mas[1];
                t[0, 2] = i.mas[2];
                t[0, 3] = i.mas[3];
                kon_n.Add(new Point3d(multiply(multiply(multiply(multiply(multiply(t, trnsf1), trnsfZ), trnsfY), trnsfX), trnsf2)));
            }

            return;
        }


		private List<float> getShapeEquation( Point3d P1, Point3d P2, Point3d P3 )
		{
			List<float> res = new List<float>();
			float A = (P1.y-P2.y)*(P3.z-P2.z) - (P1.z-P2.z)*(P3.y-P2.y);
            float B = (P1.z-P2.z)*(P3.x-P2.x) - (P1.x-P2.x)*(P3.z-P2.z);
            float C = (P1.x-P2.x)*(P3.y-P2.y) - (P1.y-P2.y)*(P3.x-P2.x);
            float D =  - ( P2.x*((P1.y-P2.y)*(P3.z-P2.z) - (P1.z-P2.z)*(P3.y-P2.y)) + P2.y*((P1.z-P2.z)*(P3.x-P2.x) - (P1.x-P2.x)*(P3.z-P2.z)) + P2.z*((P1.x-P2.x)*(P3.y-P2.y) - (P1.y-P2.y)*(P3.x-P2.x)) );
			res.Add(A); res.Add(B); res.Add(C); res.Add(D);
			return res;
		}
		
		private float getDelta(Point3d P1, Point3d P2, Point3d P3, Point3d P4)
		{
			List<float> Shape = getShapeEquation(P1,P2,P3);
			float A = Shape[0];
            float B = Shape[1];
            float C = Shape[2];
            float D = Shape[3];
			
			float mu;
            if (D > 0) mu = (float)(-1); else  mu = (float)1;
			mu /= (float)Math.Abs(A*A+B*B+C*C);
			
			float del = A*mu*P4.x + B*mu*P4.y + C*mu*P4.z + D*mu;
			return del;
		}
		
        private void getIntersectPoints(List<List<Point3d>> tShape, List<Point3d> tCurve, ref List<Point3d> res)
        {
            int LEHGTH = tShape.Count / 2;

            // = new List<Point3d>();

            for (int i = 0; i < (tCurve.Count - 1); i++)
            {
                Point3d P4 = tCurve[i];
                Point3d P5 = tCurve[i+1];

                for(int j=0; j<LEHGTH-1; j++)
                    for (int k = 0; k < (tShape[j].Count - 1); k++)
                    {
                        Point3d P1 = tShape[ j ][ k ];
                        Point3d P2 = tShape[j+1][ k ];//then Point3d P2 = tShape[ j ][k+1];
                        Point3d P3 = tShape[j+1][k+1];

                        float A = (P1.y-P2.y)*(P3.z-P2.z) - (P1.z-P2.z)*(P3.y-P2.y);
                        float B = (P1.z-P2.z)*(P3.x-P2.x) - (P1.x-P2.x)*(P3.z-P2.z);
                        float C = (P1.x-P2.x)*(P3.y-P2.y) - (P1.y-P2.y)*(P3.x-P2.x);
                        float D =  - ( P2.x*((P1.y-P2.y)*(P3.z-P2.z) - (P1.z-P2.z)*(P3.y-P2.y)) + P2.y*((P1.z-P2.z)*(P3.x-P2.x) - (P1.x-P2.x)*(P3.z-P2.z)) + P2.z*((P1.x-P2.x)*(P3.y-P2.y) - (P1.y-P2.y)*(P3.x-P2.x)) );

                        float t = (A*P4.x + B*P4.y + C*P4.z + D)/(A*(P4.x-P5.x)+B*(P4.y-P5.y)+C*(P4.z-P5.z));
                        if (0 <= t && t <= 1)
                        {
                            float tX = P4.x + t * (P5.x - P4.x);
                            float tY = P4.y + t * (P5.y - P4.y);
                            float tZ = P4.z + t * (P5.z - P4.z);
							
							float d1 = getDelta(P1,P4,P2,new Point3d(tX,tY,tZ))*getDelta(P1,P4,P2,P3);
							float d2 = getDelta(P1,P4,P3,new Point3d(tX,tY,tZ))*getDelta(P1,P4,P3,P2);
							float d3 = getDelta(P3,P4,P2,new Point3d(tX,tY,tZ))*getDelta(P3,P4,P2,P1);
							
							if ( d1>0 && d2>0 && d3>0 ) 
								res.Add(new Point3d(tX, tY, tZ));

                        }
                        //then Point3d P2 = tShape[j][k+1];

                        P2 = tShape[ j ][k+1];

                        A = (P1.y-P2.y)*(P3.z-P2.z) - (P1.z-P2.z)*(P3.y-P2.y);
                        B = (P1.z-P2.z)*(P3.x-P2.x) - (P1.x-P2.x)*(P3.z-P2.z);
                        C = (P1.x-P2.x)*(P3.y-P2.y) - (P1.y-P2.y)*(P3.x-P2.x);
                        D =  - ( P2.x*((P1.y-P2.y)*(P3.z-P2.z) - (P1.z-P2.z)*(P3.y-P2.y)) + P2.y*((P1.z-P2.z)*(P3.x-P2.x) - (P1.x-P2.x)*(P3.z-P2.z)) + P2.z*((P1.x-P2.x)*(P3.y-P2.y) - (P1.y-P2.y)*(P3.x-P2.x)) );

                        t = (A*P4.x + B*P4.y + C*P4.z + D)/(A*(P4.x-P5.x)+B*(P4.y-P5.y)+C*(P4.z-P5.z));
                        if (0 <= t && t <= 1)
                        {
                            float tX = P4.x + t * (P5.x - P4.x);
                            float tY = P4.y + t * (P5.y - P4.y);
                            float tZ = P4.z + t * (P5.z - P4.z);

                            float d1 = getDelta(P1,P4,P2,new Point3d(tX,tY,tZ))*getDelta(P1,P4,P2,P3);
							float d2 = getDelta(P1,P4,P3,new Point3d(tX,tY,tZ))*getDelta(P1,P4,P3,P2);
							float d3 = getDelta(P3,P4,P2,new Point3d(tX,tY,tZ))*getDelta(P3,P4,P2,P1);
							
							if ( d1>0 && d2>0 && d3>0 ) 
								res.Add(new Point3d(tX, tY, tZ));
                        }
                    }
            }

            //return;
        }


        public void to2d(List<Point3d> kon_s, ref List<Point2d> kon_n)
        {
            kon_n.Clear();

            float[,] pr_trnf = new float[4, 4];

            pr_trnf[0, 0] = 1;
            pr_trnf[1, 1] = 1;
            pr_trnf[2, 2] = 0;
            pr_trnf[3, 3] = 1;
            pr_trnf[3, 2] = (float)pr_pl_Z.Value;


            float[,] pr_rot_x = new float[4, 4];
            pr_rot_x[0, 0] = 1;
            pr_rot_x[3, 3] = 1;
            pr_rot_x[1, 1] = (float)0.866;
            pr_rot_x[1, 2] = (float)0.5;
            pr_rot_x[2, 1] = (float)-0.5;
            pr_rot_x[2, 2] = (float)0.866;
            float[,] pr_rot_y = new float[4, 4];
            pr_rot_y[0, 0] = (float)0.866;
            pr_rot_y[0, 2] = (float)-0.5;
            pr_rot_y[2, 2] = (float)0.866;
            pr_rot_y[2, 0] = (float)0.5;
            pr_rot_y[1, 1] = 1;
            pr_rot_y[3, 3] = 1;

            foreach (Point3d i in kon_s)
            {
                float[,] t = new float[1, 4];
                t[0, 0] = i.mas[0];
                t[0, 1] = i.mas[1];
                t[0, 2] = i.mas[2];
                t[0, 3] = i.mas[3];
                //kon_n.Add(new Point2d(multiply(t, pr_trnf)));//prev
                kon_n.Add(new Point2d(multiply(multiply(multiply(t, pr_rot_x), pr_rot_y), pr_trnf)));
                //kon_n.Add(new Point2d(multiply(multiply(t, pr_rot_y), pr_trnf)));

            }

       }



        //----------------------------------------------
        //переменные и методы для посторения
        //----------------------------------------------

        protected List<Point3d> kon_osi_Or;
        //protected List<Point2d> kon_osi_Pr;
		
		protected List<Point3d> kon_curve_Or;
		protected List<List<Point3d>> kon_shape_Or;

        protected ShapeB Figure;

        protected CurveB Curve;
		
		protected List<Point3d> IntersectPoints;

        int x0, y0;


        private float to_x(float x)
        {
            return (float)x0 + x;
        }

        private float to_y(float y)
        {
            return (float)y0 - y;
        }

        public void draw_osi(Graphics gr, Pen brush, List<Point2d> kon)
        {
            float ye = 1;
            //X
            gr.DrawLine(brush, to_x(kon[0].x * ye), to_y(kon[0].y * ye),
                                   to_x(kon[1].x * ye), to_y(kon[1].y * ye));
            gr.DrawLine(brush, to_x(kon[2].x * ye), to_y(kon[2].y * ye),
                                   to_x(kon[1].x * ye), to_y(kon[1].y * ye));
            gr.DrawLine(brush, to_x(kon[3].x * ye), to_y(kon[3].y * ye),
                                   to_x(kon[1].x * ye), to_y(kon[1].y * ye));
            gr.DrawString("X", new Font("Arial", 10), Brushes.Black, to_x(kon[1].x * ye) - 15, to_y(kon[1].y * ye) + 5);
            //Y
            gr.DrawLine(brush, to_x(kon[4].x * ye), to_y(kon[4].y * ye),
                                   to_x(kon[5].x * ye), to_y(kon[5].y * ye));
            gr.DrawLine(brush, to_x(kon[6].x * ye), to_y(kon[6].y * ye),
                                   to_x(kon[5].x * ye), to_y(kon[5].y * ye));
            gr.DrawLine(brush, to_x(kon[7].x * ye), to_y(kon[7].y * ye),
                                   to_x(kon[5].x * ye), to_y(kon[5].y * ye));
            gr.DrawString("Y", new Font("Arial", 10), Brushes.Black, to_x(kon[5].x * ye) + 5, to_y(kon[5].y * ye) + 5);
            //Z
            gr.DrawLine(brush, to_x(kon[8].x * ye), to_y(kon[8].y * ye),
                                   to_x(kon[9].x * ye), to_y(kon[9].y * ye));
            gr.DrawLine(brush, to_x(kon[10].x * ye), to_y(kon[10].y * ye),
                                   to_x(kon[9].x * ye), to_y(kon[9].y * ye));
            gr.DrawLine(brush, to_x(kon[11].x * ye), to_y(kon[11].y * ye),
                                   to_x(kon[9].x * ye), to_y(kon[9].y * ye));
            gr.DrawString("Z", new Font("Arial", 10), Brushes.Black, to_x(kon[9].x * ye) + 15, to_y(kon[9].y * ye) + 5);

            //0
            gr.DrawString("0", new Font("Arial", 10), Brushes.Black, to_x(kon[12].x * ye) + 5, to_y(kon[12].y * ye) + 5);
        }

        public void draw_curve(Graphics gr, Pen brush, List<Point2d> kon)
        { 
            float ye = (float)SIZE.Value;
            for(int i=0; i<(kon.Count-1); i++)
            {
                gr.DrawLine(brush, to_x(kon[i].x*ye),to_y(kon[i].y*ye),
                    to_x(kon[i+1].x*ye),to_y(kon[i+1].y*ye));
            }
        }



        //-----------------------------------------------------
        // служебные методы работы с окном
        //-----------------------------------------------------




        public Form1()
        {
            InitializeComponent();

            x0 = DrawBox1.Size.Width / 2;
            y0 = DrawBox1.Size.Height / 2;

            //-------------------------------
            // Stroim Osi

            kon_osi_Or = new List<Point3d>();
            //kon_osi_Pr = new List<Point2d>();
            float Max = 300;
            float delta = 20;
            //X
            kon_osi_Or.Add(new Point3d(-Max, 0, 0));
            kon_osi_Or.Add(new Point3d(Max, 0, 0));
            kon_osi_Or.Add(new Point3d(Max - delta, delta, 0));
            kon_osi_Or.Add(new Point3d(Max - delta, -delta, 0));
            //Y
            kon_osi_Or.Add(new Point3d(0, -Max, 0));
            kon_osi_Or.Add(new Point3d(0, Max, 0));
            kon_osi_Or.Add(new Point3d(delta, Max - delta, 0));
            kon_osi_Or.Add(new Point3d(-delta, Max - delta, 0));
            //Z
            kon_osi_Or.Add(new Point3d(0, 0, -Max));
            kon_osi_Or.Add(new Point3d(0, 0, Max));
            kon_osi_Or.Add(new Point3d(0, delta, Max - delta));
            kon_osi_Or.Add(new Point3d(0, -delta, Max - delta));
            //O
            kon_osi_Or.Add(new Point3d(0, 0, 0));
            

            ////-------------------------------
            //// Build figure
            List<Point3d> t = new List<Point3d>();
            t.Add(new Point3d(-100, -50, -50));
            t.Add(new Point3d(-110, -45, -50));
            t.Add(new Point3d(-125, -50, -50));
            t.Add(new Point3d(-150, -35, -50));
            t.Add(new Point3d(-25, -10, -20));
            t.Add(new Point3d(-35, -15, -20));
            t.Add(new Point3d(-27, -30, -20));
            t.Add(new Point3d(-25, -10, -20));
            t.Add(new Point3d(80, 20, 20));
            t.Add(new Point3d(80, 20, 20));
            t.Add(new Point3d(80, 25, 30));
            t.Add(new Point3d(80, 25, 45));
            t.Add(new Point3d(125, 55, 56));
            t.Add(new Point3d(125, 70, 56));
            t.Add(new Point3d(158, 50, 70));
            t.Add(new Point3d(128, 75, 65));

            Figure = new ShapeB(4, 4, t.ToArray());

            ////-------------------------------
            //// Build curve

            t.Clear();
            t.Add(new Point3d(50, -50, 20));
            t.Add(new Point3d(80, -25, 30));
            t.Add(new Point3d(90, 30, 30));
            t.Add(new Point3d(40, 50, 0));

            Curve = new CurveB(20, t.ToArray());

            t.Clear();

            Build();

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
		
		private void Build()
		{
			kon_curve_Or = Curve.getCurve();
			kon_shape_Or = Figure.getShape();
			IntersectPoints = new List<Point3d>();
			getIntersectPoints(kon_shape_Or, kon_curve_Or, ref IntersectPoints);
		}

        private void DrawBox1_Paint(object sender, PaintEventArgs e)
        {
            List<Point3d> kon_osi_Pr_3d = new List<Point3d>();
			List<Point2d> kon_osi_Pr = new List<Point2d>();
            transform(kon_osi_Or, ref kon_osi_Pr_3d);
            to2d(kon_osi_Pr_3d, ref kon_osi_Pr);

            Graphics paint1 = e.Graphics;
            paint1.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;

            draw_osi(paint1, new Pen(Color.Coral, 1), kon_osi_Pr);

            //List<Point3d> c = Curve.getCurve();
            List<Point3d> kon_curve_3dPr = new List<Point3d>();
            List<Point2d> kon_curve_2dPr = new List<Point2d>();
            transform(kon_curve_Or, ref kon_curve_3dPr);
            to2d(kon_curve_3dPr, ref kon_curve_2dPr);
            draw_curve(paint1, new Pen(Color.Red, 1), kon_curve_2dPr);

            //List<List<Point3d>> t = ;
            List<List<Point2d>> kon_shape_2dPr = new List<List<Point2d>>();

            foreach (List<Point3d> i in kon_shape_Or)
            {
                List<Point3d> t_3dPr = new List<Point3d>();
                List<Point2d> t_2dPr = new List<Point2d>();
                transform(i, ref t_3dPr);
                to2d(t_3dPr, ref t_2dPr);
                kon_shape_2dPr.Add(t_2dPr);
            }

            foreach (List<Point2d> i in kon_shape_2dPr)
                draw_curve(paint1, new Pen(Color.Green, 1), i);


            //List<Point3d> finding = new List<Point3d>();
            List<Point3d> t_finding = new List<Point3d>();
            List<Point2d> t_finding_p = new List<Point2d>();
            transform(IntersectPoints, ref t_finding);
            to2d(t_finding, ref t_finding_p);
            float ye = (float)SIZE.Value;
            foreach (Point2d i in t_finding_p)
                //draw_curve(paint1, new Pen(Color.Blue, 1), i);
                paint1.DrawEllipse(new Pen(Color.White, 1), to_x(i.x * ye), to_y(i.y * ye), 3, 3);
            return;
        }

        private void Ev_rot_OX_ValueChanged(object sender, EventArgs e)
        {
            DrawBox1.Invalidate();
        }

        private void Ev_rot_OY_ValueChanged(object sender, EventArgs e)
        {
            DrawBox1.Invalidate();
        }

        private void Ev_rot_OZ_ValueChanged(object sender, EventArgs e)
        {
            DrawBox1.Invalidate();
        }

        private void Ev_cen_x_ValueChanged(object sender, EventArgs e)
        {
            DrawBox1.Invalidate();
        }

        private void Ev_cen_y_ValueChanged(object sender, EventArgs e)
        {
            DrawBox1.Invalidate();
        }

        private void Ev_cen_z_ValueChanged(object sender, EventArgs e)
        {
            DrawBox1.Invalidate();
        }

        private void pr_pl_Z_ValueChanged(object sender, EventArgs e)
        {
            DrawBox1.Invalidate();
        }

        private void SIZE_ValueChanged(object sender, EventArgs e)
        {
            DrawBox1.Invalidate();
        }
    }
}
