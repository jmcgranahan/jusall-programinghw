namespace Ants
{
    partial class ants
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.button1 = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.stepsUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.showants = new System.Windows.Forms.CheckBox();
            this.debugbox = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.stepsUpDown1)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(413, 12);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 25);
            this.button1.TabIndex = 0;
            this.button1.Text = "Push me";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(12, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(400, 400);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 1;
            this.pictureBox1.TabStop = false;
            // 
            // stepsUpDown1
            // 
            this.stepsUpDown1.Location = new System.Drawing.Point(416, 49);
            this.stepsUpDown1.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.stepsUpDown1.Name = "stepsUpDown1";
            this.stepsUpDown1.Size = new System.Drawing.Size(45, 20);
            this.stepsUpDown1.TabIndex = 2;
            this.stepsUpDown1.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            // 
            // showants
            // 
            this.showants.AutoSize = true;
            this.showants.Checked = true;
            this.showants.CheckState = System.Windows.Forms.CheckState.Checked;
            this.showants.Location = new System.Drawing.Point(417, 79);
            this.showants.Name = "showants";
            this.showants.Size = new System.Drawing.Size(74, 17);
            this.showants.TabIndex = 3;
            this.showants.Text = "show ants";
            this.showants.UseVisualStyleBackColor = true;
            // 
            // debugbox
            // 
            this.debugbox.Location = new System.Drawing.Point(416, 102);
            this.debugbox.Multiline = true;
            this.debugbox.Name = "debugbox";
            this.debugbox.Size = new System.Drawing.Size(76, 310);
            this.debugbox.TabIndex = 4;
            this.debugbox.WordWrap = false;
            // 
            // ants
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(500, 426);
            this.Controls.Add(this.debugbox);
            this.Controls.Add(this.showants);
            this.Controls.Add(this.stepsUpDown1);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.button1);
            this.Name = "ants";
            this.Text = "ants";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.stepsUpDown1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.NumericUpDown stepsUpDown1;
        private System.Windows.Forms.CheckBox showants;
        public System.Windows.Forms.TextBox debugbox;
    }
}

