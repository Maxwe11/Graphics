using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace gr1
{
    public partial class Form1 : Form
    {
        private Model model = new Model();

        private void Init()
        {
            Point p1 = new Point(numericUpDown1X.Value, numericUpDown1Y.Value);
            Point p2 = new Point(numericUpDown2X.Value, numericUpDown2Y.Value);
            Point p3 = new Point(numericUpDown3X.Value, numericUpDown3Y.Value);
            Point p4 = new Point(numericUpDown4X.Value, numericUpDown4Y.Value);
            Point p5 = new Point(numericUpDown5X.Value, numericUpDown5Y.Value);

            Point c = new Point(numericUpDownCX.Value, numericUpDownCY.Value);

            model.SetP(p1, p2, p3, p4, p5);
            model.SetC(c);        
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            model.Paint(e.Graphics);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Init();
            pictureBox1.Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Init();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Point p1 = new Point(numericUpDown1X.Value, numericUpDown1Y.Value);
            Point p2 = new Point(numericUpDown2X.Value, numericUpDown2Y.Value);
            Point p3 = new Point(numericUpDown3X.Value, numericUpDown3Y.Value);
            Point p4 = new Point(numericUpDown4X.Value, numericUpDown4Y.Value);
            Point p5 = new Point(numericUpDown5X.Value, numericUpDown5Y.Value);

            model.Solution(new Point[]{p1,p2,p3,p4,p5});
            pictureBox1.Invalidate();
        }

        private void numericUpDown1X_ValueChanged(object sender, EventArgs e)
        {
            button2_Click(sender, e);
        }

        private void numericUpDown1Y_ValueChanged(object sender, EventArgs e)
        {
            button2_Click(sender, e);
        }

        private void numericUpDown2X_ValueChanged(object sender, EventArgs e)
        {
            button2_Click(sender, e);
        }

        private void numericUpDown2Y_ValueChanged(object sender, EventArgs e)
        {
            button2_Click(sender, e);
        }

        private void numericUpDown3X_ValueChanged(object sender, EventArgs e)
        {
            button2_Click(sender, e);
        }

        private void numericUpDown3Y_ValueChanged(object sender, EventArgs e)
        {
            button2_Click(sender, e);
        }
    }
}
