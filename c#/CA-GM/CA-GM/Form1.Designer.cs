namespace CA_GM
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
            this.components = new System.ComponentModel.Container();
            this.Display = new System.Windows.Forms.PictureBox();
            this.goButton = new System.Windows.Forms.Button();
            this.stepTimer = new System.Windows.Forms.Timer(this.components);
            this.DebugBox = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.Display)).BeginInit();
            this.SuspendLayout();
            // 
            // Display
            // 
            this.Display.Location = new System.Drawing.Point(0, 0);
            this.Display.Name = "Display";
            this.Display.Size = new System.Drawing.Size(400, 400);
            this.Display.TabIndex = 0;
            this.Display.TabStop = false;
            // 
            // goButton
            // 
            this.goButton.Location = new System.Drawing.Point(404, 366);
            this.goButton.Name = "goButton";
            this.goButton.Size = new System.Drawing.Size(107, 33);
            this.goButton.TabIndex = 1;
            this.goButton.Text = "Go";
            this.goButton.UseVisualStyleBackColor = true;
            this.goButton.Click += new System.EventHandler(this.goButton_Click);
            // 
            // stepTimer
            // 
            this.stepTimer.Interval = 10;
            // 
            // DebugBox
            // 
            this.DebugBox.Location = new System.Drawing.Point(411, 12);
            this.DebugBox.Multiline = true;
            this.DebugBox.Name = "DebugBox";
            this.DebugBox.Size = new System.Drawing.Size(100, 348);
            this.DebugBox.TabIndex = 2;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(516, 401);
            this.Controls.Add(this.DebugBox);
            this.Controls.Add(this.goButton);
            this.Controls.Add(this.Display);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.Display)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox Display;
        private System.Windows.Forms.Button goButton;
        private System.Windows.Forms.Timer stepTimer;
        private System.Windows.Forms.TextBox DebugBox;
    }
}

