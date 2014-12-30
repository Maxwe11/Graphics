namespace gmo_lab02
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.SIZE = new System.Windows.Forms.NumericUpDown();
            this.label10 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.pr_pl_Z = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.Ev_cen_z = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.Ev_rot_OZ = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.Ev_rot_OY = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.Ev_rot_OX = new System.Windows.Forms.NumericUpDown();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.Ev_cen_y = new System.Windows.Forms.NumericUpDown();
            this.Ev_cen_x = new System.Windows.Forms.NumericUpDown();
            this.label5 = new System.Windows.Forms.Label();
            this.DrawBox1 = new System.Windows.Forms.PictureBox();
            this.label13 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.label15 = new System.Windows.Forms.Label();
            this.label16 = new System.Windows.Forms.Label();
            this.numericUpDownA = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownB = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownC = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownD = new System.Windows.Forms.NumericUpDown();
            this.label17 = new System.Windows.Forms.Label();
            this.numericUpDownSX = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownSY = new System.Windows.Forms.NumericUpDown();
            this.label18 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.SIZE)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pr_pl_Z)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Ev_cen_z)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Ev_rot_OZ)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Ev_rot_OY)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Ev_rot_OX)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Ev_cen_y)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Ev_cen_x)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.DrawBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownA)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownB)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownC)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownD)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownSX)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownSY)).BeginInit();
            this.SuspendLayout();
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.label11.Location = new System.Drawing.Point(149, 611);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(54, 13);
            this.label11.TabIndex = 57;
            this.label11.Text = "Размеры";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.label12.Location = new System.Drawing.Point(149, 629);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(36, 13);
            this.label12.TabIndex = 56;
            this.label12.Text = "Size =";
            // 
            // SIZE
            // 
            this.SIZE.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.SIZE.Location = new System.Drawing.Point(191, 627);
            this.SIZE.Maximum = new decimal(new int[] {
            15,
            0,
            0,
            0});
            this.SIZE.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.SIZE.Name = "SIZE";
            this.SIZE.Size = new System.Drawing.Size(69, 20);
            this.SIZE.TabIndex = 55;
            this.SIZE.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.SIZE.ValueChanged += new System.EventHandler(this.SIZE_ValueChanged);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.label10.Location = new System.Drawing.Point(262, 606);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(149, 13);
            this.label10.TabIndex = 54;
            this.label10.Text = "Проектируем на плоскость:";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.label9.Location = new System.Drawing.Point(314, 624);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(23, 13);
            this.label9.TabIndex = 53;
            this.label9.Text = "Z =";
            // 
            // pr_pl_Z
            // 
            this.pr_pl_Z.Location = new System.Drawing.Point(342, 622);
            this.pr_pl_Z.Maximum = new decimal(new int[] {
            360,
            0,
            0,
            0});
            this.pr_pl_Z.Minimum = new decimal(new int[] {
            360,
            0,
            0,
            -2147483648});
            this.pr_pl_Z.Name = "pr_pl_Z";
            this.pr_pl_Z.Size = new System.Drawing.Size(69, 20);
            this.pr_pl_Z.TabIndex = 52;
            this.pr_pl_Z.ValueChanged += new System.EventHandler(this.pr_pl_Z_ValueChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.label4.Location = new System.Drawing.Point(659, 644);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(14, 13);
            this.label4.TabIndex = 51;
            this.label4.Text = "Z";
            // 
            // Ev_cen_z
            // 
            this.Ev_cen_z.Location = new System.Drawing.Point(679, 642);
            this.Ev_cen_z.Maximum = new decimal(new int[] {
            360,
            0,
            0,
            0});
            this.Ev_cen_z.Minimum = new decimal(new int[] {
            360,
            0,
            0,
            -2147483648});
            this.Ev_cen_z.Name = "Ev_cen_z";
            this.Ev_cen_z.Size = new System.Drawing.Size(69, 20);
            this.Ev_cen_z.TabIndex = 50;
            this.Ev_cen_z.ValueChanged += new System.EventHandler(this.Ev_cen_z_ValueChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.label3.Location = new System.Drawing.Point(525, 639);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(22, 13);
            this.label3.TabIndex = 49;
            this.label3.Text = "OZ";
            // 
            // Ev_rot_OZ
            // 
            this.Ev_rot_OZ.Location = new System.Drawing.Point(553, 637);
            this.Ev_rot_OZ.Maximum = new decimal(new int[] {
            360,
            0,
            0,
            0});
            this.Ev_rot_OZ.Minimum = new decimal(new int[] {
            360,
            0,
            0,
            -2147483648});
            this.Ev_rot_OZ.Name = "Ev_rot_OZ";
            this.Ev_rot_OZ.Size = new System.Drawing.Size(69, 20);
            this.Ev_rot_OZ.TabIndex = 48;
            this.Ev_rot_OZ.ValueChanged += new System.EventHandler(this.Ev_rot_OZ_ValueChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.label2.Location = new System.Drawing.Point(525, 613);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(22, 13);
            this.label2.TabIndex = 47;
            this.label2.Text = "OY";
            // 
            // Ev_rot_OY
            // 
            this.Ev_rot_OY.Location = new System.Drawing.Point(553, 611);
            this.Ev_rot_OY.Maximum = new decimal(new int[] {
            360,
            0,
            0,
            0});
            this.Ev_rot_OY.Minimum = new decimal(new int[] {
            360,
            0,
            0,
            -2147483648});
            this.Ev_rot_OY.Name = "Ev_rot_OY";
            this.Ev_rot_OY.Size = new System.Drawing.Size(69, 20);
            this.Ev_rot_OY.TabIndex = 46;
            this.Ev_rot_OY.ValueChanged += new System.EventHandler(this.Ev_rot_OY_ValueChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.label1.Location = new System.Drawing.Point(525, 587);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(22, 13);
            this.label1.TabIndex = 45;
            this.label1.Text = "OX";
            // 
            // Ev_rot_OX
            // 
            this.Ev_rot_OX.Location = new System.Drawing.Point(553, 585);
            this.Ev_rot_OX.Maximum = new decimal(new int[] {
            360,
            0,
            0,
            0});
            this.Ev_rot_OX.Minimum = new decimal(new int[] {
            360,
            0,
            0,
            -2147483648});
            this.Ev_rot_OX.Name = "Ev_rot_OX";
            this.Ev_rot_OX.Size = new System.Drawing.Size(69, 20);
            this.Ev_rot_OX.TabIndex = 44;
            this.Ev_rot_OX.ValueChanged += new System.EventHandler(this.Ev_rot_OX_ValueChanged);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.label6.Location = new System.Drawing.Point(647, 568);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(110, 13);
            this.label6.TabIndex = 43;
            this.label6.Text = "Относительно точки";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.label7.Location = new System.Drawing.Point(659, 618);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(14, 13);
            this.label7.TabIndex = 42;
            this.label7.Text = "Y";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.label8.Location = new System.Drawing.Point(659, 592);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(14, 13);
            this.label8.TabIndex = 41;
            this.label8.Text = "X";
            // 
            // Ev_cen_y
            // 
            this.Ev_cen_y.Location = new System.Drawing.Point(679, 616);
            this.Ev_cen_y.Maximum = new decimal(new int[] {
            300,
            0,
            0,
            0});
            this.Ev_cen_y.Minimum = new decimal(new int[] {
            300,
            0,
            0,
            -2147483648});
            this.Ev_cen_y.Name = "Ev_cen_y";
            this.Ev_cen_y.Size = new System.Drawing.Size(69, 20);
            this.Ev_cen_y.TabIndex = 40;
            this.Ev_cen_y.ValueChanged += new System.EventHandler(this.Ev_cen_y_ValueChanged);
            // 
            // Ev_cen_x
            // 
            this.Ev_cen_x.Location = new System.Drawing.Point(679, 590);
            this.Ev_cen_x.Maximum = new decimal(new int[] {
            300,
            0,
            0,
            0});
            this.Ev_cen_x.Minimum = new decimal(new int[] {
            300,
            0,
            0,
            -2147483648});
            this.Ev_cen_x.Name = "Ev_cen_x";
            this.Ev_cen_x.Size = new System.Drawing.Size(69, 20);
            this.Ev_cen_x.TabIndex = 39;
            this.Ev_cen_x.ValueChanged += new System.EventHandler(this.Ev_cen_x_ValueChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.label5.Location = new System.Drawing.Point(463, 569);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(168, 13);
            this.label5.TabIndex = 38;
            this.label5.Text = "Повернуть поверхность на угол";
            // 
            // DrawBox1
            // 
            this.DrawBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.DrawBox1.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.DrawBox1.Cursor = System.Windows.Forms.Cursors.Cross;
            this.DrawBox1.Location = new System.Drawing.Point(1, 0);
            this.DrawBox1.Name = "DrawBox1";
            this.DrawBox1.Size = new System.Drawing.Size(1023, 560);
            this.DrawBox1.TabIndex = 37;
            this.DrawBox1.TabStop = false;
            this.DrawBox1.Paint += new System.Windows.Forms.PaintEventHandler(this.DrawBox1_Paint);
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(11, 568);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(25, 13);
            this.label13.TabIndex = 58;
            this.label13.Text = "L = ";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(105, 568);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(26, 13);
            this.label14.TabIndex = 59;
            this.label14.Text = "X + ";
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(189, 568);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(26, 13);
            this.label15.TabIndex = 60;
            this.label15.Text = "Y + ";
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(282, 568);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(26, 13);
            this.label16.TabIndex = 61;
            this.label16.Text = "Z + ";
            // 
            // numericUpDownA
            // 
            this.numericUpDownA.DecimalPlaces = 1;
            this.numericUpDownA.Increment = new decimal(new int[] {
            5,
            0,
            0,
            65536});
            this.numericUpDownA.Location = new System.Drawing.Point(42, 566);
            this.numericUpDownA.Maximum = new decimal(new int[] {
            200,
            0,
            0,
            0});
            this.numericUpDownA.Minimum = new decimal(new int[] {
            200,
            0,
            0,
            -2147483648});
            this.numericUpDownA.Name = "numericUpDownA";
            this.numericUpDownA.Size = new System.Drawing.Size(57, 20);
            this.numericUpDownA.TabIndex = 62;
            this.numericUpDownA.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownA.ValueChanged += new System.EventHandler(this.numericUpDownA_ValueChanged);
            // 
            // numericUpDownB
            // 
            this.numericUpDownB.DecimalPlaces = 1;
            this.numericUpDownB.Increment = new decimal(new int[] {
            5,
            0,
            0,
            65536});
            this.numericUpDownB.Location = new System.Drawing.Point(126, 566);
            this.numericUpDownB.Maximum = new decimal(new int[] {
            200,
            0,
            0,
            0});
            this.numericUpDownB.Minimum = new decimal(new int[] {
            200,
            0,
            0,
            -2147483648});
            this.numericUpDownB.Name = "numericUpDownB";
            this.numericUpDownB.Size = new System.Drawing.Size(57, 20);
            this.numericUpDownB.TabIndex = 63;
            this.numericUpDownB.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownB.ValueChanged += new System.EventHandler(this.numericUpDownB_ValueChanged);
            // 
            // numericUpDownC
            // 
            this.numericUpDownC.DecimalPlaces = 1;
            this.numericUpDownC.Increment = new decimal(new int[] {
            5,
            0,
            0,
            65536});
            this.numericUpDownC.Location = new System.Drawing.Point(219, 566);
            this.numericUpDownC.Maximum = new decimal(new int[] {
            200,
            0,
            0,
            0});
            this.numericUpDownC.Minimum = new decimal(new int[] {
            200,
            0,
            0,
            -2147483648});
            this.numericUpDownC.Name = "numericUpDownC";
            this.numericUpDownC.Size = new System.Drawing.Size(57, 20);
            this.numericUpDownC.TabIndex = 64;
            this.numericUpDownC.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownC.ValueChanged += new System.EventHandler(this.numericUpDownC_ValueChanged);
            // 
            // numericUpDownD
            // 
            this.numericUpDownD.DecimalPlaces = 1;
            this.numericUpDownD.Increment = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numericUpDownD.Location = new System.Drawing.Point(305, 566);
            this.numericUpDownD.Maximum = new decimal(new int[] {
            1200,
            0,
            0,
            0});
            this.numericUpDownD.Minimum = new decimal(new int[] {
            1200,
            0,
            0,
            -2147483648});
            this.numericUpDownD.Name = "numericUpDownD";
            this.numericUpDownD.Size = new System.Drawing.Size(57, 20);
            this.numericUpDownD.TabIndex = 65;
            this.numericUpDownD.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownD.ValueChanged += new System.EventHandler(this.numericUpDownD_ValueChanged);
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(12, 606);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(34, 13);
            this.label17.TabIndex = 66;
            this.label17.Text = "stepX";
            // 
            // numericUpDownSX
            // 
            this.numericUpDownSX.DecimalPlaces = 2;
            this.numericUpDownSX.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.numericUpDownSX.Location = new System.Drawing.Point(59, 604);
            this.numericUpDownSX.Maximum = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numericUpDownSX.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.numericUpDownSX.Name = "numericUpDownSX";
            this.numericUpDownSX.Size = new System.Drawing.Size(64, 20);
            this.numericUpDownSX.TabIndex = 67;
            this.numericUpDownSX.Value = new decimal(new int[] {
            5,
            0,
            0,
            65536});
            this.numericUpDownSX.ValueChanged += new System.EventHandler(this.numericUpDownSX_ValueChanged);
            // 
            // numericUpDownSY
            // 
            this.numericUpDownSY.DecimalPlaces = 2;
            this.numericUpDownSY.Location = new System.Drawing.Point(59, 630);
            this.numericUpDownSY.Maximum = new decimal(new int[] {
            150,
            0,
            0,
            0});
            this.numericUpDownSY.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.numericUpDownSY.Name = "numericUpDownSY";
            this.numericUpDownSY.Size = new System.Drawing.Size(64, 20);
            this.numericUpDownSY.TabIndex = 69;
            this.numericUpDownSY.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownSY.ValueChanged += new System.EventHandler(this.numericUpDownSY_ValueChanged);
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(12, 632);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(34, 13);
            this.label18.TabIndex = 68;
            this.label18.Text = "stepY";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1022, 665);
            this.Controls.Add(this.numericUpDownSY);
            this.Controls.Add(this.label18);
            this.Controls.Add(this.numericUpDownSX);
            this.Controls.Add(this.label17);
            this.Controls.Add(this.numericUpDownD);
            this.Controls.Add(this.numericUpDownC);
            this.Controls.Add(this.numericUpDownB);
            this.Controls.Add(this.numericUpDownA);
            this.Controls.Add(this.label16);
            this.Controls.Add(this.label15);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.SIZE);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.pr_pl_Z);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.Ev_cen_z);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.Ev_rot_OZ);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.Ev_rot_OY);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Ev_rot_OX);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.Ev_cen_y);
            this.Controls.Add(this.Ev_cen_x);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.DrawBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.SIZE)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pr_pl_Z)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Ev_cen_z)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Ev_rot_OZ)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Ev_rot_OY)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Ev_rot_OX)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Ev_cen_y)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Ev_cen_x)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.DrawBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownA)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownB)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownC)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownD)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownSX)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownSY)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.NumericUpDown SIZE;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.NumericUpDown pr_pl_Z;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown Ev_cen_z;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.NumericUpDown Ev_rot_OZ;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.NumericUpDown Ev_rot_OY;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown Ev_rot_OX;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.NumericUpDown Ev_cen_y;
        private System.Windows.Forms.NumericUpDown Ev_cen_x;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.PictureBox DrawBox1;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.NumericUpDown numericUpDownA;
        private System.Windows.Forms.NumericUpDown numericUpDownB;
        private System.Windows.Forms.NumericUpDown numericUpDownC;
        private System.Windows.Forms.NumericUpDown numericUpDownD;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.NumericUpDown numericUpDownSX;
        private System.Windows.Forms.NumericUpDown numericUpDownSY;
        private System.Windows.Forms.Label label18;
    }
}

