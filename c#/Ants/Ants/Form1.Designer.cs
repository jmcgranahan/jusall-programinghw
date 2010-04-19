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
            this.FoodPilesBox = new System.Windows.Forms.NumericUpDown();
            this.FoodPerPileBox = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.stepsUpDown1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.FoodPilesBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.FoodPerPileBox)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(418, 197);
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
            this.stepsUpDown1.Location = new System.Drawing.Point(431, 171);
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
            this.showants.Location = new System.Drawing.Point(416, 228);
            this.showants.Name = "showants";
            this.showants.Size = new System.Drawing.Size(74, 17);
            this.showants.TabIndex = 3;
            this.showants.Text = "show ants";
            this.showants.UseVisualStyleBackColor = true;
            // 
            // debugbox
            // 
            this.debugbox.Location = new System.Drawing.Point(416, 251);
            this.debugbox.Multiline = true;
            this.debugbox.Name = "debugbox";
            this.debugbox.Size = new System.Drawing.Size(76, 161);
            this.debugbox.TabIndex = 4;
            this.debugbox.WordWrap = false;
            // 
            // FoodPilesBox
            // 
            this.FoodPilesBox.Location = new System.Drawing.Point(427, 28);
            this.FoodPilesBox.Name = "FoodPilesBox";
            this.FoodPilesBox.Size = new System.Drawing.Size(49, 20);
            this.FoodPilesBox.TabIndex = 5;
            this.FoodPilesBox.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
            // 
            // FoodPerPileBox
            // 
            this.FoodPerPileBox.Location = new System.Drawing.Point(427, 66);
            this.FoodPerPileBox.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.FoodPerPileBox.Name = "FoodPerPileBox";
            this.FoodPerPileBox.Size = new System.Drawing.Size(49, 20);
            this.FoodPerPileBox.TabIndex = 6;
            this.FoodPerPileBox.Value = new decimal(new int[] {
            20,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(424, 155);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(34, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "Steps";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(424, 12);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(52, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "food piles";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(420, 50);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(68, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "Food per pile";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(418, 92);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 25);
            this.button2.TabIndex = 10;
            this.button2.Text = "New";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(474, 66);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(19, 13);
            this.label4.TabIndex = 11;
            this.label4.Text = "^2";
            // 
            // ants
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(500, 426);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.FoodPerPileBox);
            this.Controls.Add(this.FoodPilesBox);
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
            ((System.ComponentModel.ISupportInitialize)(this.FoodPilesBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.FoodPerPileBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.NumericUpDown stepsUpDown1;
        private System.Windows.Forms.CheckBox showants;
        public System.Windows.Forms.TextBox debugbox;
        private System.Windows.Forms.NumericUpDown FoodPilesBox;
        private System.Windows.Forms.NumericUpDown FoodPerPileBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Label label4;
    }
}

