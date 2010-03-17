namespace coin_genetics
{
    partial class Form1
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
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.Target_Value = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.checkBox_penny = new System.Windows.Forms.CheckBox();
            this.checkBox_nickel = new System.Windows.Forms.CheckBox();
            this.checkBox_dime = new System.Windows.Forms.CheckBox();
            this.checkBox_quater = new System.Windows.Forms.CheckBox();
            this.checkBox_halfdollar = new System.Windows.Forms.CheckBox();
            this.checkBox_dollar = new System.Windows.Forms.CheckBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.numericUpDown2 = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.numericUpDown3 = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.Target_Value)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown3)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(740, 363);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(73, 26);
            this.button1.TabIndex = 0;
            this.button1.Text = "PUSH ME!";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(12, 8);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(719, 382);
            this.textBox1.TabIndex = 1;
            // 
            // Target_Value
            // 
            this.Target_Value.Location = new System.Drawing.Point(784, 9);
            this.Target_Value.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.Target_Value.Minimum = new decimal(new int[] {
            25,
            0,
            0,
            0});
            this.Target_Value.Name = "Target_Value";
            this.Target_Value.Size = new System.Drawing.Size(87, 20);
            this.Target_Value.TabIndex = 2;
            this.Target_Value.Value = new decimal(new int[] {
            500,
            0,
            0,
            0});
            this.Target_Value.ValueChanged += new System.EventHandler(this.Target_Value_ValueChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(737, 11);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Target:";
            // 
            // checkBox_penny
            // 
            this.checkBox_penny.AutoSize = true;
            this.checkBox_penny.Checked = true;
            this.checkBox_penny.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox_penny.Location = new System.Drawing.Point(737, 140);
            this.checkBox_penny.Name = "checkBox_penny";
            this.checkBox_penny.Size = new System.Drawing.Size(64, 17);
            this.checkBox_penny.TabIndex = 4;
            this.checkBox_penny.Text = "Pennies";
            this.checkBox_penny.UseVisualStyleBackColor = true;
            // 
            // checkBox_nickel
            // 
            this.checkBox_nickel.AutoSize = true;
            this.checkBox_nickel.Checked = true;
            this.checkBox_nickel.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox_nickel.Location = new System.Drawing.Point(737, 163);
            this.checkBox_nickel.Name = "checkBox_nickel";
            this.checkBox_nickel.Size = new System.Drawing.Size(61, 17);
            this.checkBox_nickel.TabIndex = 5;
            this.checkBox_nickel.Text = "Nickels";
            this.checkBox_nickel.UseVisualStyleBackColor = true;
            // 
            // checkBox_dime
            // 
            this.checkBox_dime.AutoSize = true;
            this.checkBox_dime.Checked = true;
            this.checkBox_dime.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox_dime.Location = new System.Drawing.Point(737, 186);
            this.checkBox_dime.Name = "checkBox_dime";
            this.checkBox_dime.Size = new System.Drawing.Size(55, 17);
            this.checkBox_dime.TabIndex = 6;
            this.checkBox_dime.Text = "Dimes";
            this.checkBox_dime.UseVisualStyleBackColor = true;
            // 
            // checkBox_quater
            // 
            this.checkBox_quater.AutoSize = true;
            this.checkBox_quater.Checked = true;
            this.checkBox_quater.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox_quater.Location = new System.Drawing.Point(811, 140);
            this.checkBox_quater.Name = "checkBox_quater";
            this.checkBox_quater.Size = new System.Drawing.Size(63, 17);
            this.checkBox_quater.TabIndex = 7;
            this.checkBox_quater.Text = "Quaters";
            this.checkBox_quater.UseVisualStyleBackColor = true;
            // 
            // checkBox_halfdollar
            // 
            this.checkBox_halfdollar.AutoSize = true;
            this.checkBox_halfdollar.Checked = true;
            this.checkBox_halfdollar.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox_halfdollar.Location = new System.Drawing.Point(811, 163);
            this.checkBox_halfdollar.Name = "checkBox_halfdollar";
            this.checkBox_halfdollar.Size = new System.Drawing.Size(80, 17);
            this.checkBox_halfdollar.TabIndex = 8;
            this.checkBox_halfdollar.Text = "Half-Dollars";
            this.checkBox_halfdollar.UseVisualStyleBackColor = true;
            // 
            // checkBox_dollar
            // 
            this.checkBox_dollar.AutoSize = true;
            this.checkBox_dollar.Checked = true;
            this.checkBox_dollar.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox_dollar.Location = new System.Drawing.Point(811, 186);
            this.checkBox_dollar.Name = "checkBox_dollar";
            this.checkBox_dollar.Size = new System.Drawing.Size(58, 17);
            this.checkBox_dollar.TabIndex = 9;
            this.checkBox_dollar.Text = "Dollars";
            this.checkBox_dollar.UseVisualStyleBackColor = true;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(740, 210);
            this.textBox2.Multiline = true;
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(140, 148);
            this.textBox2.TabIndex = 10;
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.DecimalPlaces = 2;
            this.numericUpDown1.Increment = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.numericUpDown1.Location = new System.Drawing.Point(786, 36);
            this.numericUpDown1.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(48, 20);
            this.numericUpDown1.TabIndex = 11;
            this.numericUpDown1.Value = new decimal(new int[] {
            2,
            0,
            0,
            131072});
            this.numericUpDown1.ValueChanged += new System.EventHandler(this.numericUpDown1_ValueChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(737, 38);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 13);
            this.label2.TabIndex = 12;
            this.label2.Text = "mutation";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(737, 64);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(29, 13);
            this.label3.TabIndex = 14;
            this.label3.Text = "Pop:";
            // 
            // numericUpDown2
            // 
            this.numericUpDown2.Location = new System.Drawing.Point(784, 62);
            this.numericUpDown2.Minimum = new decimal(new int[] {
            2,
            0,
            0,
            0});
            this.numericUpDown2.Name = "numericUpDown2";
            this.numericUpDown2.Size = new System.Drawing.Size(87, 20);
            this.numericUpDown2.TabIndex = 13;
            this.numericUpDown2.Value = new decimal(new int[] {
            25,
            0,
            0,
            0});
            this.numericUpDown2.ValueChanged += new System.EventHandler(this.numericUpDown2_ValueChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(737, 90);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(36, 13);
            this.label4.TabIndex = 16;
            this.label4.Text = "Coins:";
            // 
            // numericUpDown3
            // 
            this.numericUpDown3.Location = new System.Drawing.Point(784, 88);
            this.numericUpDown3.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.numericUpDown3.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDown3.Name = "numericUpDown3";
            this.numericUpDown3.Size = new System.Drawing.Size(87, 20);
            this.numericUpDown3.TabIndex = 15;
            this.numericUpDown3.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            this.numericUpDown3.ValueChanged += new System.EventHandler(this.numericUpDown3_ValueChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(892, 402);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.numericUpDown3);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.numericUpDown2);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.numericUpDown1);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.checkBox_dollar);
            this.Controls.Add(this.checkBox_halfdollar);
            this.Controls.Add(this.checkBox_quater);
            this.Controls.Add(this.checkBox_dime);
            this.Controls.Add(this.checkBox_nickel);
            this.Controls.Add(this.checkBox_penny);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Target_Value);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.Target_Value)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown3)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.NumericUpDown Target_Value;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.CheckBox checkBox_penny;
        private System.Windows.Forms.CheckBox checkBox_nickel;
        private System.Windows.Forms.CheckBox checkBox_dime;
        private System.Windows.Forms.CheckBox checkBox_quater;
        private System.Windows.Forms.CheckBox checkBox_halfdollar;
        private System.Windows.Forms.CheckBox checkBox_dollar;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.NumericUpDown numericUpDown2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown numericUpDown3;
    }
}

