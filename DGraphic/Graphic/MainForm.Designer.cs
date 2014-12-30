namespace Graphic
{
    partial class MainForm
    {
        private int length_ = 160;
        private int height_ = 170;
        private int big_circle_d = 50;
        private int small_circle_d = 28;
        private int outside_r = 64;
        private int inside1_r = 32;
        private int inside2_r = 80;
        private int inside3_r = 52;

        private bool show_points = false;
        private int amount_of_points = 28;
        private int grid_step = 10;
        private int current_point_selected = 0;

        System.Drawing.PointF[] point = new System.Drawing.PointF [10];
        
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        private void InitializeComponent()
        {
            System.Windows.Forms.TabControl Tab;
            System.Windows.Forms.TabPage FirstTab;
            System.Windows.Forms.GroupBox CoordGroupBox;
            System.Windows.Forms.GroupBox groupBox1;
            System.Windows.Forms.Label YCoordLabel;
            System.Windows.Forms.Label XCoordLabel;
            System.Windows.Forms.GroupBox OtherGroupBox;
            System.Windows.Forms.CheckBox ShowPointsCheckBox;
            System.Windows.Forms.Label AmountOfPointsLabel;
            System.Windows.Forms.NumericUpDown AmountOfPointsEdit;
            System.Windows.Forms.Label GridStepLabel;
            System.Windows.Forms.NumericUpDown GridStepEdit;
            System.Windows.Forms.GroupBox DetailParams;
            System.Windows.Forms.Label InsideR3Label;
            System.Windows.Forms.NumericUpDown InsideR3Edit;
            System.Windows.Forms.Label InsideR2Label;
            System.Windows.Forms.NumericUpDown InsideR2Edit;
            System.Windows.Forms.Label InsideR1Label;
            System.Windows.Forms.NumericUpDown InsideR1Edit;
            System.Windows.Forms.Label OutsideRLabel;
            System.Windows.Forms.NumericUpDown OutsideREdit;
            System.Windows.Forms.Label SmallHoleLabel;
            System.Windows.Forms.NumericUpDown SmallHoleDEdit;
            System.Windows.Forms.Label BigHoleLabel;
            System.Windows.Forms.NumericUpDown BigHoleDEdit;
            System.Windows.Forms.Label HeightLabel;
            System.Windows.Forms.NumericUpDown HeigthEdit;
            System.Windows.Forms.Label LengthLabel;
            System.Windows.Forms.NumericUpDown LengthEdit;
            System.Windows.Forms.TabPage SecondTab;
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.YCoordTB = new System.Windows.Forms.TextBox();
            this.XCoordTB = new System.Windows.Forms.TextBox();
            this.Scene = new System.Windows.Forms.PictureBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            Tab = new System.Windows.Forms.TabControl();
            FirstTab = new System.Windows.Forms.TabPage();
            CoordGroupBox = new System.Windows.Forms.GroupBox();
            groupBox1 = new System.Windows.Forms.GroupBox();
            YCoordLabel = new System.Windows.Forms.Label();
            XCoordLabel = new System.Windows.Forms.Label();
            OtherGroupBox = new System.Windows.Forms.GroupBox();
            ShowPointsCheckBox = new System.Windows.Forms.CheckBox();
            AmountOfPointsLabel = new System.Windows.Forms.Label();
            AmountOfPointsEdit = new System.Windows.Forms.NumericUpDown();
            GridStepLabel = new System.Windows.Forms.Label();
            GridStepEdit = new System.Windows.Forms.NumericUpDown();
            DetailParams = new System.Windows.Forms.GroupBox();
            InsideR3Label = new System.Windows.Forms.Label();
            InsideR3Edit = new System.Windows.Forms.NumericUpDown();
            InsideR2Label = new System.Windows.Forms.Label();
            InsideR2Edit = new System.Windows.Forms.NumericUpDown();
            InsideR1Label = new System.Windows.Forms.Label();
            InsideR1Edit = new System.Windows.Forms.NumericUpDown();
            OutsideRLabel = new System.Windows.Forms.Label();
            OutsideREdit = new System.Windows.Forms.NumericUpDown();
            SmallHoleLabel = new System.Windows.Forms.Label();
            SmallHoleDEdit = new System.Windows.Forms.NumericUpDown();
            BigHoleLabel = new System.Windows.Forms.Label();
            BigHoleDEdit = new System.Windows.Forms.NumericUpDown();
            HeightLabel = new System.Windows.Forms.Label();
            HeigthEdit = new System.Windows.Forms.NumericUpDown();
            LengthLabel = new System.Windows.Forms.Label();
            LengthEdit = new System.Windows.Forms.NumericUpDown();
            SecondTab = new System.Windows.Forms.TabPage();
            Tab.SuspendLayout();
            FirstTab.SuspendLayout();
            CoordGroupBox.SuspendLayout();
            groupBox1.SuspendLayout();
            OtherGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(AmountOfPointsEdit)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(GridStepEdit)).BeginInit();
            DetailParams.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(InsideR3Edit)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(InsideR2Edit)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(InsideR1Edit)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(OutsideREdit)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(SmallHoleDEdit)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(BigHoleDEdit)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(HeigthEdit)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(LengthEdit)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Scene)).BeginInit();
            SecondTab.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // Tab
            // 
            Tab.Controls.Add(FirstTab);
            Tab.Controls.Add(SecondTab);
            Tab.Location = new System.Drawing.Point(-4, -2);
            Tab.Name = "Tab";
            Tab.SelectedIndex = 0;
            Tab.Size = new System.Drawing.Size(920, 516);
            Tab.TabIndex = 0;
            // 
            // FirstTab
            // 
            FirstTab.BackColor = System.Drawing.Color.WhiteSmoke;
            FirstTab.Controls.Add(CoordGroupBox);
            FirstTab.Controls.Add(OtherGroupBox);
            FirstTab.Controls.Add(DetailParams);
            FirstTab.Controls.Add(this.Scene);
            FirstTab.Location = new System.Drawing.Point(4, 22);
            FirstTab.Name = "FirstTab";
            FirstTab.Padding = new System.Windows.Forms.Padding(3);
            FirstTab.Size = new System.Drawing.Size(912, 490);
            FirstTab.TabIndex = 0;
            FirstTab.Text = "Деталь";
            // 
            // CoordGroupBox
            // 
            CoordGroupBox.Controls.Add(groupBox1);
            CoordGroupBox.Controls.Add(YCoordLabel);
            CoordGroupBox.Controls.Add(XCoordLabel);
            CoordGroupBox.Controls.Add(this.YCoordTB);
            CoordGroupBox.Controls.Add(this.XCoordTB);
            CoordGroupBox.Location = new System.Drawing.Point(763, 391);
            CoordGroupBox.Name = "CoordGroupBox";
            CoordGroupBox.Size = new System.Drawing.Size(135, 78);
            CoordGroupBox.TabIndex = 21;
            CoordGroupBox.TabStop = false;
            CoordGroupBox.Text = "Координаты точки:";
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(this.textBox3);
            groupBox1.Controls.Add(this.textBox4);
            groupBox1.Location = new System.Drawing.Point(756, 390);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new System.Drawing.Size(135, 78);
            groupBox1.TabIndex = 24;
            groupBox1.TabStop = false;
            groupBox1.Text = "Координаты точки:";
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(52, 50);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(74, 20);
            this.textBox3.TabIndex = 1;
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(52, 20);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(74, 20);
            this.textBox4.TabIndex = 0;
            // 
            // YCoordLabel
            // 
            YCoordLabel.AutoSize = true;
            YCoordLabel.Location = new System.Drawing.Point(17, 53);
            YCoordLabel.Name = "YCoordLabel";
            YCoordLabel.Size = new System.Drawing.Size(17, 13);
            YCoordLabel.TabIndex = 23;
            YCoordLabel.Text = "Y:";
            // 
            // XCoordLabel
            // 
            XCoordLabel.AutoSize = true;
            XCoordLabel.Location = new System.Drawing.Point(17, 23);
            XCoordLabel.Name = "XCoordLabel";
            XCoordLabel.Size = new System.Drawing.Size(17, 13);
            XCoordLabel.TabIndex = 22;
            XCoordLabel.Text = "X:";
            // 
            // YCoordTB
            // 
            this.YCoordTB.Location = new System.Drawing.Point(40, 50);
            this.YCoordTB.Name = "YCoordTB";
            this.YCoordTB.ReadOnly = true;
            this.YCoordTB.Size = new System.Drawing.Size(84, 20);
            this.YCoordTB.TabIndex = 1;
            this.YCoordTB.Text = "0.0";
            // 
            // XCoordTB
            // 
            this.XCoordTB.Location = new System.Drawing.Point(40, 20);
            this.XCoordTB.Name = "XCoordTB";
            this.XCoordTB.ReadOnly = true;
            this.XCoordTB.Size = new System.Drawing.Size(84, 20);
            this.XCoordTB.TabIndex = 0;
            this.XCoordTB.Text = "0.0";
            // 
            // OtherGroupBox
            // 
            OtherGroupBox.Controls.Add(ShowPointsCheckBox);
            OtherGroupBox.Controls.Add(AmountOfPointsLabel);
            OtherGroupBox.Controls.Add(AmountOfPointsEdit);
            OtherGroupBox.Controls.Add(GridStepLabel);
            OtherGroupBox.Controls.Add(GridStepEdit);
            OtherGroupBox.Location = new System.Drawing.Point(761, 284);
            OtherGroupBox.Name = "OtherGroupBox";
            OtherGroupBox.Size = new System.Drawing.Size(138, 100);
            OtherGroupBox.TabIndex = 20;
            OtherGroupBox.TabStop = false;
            OtherGroupBox.Text = "Доп. параметры";
            // 
            // ShowPointsCheckBox
            // 
            ShowPointsCheckBox.AutoSize = true;
            ShowPointsCheckBox.Location = new System.Drawing.Point(14, 76);
            ShowPointsCheckBox.Name = "ShowPointsCheckBox";
            ShowPointsCheckBox.Size = new System.Drawing.Size(118, 17);
            ShowPointsCheckBox.TabIndex = 22;
            ShowPointsCheckBox.Text = "показывать точки";
            ShowPointsCheckBox.UseVisualStyleBackColor = true;
            ShowPointsCheckBox.CheckStateChanged += new System.EventHandler(this.ShowPointsCheckBoxCheckStateChanged);
            // 
            // AmountOfPointsLabel
            // 
            AmountOfPointsLabel.AutoSize = true;
            AmountOfPointsLabel.Location = new System.Drawing.Point(4, 52);
            AmountOfPointsLabel.Name = "AmountOfPointsLabel";
            AmountOfPointsLabel.Size = new System.Drawing.Size(65, 13);
            AmountOfPointsLabel.TabIndex = 21;
            AmountOfPointsLabel.Text = "К-тво точек";
            // 
            // AmountOfPointsEdit
            // 
            AmountOfPointsEdit.Increment = new decimal(new int[] {
            4,
            0,
            0,
            0});
            AmountOfPointsEdit.Location = new System.Drawing.Point(69, 50);
            AmountOfPointsEdit.Maximum = new decimal(new int[] {
            60,
            0,
            0,
            0});
            AmountOfPointsEdit.Minimum = new decimal(new int[] {
            8,
            0,
            0,
            0});
            AmountOfPointsEdit.Name = "AmountOfPointsEdit";
            AmountOfPointsEdit.Size = new System.Drawing.Size(59, 20);
            AmountOfPointsEdit.TabIndex = 20;
            AmountOfPointsEdit.Value = new decimal(new int[] {
            28,
            0,
            0,
            0});
            AmountOfPointsEdit.ValueChanged += new System.EventHandler(this.AmountOfPointsEditValueChanged);
            // 
            // GridStepLabel
            // 
            GridStepLabel.AutoSize = true;
            GridStepLabel.Location = new System.Drawing.Point(4, 22);
            GridStepLabel.Name = "GridStepLabel";
            GridStepLabel.Size = new System.Drawing.Size(59, 13);
            GridStepLabel.TabIndex = 19;
            GridStepLabel.Text = "Шаг сетки";
            // 
            // GridStepEdit
            // 
            GridStepEdit.Increment = new decimal(new int[] {
            5,
            0,
            0,
            0});
            GridStepEdit.Location = new System.Drawing.Point(69, 20);
            GridStepEdit.Minimum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            GridStepEdit.Name = "GridStepEdit";
            GridStepEdit.Size = new System.Drawing.Size(59, 20);
            GridStepEdit.TabIndex = 17;
            GridStepEdit.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            GridStepEdit.ValueChanged += new System.EventHandler(this.GridStepEditValueChanged);
            // 
            // DetailParams
            // 
            DetailParams.Controls.Add(InsideR3Label);
            DetailParams.Controls.Add(InsideR3Edit);
            DetailParams.Controls.Add(InsideR2Label);
            DetailParams.Controls.Add(InsideR2Edit);
            DetailParams.Controls.Add(InsideR1Label);
            DetailParams.Controls.Add(InsideR1Edit);
            DetailParams.Controls.Add(OutsideRLabel);
            DetailParams.Controls.Add(OutsideREdit);
            DetailParams.Controls.Add(SmallHoleLabel);
            DetailParams.Controls.Add(SmallHoleDEdit);
            DetailParams.Controls.Add(BigHoleLabel);
            DetailParams.Controls.Add(BigHoleDEdit);
            DetailParams.Controls.Add(HeightLabel);
            DetailParams.Controls.Add(HeigthEdit);
            DetailParams.Controls.Add(LengthLabel);
            DetailParams.Controls.Add(LengthEdit);
            DetailParams.Location = new System.Drawing.Point(761, 20);
            DetailParams.Name = "DetailParams";
            DetailParams.Size = new System.Drawing.Size(138, 258);
            DetailParams.TabIndex = 18;
            DetailParams.TabStop = false;
            DetailParams.Text = "Параметры детали";
            // 
            // InsideR3Label
            // 
            InsideR3Label.AutoSize = true;
            InsideR3Label.Location = new System.Drawing.Point(18, 231);
            InsideR3Label.Name = "InsideR3Label";
            InsideR3Label.Size = new System.Drawing.Size(33, 13);
            InsideR3Label.TabIndex = 16;
            InsideR3Label.Text = "R3  =";
            // 
            // InsideR3Edit
            // 
            InsideR3Edit.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            InsideR3Edit.Location = new System.Drawing.Point(54, 229);
            InsideR3Edit.Maximum = new decimal(new int[] {
            500,
            0,
            0,
            0});
            InsideR3Edit.Name = "InsideR3Edit";
            InsideR3Edit.Size = new System.Drawing.Size(59, 20);
            InsideR3Edit.TabIndex = 15;
            InsideR3Edit.Value = new decimal(new int[] {
            52,
            0,
            0,
            0});
            InsideR3Edit.ValueChanged += new System.EventHandler(this.InsideR3EditValueChanged);
            // 
            // InsideR2Label
            // 
            InsideR2Label.AutoSize = true;
            InsideR2Label.Location = new System.Drawing.Point(18, 201);
            InsideR2Label.Name = "InsideR2Label";
            InsideR2Label.Size = new System.Drawing.Size(33, 13);
            InsideR2Label.TabIndex = 14;
            InsideR2Label.Text = "R2  =";
            // 
            // InsideR2Edit
            // 
            InsideR2Edit.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            InsideR2Edit.Location = new System.Drawing.Point(54, 199);
            InsideR2Edit.Maximum = new decimal(new int[] {
            210,
            0,
            0,
            0});
            InsideR2Edit.Name = "InsideR2Edit";
            InsideR2Edit.Size = new System.Drawing.Size(59, 20);
            InsideR2Edit.TabIndex = 13;
            InsideR2Edit.Value = new decimal(new int[] {
            80,
            0,
            0,
            0});
            InsideR2Edit.ValueChanged += new System.EventHandler(this.InsideR2EditValueChanged);
            // 
            // InsideR1Label
            // 
            InsideR1Label.AutoSize = true;
            InsideR1Label.Location = new System.Drawing.Point(18, 171);
            InsideR1Label.Name = "InsideR1Label";
            InsideR1Label.Size = new System.Drawing.Size(30, 13);
            InsideR1Label.TabIndex = 12;
            InsideR1Label.Text = "R1 =";
            // 
            // InsideR1Edit
            // 
            InsideR1Edit.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            InsideR1Edit.Location = new System.Drawing.Point(54, 169);
            InsideR1Edit.Maximum = new decimal(new int[] {
            500,
            0,
            0,
            0});
            InsideR1Edit.Name = "InsideR1Edit";
            InsideR1Edit.Size = new System.Drawing.Size(59, 20);
            InsideR1Edit.TabIndex = 11;
            InsideR1Edit.Value = new decimal(new int[] {
            32,
            0,
            0,
            0});
            InsideR1Edit.ValueChanged += new System.EventHandler(this.InsideR1EditValueChanged);
            // 
            // OutsideRLabel
            // 
            OutsideRLabel.AutoSize = true;
            OutsideRLabel.Location = new System.Drawing.Point(23, 141);
            OutsideRLabel.Name = "OutsideRLabel";
            OutsideRLabel.Size = new System.Drawing.Size(25, 13);
            OutsideRLabel.TabIndex = 10;
            OutsideRLabel.Text = "r  = ";
            // 
            // OutsideREdit
            // 
            OutsideREdit.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            OutsideREdit.Location = new System.Drawing.Point(54, 139);
            OutsideREdit.Maximum = new decimal(new int[] {
            500,
            0,
            0,
            0});
            OutsideREdit.Name = "OutsideREdit";
            OutsideREdit.Size = new System.Drawing.Size(59, 20);
            OutsideREdit.TabIndex = 9;
            OutsideREdit.Value = new decimal(new int[] {
            64,
            0,
            0,
            0});
            OutsideREdit.ValueChanged += new System.EventHandler(this.OutsideREditValueChanged);
            // 
            // SmallHoleLabel
            // 
            SmallHoleLabel.AutoSize = true;
            SmallHoleLabel.Location = new System.Drawing.Point(23, 111);
            SmallHoleLabel.Name = "SmallHoleLabel";
            SmallHoleLabel.Size = new System.Drawing.Size(28, 13);
            SmallHoleLabel.TabIndex = 8;
            SmallHoleLabel.Text = "d  = ";
            // 
            // SmallHoleDEdit
            // 
            SmallHoleDEdit.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            SmallHoleDEdit.Location = new System.Drawing.Point(54, 109);
            SmallHoleDEdit.Maximum = new decimal(new int[] {
            500,
            0,
            0,
            0});
            SmallHoleDEdit.Name = "SmallHoleDEdit";
            SmallHoleDEdit.Size = new System.Drawing.Size(59, 20);
            SmallHoleDEdit.TabIndex = 7;
            SmallHoleDEdit.Value = new decimal(new int[] {
            28,
            0,
            0,
            0});
            SmallHoleDEdit.ValueChanged += new System.EventHandler(this.SmallHoleDEditValueChanged);
            // 
            // BigHoleLabel
            // 
            BigHoleLabel.AutoSize = true;
            BigHoleLabel.Location = new System.Drawing.Point(23, 81);
            BigHoleLabel.Name = "BigHoleLabel";
            BigHoleLabel.Size = new System.Drawing.Size(24, 13);
            BigHoleLabel.TabIndex = 6;
            BigHoleLabel.Text = "D =";
            // 
            // BigHoleDEdit
            // 
            BigHoleDEdit.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            BigHoleDEdit.Location = new System.Drawing.Point(54, 79);
            BigHoleDEdit.Maximum = new decimal(new int[] {
            500,
            0,
            0,
            0});
            BigHoleDEdit.Name = "BigHoleDEdit";
            BigHoleDEdit.Size = new System.Drawing.Size(59, 20);
            BigHoleDEdit.TabIndex = 5;
            BigHoleDEdit.Value = new decimal(new int[] {
            50,
            0,
            0,
            0});
            BigHoleDEdit.ValueChanged += new System.EventHandler(this.BigHoleDEditValueChanged);
            // 
            // HeightLabel
            // 
            HeightLabel.AutoSize = true;
            HeightLabel.Location = new System.Drawing.Point(23, 51);
            HeightLabel.Name = "HeightLabel";
            HeightLabel.Size = new System.Drawing.Size(27, 13);
            HeightLabel.TabIndex = 4;
            HeightLabel.Text = "H  =";
            // 
            // HeigthEdit
            // 
            HeigthEdit.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            HeigthEdit.Location = new System.Drawing.Point(54, 49);
            HeigthEdit.Maximum = new decimal(new int[] {
            500,
            0,
            0,
            0});
            HeigthEdit.Name = "HeigthEdit";
            HeigthEdit.Size = new System.Drawing.Size(59, 20);
            HeigthEdit.TabIndex = 3;
            HeigthEdit.Value = new decimal(new int[] {
            170,
            0,
            0,
            0});
            HeigthEdit.ValueChanged += new System.EventHandler(this.HeigthEditValueChanged);
            // 
            // LengthLabel
            // 
            LengthLabel.AutoSize = true;
            LengthLabel.Location = new System.Drawing.Point(23, 21);
            LengthLabel.Name = "LengthLabel";
            LengthLabel.Size = new System.Drawing.Size(28, 13);
            LengthLabel.TabIndex = 2;
            LengthLabel.Text = "L  = ";
            // 
            // LengthEdit
            // 
            LengthEdit.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            LengthEdit.Location = new System.Drawing.Point(54, 19);
            LengthEdit.Maximum = new decimal(new int[] {
            550,
            0,
            0,
            0});
            LengthEdit.Name = "LengthEdit";
            LengthEdit.Size = new System.Drawing.Size(59, 20);
            LengthEdit.TabIndex = 1;
            LengthEdit.Value = new decimal(new int[] {
            160,
            0,
            0,
            0});
            LengthEdit.ValueChanged += new System.EventHandler(this.LengthEditValueChanged);
            // 
            // Scene
            // 
            this.Scene.BackColor = System.Drawing.Color.White;
            this.Scene.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.Scene.Location = new System.Drawing.Point(16, 20);
            this.Scene.Name = "Scene";
            this.Scene.Size = new System.Drawing.Size(730, 450);
            this.Scene.TabIndex = 0;
            this.Scene.TabStop = false;
            this.Scene.Paint += new System.Windows.Forms.PaintEventHandler(this.ScenePaint);
            this.Scene.MouseClick += new System.Windows.Forms.MouseEventHandler(this.SceneMouseClick);
            // 
            // SecondTab
            // 
            SecondTab.BackColor = System.Drawing.Color.WhiteSmoke;
            SecondTab.Controls.Add(this.pictureBox1);
            SecondTab.Location = new System.Drawing.Point(4, 22);
            SecondTab.Name = "SecondTab";
            SecondTab.Padding = new System.Windows.Forms.Padding(3);
            SecondTab.Size = new System.Drawing.Size(912, 490);
            SecondTab.TabIndex = 1;
            SecondTab.Text = "Макет";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::Graphic.Properties.Resources.DSCN1587;
            this.pictureBox1.Location = new System.Drawing.Point(232, 6);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(513, 478);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(914, 509);
            this.Controls.Add(Tab);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.MaximizeBox = false;
            this.Name = "MainForm";
            this.Text = "Graphic";
            Tab.ResumeLayout(false);
            FirstTab.ResumeLayout(false);
            CoordGroupBox.ResumeLayout(false);
            CoordGroupBox.PerformLayout();
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            OtherGroupBox.ResumeLayout(false);
            OtherGroupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(AmountOfPointsEdit)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(GridStepEdit)).EndInit();
            DetailParams.ResumeLayout(false);
            DetailParams.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(InsideR3Edit)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(InsideR2Edit)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(InsideR1Edit)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(OutsideREdit)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(SmallHoleDEdit)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(BigHoleDEdit)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(HeigthEdit)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(LengthEdit)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Scene)).EndInit();
            SecondTab.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox Scene;

        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox YCoordTB;
        private System.Windows.Forms.TextBox XCoordTB;
        private System.Windows.Forms.PictureBox pictureBox1;
    }
}

