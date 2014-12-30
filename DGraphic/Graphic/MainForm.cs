using System;
using System.Linq;
using System.Drawing;
using System.Windows.Forms;

namespace Graphic
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            this.length_ = 160;
            this.height_ = 170;
            this.big_circle_d = 50;
            this.small_circle_d = 28;
            this.outside_r = 64;
            this.inside1_r = 32;
            this.inside2_r = 80;
            this.inside3_r = 52;
            this.show_points = false;
            this.amount_of_points = 28;
            this.grid_step = 10;
            this.current_point_selected = 0;
            
            InitializeComponent();

            this.XCoordTB.Text = point[0].X.ToString();
            this.YCoordTB.Text = point[0].Y.ToString();
        }

        private void DrawDot(Graphics g, PointF point, float rad, Brush br)
        {
            g.FillEllipse(br, point.X - 0.5f * rad, -point.Y - 0.5f * rad, rad, rad);
        }

        private void DrawLine(Graphics g, float x1, float y1, float x2, float y2, Pen pen)
        {
            g.DrawLine(pen, x1, -y1, x2, -y2);
        }

        private void DrawArc(Graphics g, float x, float y, float radius, double begin_angel, double end_angel, Pen pen)
        {
            begin_angel *= Math.PI / 180.0;
            end_angel   *= Math.PI / 180.0;

            float begin_x = x + (float)(radius * Math.Cos(begin_angel));
            float begin_y = y + (float)(radius * Math.Sin(begin_angel));

            float step = (float)(end_angel - begin_angel) / Convert.ToSingle(amount_of_points);
            end_angel += step;
            for (float i = (float)begin_angel + step; i < end_angel; i += step)
            {
                float new_x = x + (float)(radius * Math.Cos(i));
                float new_y = y + (float)(radius * Math.Sin(i));

                DrawLine(g, begin_x, begin_y, new_x, new_y, pen);

                begin_x = new_x;
                begin_y = new_y;
            }
        }

        private void DrawCircle(Graphics g, float x, float y, float radius, Pen p)
        {
            DrawArc(g, x, y, radius, 0.0, 360.0, p);
        }

        private void DrawGrid(Graphics g)
        {
            Pen pen = new Pen(new SolidBrush(Color.Cyan));

            int delta = 365 / this.grid_step, tmp;

            for (int i = -delta; i <= delta; ++i)
            {
                tmp = i * this.grid_step;
                DrawLine(g, tmp, -225, tmp, 225, pen);
            }

            delta = 225 / this.grid_step;
            for (int i = -delta; i <= delta; ++i)
            {
                tmp = i * this.grid_step;
                DrawLine(g, -365, tmp, 365, tmp, pen); 
            }
        }

        private void DrawAxis(Graphics g)
        {
            SolidBrush br = new SolidBrush(Color.Black);
            Pen pen = new Pen(br);
            DrawLine(g, -365.0f, 0.0f, 365.0f, 0.0f, pen);
            DrawLine(g, 0.0f, -225.0f, 0.0f, 225.0f, pen);

            DrawLine(g, 0.0f, 225.0f, 10.0f, 200.0f, pen);
            DrawLine(g, 0.0f, 225.0f, -10.0f, 200.0f, pen);
 
            DrawLine(g, 365.0f, 0.0f, 340.0f, 10.0f, pen);
            DrawLine(g, 365.0f, 0.0f, 340.0f, -10.0f, pen);
            
            Font font = new System.Drawing.Font("Calibri", 20.0f);
            g.DrawString("X", font, br, 340.0f, -38.0f);
            g.DrawString("Y", font, br, 10.0f, -220.0f);
        }

        private void DrawDetail(Graphics g)
        {
            SolidBrush solid_br = new SolidBrush(Color.Black);
            Pen pen = new Pen(solid_br, 2.5f);

            float len = length_ / 2.0f;
            float hgt = height_ / 2.0f;

            DrawCircle(g, -len, -hgt, small_circle_d / 2, pen);
            DrawCircle(g, -len, hgt, big_circle_d / 2, pen);
            DrawCircle(g, len, 0, big_circle_d / 2, pen);

            {
                this.point[0] = new PointF(-len, -hgt);
                this.point[1] = new PointF(-len,  hgt);
                this.point[2] = new PointF( len, 0.0f);
            }

            float outside_x, outside_y;
            double inside1_angel_begin, inside1_angel_end;
            double inside2_angel_begin, inside2_angel_end;
            double inside3_angel_begin, inside3_angel_end;
            double outside_angel_begin, outside_angel_end;
            float outside_x_begin, outside_y_begin;
            float outside_x_end, outside_y_end;
            float hx1, hy1, hx2, hy2;
            float lx1, ly1, lx2, ly2;

            {
                float r1 = (float)(inside1_r + outside_r);
                float r2 = (float)(inside3_r + outside_r);

                double tmp = (double)(r2 * r2 - r1 * r1 + height_ * height_) / (2.0 * height_);
                outside_x = -len - (float)(Math.Sqrt((double)(r2 * r2) - tmp * tmp));
                outside_y = hgt - (float)(tmp);

                tmp = (-hgt - outside_y) / (-len - outside_x);
                outside_angel_begin = Math.Atan(tmp) * 180.0 / Math.PI;

                tmp = (hgt - outside_y) / (-len - outside_x);
                outside_angel_end = Math.Atan(tmp) * 180.0 / Math.PI;

                inside1_angel_begin = 180.0 + outside_angel_begin;
                inside3_angel_end = 180.0 + outside_angel_end;
                
                {
                    outside_x_begin = -len + (float)(this.inside1_r * Math.Cos(inside1_angel_begin * Math.PI / 180.0));
                    outside_y_begin = -hgt + (float)(this.inside1_r * Math.Sin(inside1_angel_begin * Math.PI / 180.0));
                    outside_x_end   = -len + (float)(this.inside3_r * Math.Cos(inside3_angel_end * Math.PI / 180.0));
                    outside_y_end   =  hgt + (float)(this.inside3_r * Math.Sin(inside3_angel_end * Math.PI / 180.0));

                    this.point[3] = new PointF(outside_x, outside_y);
                    this.point[4] = new PointF(outside_x_begin, outside_y_begin);
                    this.point[5] = new PointF(outside_x_end, outside_y_end);
                }
            }

            {
                float base_hip = (float)Math.Sqrt((double)(length_ * length_ + hgt * hgt));

                inside3_angel_begin = /*0.5 * Math.PI - Math.Acos((this.inside2_r - this.inside3_r) / base_hip) + */Math.Atan(length_ / hgt);
                inside1_angel_end = /*-0.5 * Math.PI + Math.Acos((this.inside2_r - this.inside1_r) / base_hip)*/ -Math.Atan(length_ / hgt);

                if (this.inside2_r >= this.inside3_r)
                    inside3_angel_begin += 0.5 * Math.PI - Math.Acos((this.inside2_r - this.inside3_r) / base_hip);
                else
                    inside3_angel_begin -= 0.5 * Math.PI - Math.Acos((this.inside3_r - this.inside2_r) / base_hip);

                if (this.inside2_r >= this.inside1_r)
                    inside1_angel_end += -0.5 * Math.PI + Math.Acos((this.inside2_r - this.inside1_r) / base_hip);
                else
                    inside1_angel_end -= -0.5 * Math.PI + Math.Acos((this.inside1_r - this.inside2_r) / base_hip);

                hx1 = (float)(this.inside3_r * Math.Cos(inside3_angel_begin)) - len;
                hy1 = (float)(this.inside3_r * Math.Sin(inside3_angel_begin)) + hgt;

                hx2 = (float)(this.inside2_r * Math.Cos(inside3_angel_begin)) + len;
                hy2 = (float)(this.inside2_r * Math.Sin(inside3_angel_begin));

                lx1 = (float)(this.inside1_r * Math.Cos(inside1_angel_end)) - len;
                ly1 = (float)(this.inside1_r * Math.Sin(inside1_angel_end)) - hgt;

                lx2 = (float)(this.inside2_r * Math.Cos(inside1_angel_end)) + len;
                ly2 = (float)(this.inside2_r * Math.Sin(inside1_angel_end));

                {
                    this.point[6] = new PointF(hx1, hy1);
                    this.point[7] = new PointF(hx2, hy2);
                    this.point[8] = new PointF(lx1, ly1);
                    this.point[9] = new PointF(lx2, ly2);
                }

                inside1_angel_end *= 180.0 / Math.PI;
                inside3_angel_begin *= 180.0 / Math.PI;
                inside2_angel_begin = inside1_angel_end;
                inside2_angel_end = inside3_angel_begin;
                inside1_angel_end += 360.0;
            }

            {
                DrawLine(g, hx1, hy1, hx2, hy2, pen);
                DrawLine(g, lx1, ly1, lx2, ly2, pen);

                DrawArc(g, -len, -hgt, inside1_r, inside1_angel_begin, inside1_angel_end, pen);
                DrawArc(g, outside_x, outside_y, outside_r, outside_angel_begin, outside_angel_end, pen);
                DrawArc(g, -len, hgt, inside3_r, inside3_angel_begin, inside3_angel_end, pen);

                DrawArc(g, len, 0, inside2_r, inside2_angel_begin, inside2_angel_end, pen);
            }

            if (this.show_points == true)
            {
                float dot_w = 8.0f;
                foreach (PointF t in this.point)
                {
                    DrawDot(g, t, dot_w, solid_br);
                }
                SolidBrush red_br = new SolidBrush(Color.Red);
                DrawDot(g, point[this.current_point_selected], dot_w, red_br);
            }
        }

        private float LenghtBetweenPoints(PointF p1, PointF p2)
        {
            return (float)Math.Sqrt((p2.X - p1.X) * (p2.X - p1.X) + (p2.Y - p1.Y) * (p2.Y - p1.Y));
        }

        private void SceneMouseClick(object sender, MouseEventArgs e)
        {
            PointF p = new PointF(e.X - 365, -e.Y + 225);

            float[] arr = new float[10];

            for (int i = 0; i < 10; ++i)
            {
                arr[i] = LenghtBetweenPoints(p, this.point[i]);
            }

            this.current_point_selected = Array.IndexOf(arr, arr.Min(), 0);

            this.XCoordTB.Text = (this.point[this.current_point_selected].X / this.grid_step).ToString();
            this.YCoordTB.Text = (this.point[this.current_point_selected].Y / this.grid_step).ToString();
            this.Scene.Invalidate();
        }

        private void ScenePaint(object sender, PaintEventArgs e)
        {
            e.Graphics.TranslateTransform(365.0f, 225.0f);
            //e.Graphics.ScaleTransform(1.5f, 1.5f);
            e.Graphics.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            DrawGrid(e.Graphics);
            DrawAxis(e.Graphics);
            DrawDetail(e.Graphics);
        }

        private void GridStepEditValueChanged(object sender, EventArgs e)
        {
            NumericUpDown t = sender as NumericUpDown;
            this.grid_step = (int)t.Value;
            this.XCoordTB.Text = (this.point[this.current_point_selected].X / this.grid_step).ToString();
            this.YCoordTB.Text = (this.point[this.current_point_selected].Y / this.grid_step).ToString();
            this.Scene.Invalidate();
        }

        private void LengthEditValueChanged(object sender, EventArgs e)
        {
            NumericUpDown t = sender as NumericUpDown;
            this.length_ = (int)t.Value;
            this.Scene.Invalidate();
        }

        private void HeigthEditValueChanged(object sender, EventArgs e)
        {
            NumericUpDown t = sender as NumericUpDown;
            t.Minimum = (decimal)(this.small_circle_d / 2 + this.big_circle_d / 2);
            //t.Maximum = (decimal)(450 - 2 * Math.Max(this.inside1_r, this.inside3_r));
            t.Maximum = (decimal)(this.inside1_r + 2 * this.outside_r + this.inside3_r);
            this.height_ = (int)t.Value;
            this.Scene.Invalidate();
        }

        private void BigHoleDEditValueChanged(object sender, EventArgs e)
        {
            NumericUpDown t = sender as NumericUpDown;
            t.Maximum = (decimal)(Math.Min(2 * this.inside2_r, 2 * this.inside3_r));
            this.big_circle_d = (int)t.Value;
            this.Scene.Invalidate();
        }

        private void SmallHoleDEditValueChanged(object sender, EventArgs e)
        {
            NumericUpDown t = sender as NumericUpDown;
            t.Maximum = (decimal)(2 * this.inside1_r);
            this.small_circle_d = (int)t.Value;
            this.Scene.Invalidate();
        }

        private void OutsideREditValueChanged(object sender, EventArgs e)
        {
            NumericUpDown t = sender as NumericUpDown;
            t.Minimum = (decimal)((this.height_ - this.inside3_r - this.inside1_r) / 2);
            this.outside_r = (int)t.Value;
            this.Scene.Invalidate();
        }

        private void InsideR1EditValueChanged(object sender, EventArgs e)
        {
            NumericUpDown t = sender as NumericUpDown;
            t.Minimum = (decimal)(this.small_circle_d / 2);
            this.inside1_r = (int)t.Value;
            this.Scene.Invalidate();
        }

        private void InsideR2EditValueChanged(object sender, EventArgs e)
        {
            NumericUpDown t = sender as NumericUpDown;
            t.Minimum = (decimal)(this.big_circle_d / 2);
            this.inside2_r = (int)t.Value;
            this.Scene.Invalidate();
        }

        private void InsideR3EditValueChanged(object sender, EventArgs e)
        {
            NumericUpDown t = sender as NumericUpDown;
            t.Minimum = (decimal)(this.big_circle_d / 2);
            this.inside3_r = (int)t.Value;
            this.Scene.Invalidate();
        }

        private void AmountOfPointsEditValueChanged(object sender, EventArgs e)
        {
            NumericUpDown t = sender as NumericUpDown;
            this.amount_of_points = (int)t.Value;
            this.Scene.Invalidate();
        }

        private void ShowPointsCheckBoxCheckStateChanged(object sender, EventArgs e)
        {
            CheckBox t = sender as CheckBox;
            this.show_points = t.Checked;
            this.XCoordTB.Text = point[0].X.ToString();
            this.YCoordTB.Text = point[0].Y.ToString();
            this.Scene.Invalidate();
        }
    }
}
