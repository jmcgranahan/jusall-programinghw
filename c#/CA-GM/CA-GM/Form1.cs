using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace CA_GM
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void goButton_Click(object sender, EventArgs e)
        {
            stepTimer.Enabled = !stepTimer.Enabled;
            if (stepTimer.Enabled)
                goButton.Text = "STOP";
            else
                goButton.Text = "GO";
        }


        private void Display()
        {
            graphic.Clear(Color.Black);
            for (int r = 0; r < WIDTH-1; r++)
            {
                for (int c = 0; c < HEIGHT-1; c++)
                {
                    if(!zombieLand.IsOpen(r,c))
                        bitMap.SetPixel(r, c, Color.Yellow);
                }
            }

            int aliveCount = 0, sickCount = 0, infectedCount = 0, panicingCount = 0;
            foreach (Human human in zombieLand.Humans)
            {
                //debugBox.Text += "Human#" + human.Index + " see's " + human.HumansInSight() + "\r\n";
                //debugBox.Text += "Human#" + human.Index + " see's " + human.InfectedInSight() + "\r\n";
                Color humanColor;
                if (!human.Alive)
                    humanColor = Color.Gray;
                else if (human.Infected)
                    humanColor = Color.LimeGreen;
                else if (human.Sick)
                    humanColor = Color.Purple;
                else if (human.Panic)
                    humanColor = Color.Red;
                else
                    humanColor = Color.LightSalmon;

                bitMap.SetPixel(human.PosX, human.PosY, humanColor);

                if (human.Alive)
                {
                    if (human.Infected)
                        infectedCount++;
                    else if (human.Sick)
                        sickCount++;
                    else
                    {
                        aliveCount++;
                        if (human.Panic)
                            panicingCount++;
                    }

                }

            }

    }
}
