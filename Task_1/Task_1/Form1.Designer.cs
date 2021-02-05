namespace Task_1
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
            this.screen = new System.Windows.Forms.PictureBox();
            this.osx = new System.Windows.Forms.Label();
            this.osy = new System.Windows.Forms.Label();
            this.Create = new System.Windows.Forms.Button();
            this.Size = new System.Windows.Forms.TrackBar();
            this.label2 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.screen)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Size)).BeginInit();
            this.SuspendLayout();
            // 
            // screen
            // 
            this.screen.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.screen.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.screen.Location = new System.Drawing.Point(3, -2);
            this.screen.Name = "screen";
            this.screen.Size = new System.Drawing.Size(428, 428);
            this.screen.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.screen.TabIndex = 0;
            this.screen.TabStop = false;
            this.screen.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            // 
            // osx
            // 
            this.osx.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.osx.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.osx.Location = new System.Drawing.Point(403, 221);
            this.osx.Name = "osx";
            this.osx.Size = new System.Drawing.Size(19, 18);
            this.osx.TabIndex = 4;
            this.osx.Text = "x";
            this.osx.Visible = false;
            // 
            // osy
            // 
            this.osy.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.osy.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.osy.Location = new System.Drawing.Point(225, 9);
            this.osy.Name = "osy";
            this.osy.Size = new System.Drawing.Size(19, 22);
            this.osy.TabIndex = 5;
            this.osy.Text = "y";
            this.osy.Visible = false;
            // 
            // Create
            // 
            this.Create.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.Create.Location = new System.Drawing.Point(533, 79);
            this.Create.Name = "Create";
            this.Create.Size = new System.Drawing.Size(108, 48);
            this.Create.TabIndex = 1;
            this.Create.Text = "Create";
            this.Create.UseVisualStyleBackColor = true;
            this.Create.Click += new System.EventHandler(this.Create_Click);
            // 
            // Size
            // 
            this.Size.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.Size.LargeChange = 1;
            this.Size.Location = new System.Drawing.Point(437, 9);
            this.Size.Maximum = 7;
            this.Size.Minimum = 2;
            this.Size.Name = "Size";
            this.Size.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.Size.Size = new System.Drawing.Size(56, 118);
            this.Size.TabIndex = 3;
            this.Size.Value = 2;
            this.Size.Scroll += new System.EventHandler(this.Size_Scroll);
            // 
            // label2
            // 
            this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label2.Location = new System.Drawing.Point(451, 338);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(189, 97);
            this.label2.TabIndex = 8;
            this.label2.Text = "Выполнил студент группы М8О-309Б-18\r\n                \r\n         Рябыкин Алексей";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.ClientSize = new System.Drawing.Size(653, 443);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.Size);
            this.Controls.Add(this.osy);
            this.Controls.Add(this.Create);
            this.Controls.Add(this.osx);
            this.Controls.Add(this.screen);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.screen)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Size)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox screen;
        private System.Windows.Forms.Label osx;
        private System.Windows.Forms.Label osy;
        private System.Windows.Forms.Button Create;
        private System.Windows.Forms.TrackBar Size;
        private System.Windows.Forms.Label label2;
    }
}

