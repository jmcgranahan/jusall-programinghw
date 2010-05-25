using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ALfinal
{
    public partial class Gui : Form
    {
        const int WIDTH = 400, HEIGHT = WIDTH, HUMANS = 5000, IMMUNE = 1;
        World zombieLand;
        Bitmap bitMap;
        Graphics graphic;

        public Gui()
        {
            InitializeComponent();
        }

        private void Gui_Load(object sender, EventArgs e)
        {
            zombieLand = new World(WIDTH, HEIGHT, HUMANS, IMMUNE);
            
            for (int r = 0; r < WIDTH; r++)
            {
                zombieLand.SetSpace(0, r, 1);
                zombieLand.SetSpace(r, 0, 1);
                zombieLand.SetSpace(WIDTH-1, r, 1);
                zombieLand.SetSpace(r, WIDTH-1, 1);

                zombieLand.SetSpace(1, r, 1);
                zombieLand.SetSpace(r, 1, 1);
                zombieLand.SetSpace(WIDTH - 2, r, 1);
                zombieLand.SetSpace(r, WIDTH - 2, 1);
            }

            /*
            zombieLand.Humans[0].Speed = Human.SpeedNum.Stop;
            zombieLand.Humans[0].PosX = 200;
            zombieLand.Humans[0].PosY = 200;

            zombieLand.Humans[1].Speed = Human.SpeedNum.Limp;
            zombieLand.Humans[1].Dir = Human.Direction.East;
            zombieLand.Humans[1].PosX = 180;
            zombieLand.Humans[1].PosY = 197;
            */
   

            bitMap = new Bitmap(WIDTH, HEIGHT);
            graphic = Graphics.FromImage(bitMap);
            guiDisplay.Image = bitMap;
            Display();
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
            debugBox.Text += "Survivors:" + aliveCount + "\r\n";
            debugBox.Text += "Panicing:" + panicingCount + "\r\n";
            debugBox.Text += "Sick:" + sickCount + "\r\n";
            debugBox.Text += "Infected:" + infectedCount + "\r\n";
            debugBox.Text += "Dead:" + (HUMANS - (aliveCount + sickCount + infectedCount)) + "\r\n";
            

            this.Refresh();
        }

        private void resetButton_Click(object sender, EventArgs e)
        {
            debugBox.Text = "";
            zombieLand.Humans[0].Reset();
            Gui_Load(sender, e);
        }

        private void stepTimer_Tick(object sender, EventArgs e)
        {
            debugBox.Text = "";
            zombieLand.TimeStep();
            Display();
        }

        private void stepButton_Click(object sender, EventArgs e)
        {
            stepTimer.Enabled = false;
            goButton.Text = "GO";
            debugBox.Text = "";
            zombieLand.TimeStep();
            Display();
        }
    }
   
}
