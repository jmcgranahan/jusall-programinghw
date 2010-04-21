namespace ALfinal
{
    partial class Gui
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
            this.guiDisplay = new System.Windows.Forms.PictureBox();
            this.goButton = new System.Windows.Forms.Button();
            this.resetButton = new System.Windows.Forms.Button();
            this.debugBox = new System.Windows.Forms.TextBox();
            this.stepTimer = new System.Windows.Forms.Timer(this.components);
            this.stepButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.guiDisplay)).BeginInit();
            this.SuspendLayout();
            // 
            // guiDisplay
            // 
            this.guiDisplay.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.guiDisplay.Location = new System.Drawing.Point(0, 0);
            this.guiDisplay.Name = "guiDisplay";
            this.guiDisplay.Size = new System.Drawing.Size(400, 400);
            this.guiDisplay.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.guiDisplay.TabIndex = 0;
            this.guiDisplay.TabStop = false;
            // 
            // goButton
            // 
            this.goButton.Location = new System.Drawing.Point(12, 406);
            this.goButton.Name = "goButton";
            this.goButton.Size = new System.Drawing.Size(121, 23);
            this.goButton.TabIndex = 1;
            this.goButton.Text = "GO";
            this.goButton.UseVisualStyleBackColor = true;
            this.goButton.Click += new System.EventHandler(this.goButton_Click);
            // 
            // resetButton
            // 
            this.resetButton.Location = new System.Drawing.Point(267, 406);
            this.resetButton.Name = "resetButton";
            this.resetButton.Size = new System.Drawing.Size(130, 23);
            this.resetButton.TabIndex = 2;
            this.resetButton.Text = "RESET";
            this.resetButton.UseVisualStyleBackColor = true;
            this.resetButton.Click += new System.EventHandler(this.resetButton_Click);
            // 
            // debugBox
            // 
            this.debugBox.Location = new System.Drawing.Point(403, 5);
            this.debugBox.Multiline = true;
            this.debugBox.Name = "debugBox";
            this.debugBox.Size = new System.Drawing.Size(102, 423);
            this.debugBox.TabIndex = 3;
            // 
            // stepTimer
            // 
            this.stepTimer.Interval = 50;
            this.stepTimer.Tick += new System.EventHandler(this.stepTimer_Tick);
            // 
            // stepButton
            // 
            this.stepButton.Location = new System.Drawing.Point(140, 405);
            this.stepButton.Name = "stepButton";
            this.stepButton.Size = new System.Drawing.Size(121, 23);
            this.stepButton.TabIndex = 4;
            this.stepButton.Text = "STEP";
            this.stepButton.UseVisualStyleBackColor = true;
            this.stepButton.Click += new System.EventHandler(this.stepButton_Click);
            // 
            // Gui
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(507, 431);
            this.Controls.Add(this.stepButton);
            this.Controls.Add(this.debugBox);
            this.Controls.Add(this.resetButton);
            this.Controls.Add(this.goButton);
            this.Controls.Add(this.guiDisplay);
            this.Name = "Gui";
            this.Load += new System.EventHandler(this.Gui_Load);
            ((System.ComponentModel.ISupportInitialize)(this.guiDisplay)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox guiDisplay;
        private System.Windows.Forms.Button goButton;
        private System.Windows.Forms.Button resetButton;
        public System.Windows.Forms.TextBox debugBox;
        private System.Windows.Forms.Timer stepTimer;
        private System.Windows.Forms.Button stepButton;
    }
}

