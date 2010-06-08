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
    public partial class Window : Form
    {

        public const int WIDTH = 100, HEIGHT = 100;
        World world;
        Bitmap bitMap;
        Graphics graphic;

        public Window()
        {
            InitializeComponent();
        }

        private void Window_Load(object sender, EventArgs e)
        {
            world = new World(WIDTH, HEIGHT);

            bitMap = new Bitmap(WIDTH, HEIGHT);
            graphic = Graphics.FromImage(bitMap);
            Display.Image = bitMap;
            //world.CellOutput[25,25].
            DisplayOutput();

        }

        private void goButton_Click(object sender, EventArgs e)
        {
            stepTimer.Enabled = !stepTimer.Enabled;
            if (stepTimer.Enabled)
                goButton.Text = "STOP";
            else
                goButton.Text = "GO";
        }


        private void DisplayOutput()
        {
            graphic.Clear(Color.White);

            for (int r = 0; r < WIDTH; r++)
            {
                for (int c = 0; c < HEIGHT; c++)
                    bitMap.SetPixel(c,r, world.CellOutput()[c,r].cellColor());
            }

            this.Refresh();
        }

        private void stepTimer_Tick(object sender, EventArgs e)
        {
            DebugBox.Text = "";
            world.TimeStep();
            DisplayOutput();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            world = new World(WIDTH, HEIGHT);
            DisplayOutput();


        }

   



    }
}
