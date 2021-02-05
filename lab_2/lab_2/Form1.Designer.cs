namespace lab_2
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
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
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.trBar_angleX = new System.Windows.Forms.TrackBar();
            this.trBar_angleY = new System.Windows.Forms.TrackBar();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.plus_size = new System.Windows.Forms.Button();
            this.min_size = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trBar_angleX)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trBar_angleY)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pictureBox1.Location = new System.Drawing.Point(12, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(856, 567);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Paint += new System.Windows.Forms.PaintEventHandler(this.pictureBox1_Paint);
            // 
            // trBar_angleX
            // 
            this.trBar_angleX.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.trBar_angleX.Location = new System.Drawing.Point(917, 178);
            this.trBar_angleX.Margin = new System.Windows.Forms.Padding(4);
            this.trBar_angleX.Maximum = 628;
            this.trBar_angleX.Name = "trBar_angleX";
            this.trBar_angleX.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.trBar_angleX.Size = new System.Drawing.Size(56, 386);
            this.trBar_angleX.TabIndex = 1;
            this.trBar_angleX.TickStyle = System.Windows.Forms.TickStyle.TopLeft;
            this.trBar_angleX.Scroll += new System.EventHandler(this.trBar_angleX_Scroll);
            // 
            // trBar_angleY
            // 
            this.trBar_angleY.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.trBar_angleY.Location = new System.Drawing.Point(1118, 178);
            this.trBar_angleY.Maximum = 628;
            this.trBar_angleY.Name = "trBar_angleY";
            this.trBar_angleY.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.trBar_angleY.Size = new System.Drawing.Size(56, 386);
            this.trBar_angleY.TabIndex = 2;
            this.trBar_angleY.TickStyle = System.Windows.Forms.TickStyle.TopLeft;
            this.trBar_angleY.Scroll += new System.EventHandler(this.trBar_angleY_Scroll);
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(813, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(46, 17);
            this.label1.TabIndex = 3;
            this.label1.Text = "label1";
            this.label1.Visible = false;
            // 
            // label2
            // 
            this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(813, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(46, 17);
            this.label2.TabIndex = 4;
            this.label2.Text = "label2";
            this.label2.Visible = false;
            // 
            // plus_size
            // 
            this.plus_size.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.plus_size.Location = new System.Drawing.Point(917, 34);
            this.plus_size.Name = "plus_size";
            this.plus_size.Size = new System.Drawing.Size(257, 45);
            this.plus_size.TabIndex = 5;
            this.plus_size.Text = "+";
            this.plus_size.UseVisualStyleBackColor = true;
            this.plus_size.Click += new System.EventHandler(this.plus_size_Click);
            // 
            // min_size
            // 
            this.min_size.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.min_size.Location = new System.Drawing.Point(917, 127);
            this.min_size.Name = "min_size";
            this.min_size.Size = new System.Drawing.Size(257, 45);
            this.min_size.TabIndex = 6;
            this.min_size.Text = "-";
            this.min_size.UseVisualStyleBackColor = true;
            this.min_size.Click += new System.EventHandler(this.min_size_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1186, 591);
            this.Controls.Add(this.min_size);
            this.Controls.Add(this.plus_size);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.trBar_angleY);
            this.Controls.Add(this.trBar_angleX);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Resize += new System.EventHandler(this.Form1_Resize);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trBar_angleX)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trBar_angleY)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.TrackBar trBar_angleX;
        private System.Windows.Forms.TrackBar trBar_angleY;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button plus_size;
        private System.Windows.Forms.Button min_size;
    }
}

