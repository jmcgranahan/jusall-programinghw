using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Ants
{
    public partial class ants : Form
    {
        const int NUM_ANTS = 1000;
        const int WHEIGHT = 200;
        const int WWIDTH = 200;
        const int PERCENT_FOOD = 5;
        World myWorld;
        Scent myScent;
        Bitmap b;
        Graphics g;

        public ants()
        {
            InitializeComponent();
        }
        
        private void Form1_Load(object sender, EventArgs e)
        {
            myScent = new Scent(WWIDTH, WHEIGHT);
            myWorld = new World(WWIDTH, WHEIGHT, NUM_ANTS, PERCENT_FOOD, myScent);
            
            b = new Bitmap(WWIDTH, WHEIGHT);
            g = Graphics.FromImage(b);
            pictureBox1.Image = b;
            Display();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < 5000; i++)
            {
                debugbox.Text = "";
                myWorld.TimeStep();
                Display();
                
            }
        }

        public void Display()
        {
            g.Clear(Color.Black);
            for (int r = 0; r < WWIDTH; r++)
            {
                for (int c = 0; c < WHEIGHT; c++)
                {
                    Color scentcolor = new Color();
                    scentcolor = Color.Black;
                    int home = 0, food = 0;
                    int R, G, B;
                    myScent.Scents(r, c, ref home, ref food);
                    B = (home<255? home : 255);
                    G = (food / 4 < 255 ? food / 4 : 255);
                    R = (food / 4 < 255 ? food / 4 : 255);
                    
                    
                    b.SetPixel(r, c, Color.FromArgb(255,R,G,B));
                    
                    
                    
                }

            }
            for (int r = 0; r < WWIDTH; r++)
            {
                for (int c = 0; c < WHEIGHT; c++)
                {
                    if (myWorld.field[r, c] == World.FOOD)
                        b.SetPixel(r, c, Color.Yellow);
                }

            }
            if ( showants.Checked ) {
                foreach(Ant ant in myWorld.ants)
                {
                    b.SetPixel(ant.x, ant.y, (ant.hasFOOD ? Color.Green : Color.Red));
                }
            }

            this.Refresh();
        }
 
    }

    public class Ant
    {
        public enum Direction { North, NorthEast, East, SouthEast, South, SouthWest, West, NorthWest };
        public Direction dir;
        public int x, y;
        public bool hasFOOD;
        public World world;
        public Scent scent;
        public int index;

        public Ant(World w ,Scent s ,int i)
        {
            Random rand = new Random();
            world = w;
            scent = s;
            index = i;
            x = world.width/2;
            y = world.height/2;
            dir = (Direction)rand.Next(7);
        }

        public void Act()
        {
            if ((int)dir > 8)
                dir = (Direction)0;
            else if ((int)dir < 0)
                dir = (Direction)8;
            Random rand = new Random(x*y*index);
            int moveReturn;
            if (hasFOOD)
            {
                dir = AimHome();
                moveReturn = Move();
                if(((x == world.width/2) || (x == (world.width/2)+1)) &&
                     ((y == world.height/2) || (y == (world.height/2)+1)))    
                    DropFood();

                if (moveReturn == 0 && rand.Next(1, 10) > 6)
                    DropFood();
                else if (moveReturn == 0)
                    dir = (Direction)((int)dir + (rand.Next(1, 4) - 2));
                
                    
            }
            else
            {
                if(rand.Next(10) < 3)
                    dir = (Direction)(((int)dir)+(rand.Next(1,4)-2));
                moveReturn = Move();
                if (world.hasFOOD(x, y) && rand.Next(2) < 1)
                    PickupFood();
            }
        }

        private Direction AimHome()
        {
            Random rand = new Random(x * y * index);
            Direction tempdir;
            if (x == world.width / 2)
            {
                if (y < world.height / 2)
                    tempdir = Direction.South;
                else
                    tempdir = Direction.North;
            }
            if (y == world.height / 2)
            {
                if (x < world.width / 2)
                    tempdir = Direction.East;
                else
                    tempdir = Direction.West;
            }

            if (x < world.width / 2)
            {
                if (y < world.height / 2)
                    tempdir = Direction.SouthEast;
                else
                    tempdir = Direction.NorthEast;
            }
            else
            {
                if (y < world.height / 2)
                    tempdir = Direction.SouthWest;
                else
                    tempdir = Direction.NorthWest;
            }

            tempdir = (rand.Next(10) > 2 ? (tempdir + rand.Next(1,3) - 2) : tempdir);
            return tempdir;
        }

        private int Move()
        {
            if (dir == Direction.East)
                return AttemptMove(1, 0);
            else if (dir == Direction.North)
                return AttemptMove(0, -1);
            else if (dir == Direction.NorthEast)
                return AttemptMove(1, -1);
            else if (dir == Direction.NorthWest)
                return AttemptMove(-1, -1);
            else if (dir == Direction.South)
                return AttemptMove(0, 1);
            else if (dir == Direction.SouthEast)
                return AttemptMove(1, 1);
            else if (dir == Direction.SouthWest)
                return AttemptMove(-1, 1);
            else if (dir == Direction.West)
                return AttemptMove(-1, 0);
            else
                return 0;

        }

        private int AttemptMove(int xMove, int yMove)
        {
            int Fx, Fy;

            Fx = x+xMove;
            Fy = y+yMove;

            Toroidal(ref Fx, ref Fy);

            if ((world.field[Fx, Fy] == World.SPACE) ||(hasFOOD == false))
                
            {
                x = Fx;
                y = Fy;
                if (hasFOOD)
                    scent.AddFood(x,y);
                return 1;
            }
            else
            {
                return 0;
            }
        }

        private void Toroidal(ref int Fx, ref int Fy)
        {
            if (Fx > world.width - 1)
                Fx = 0;
            else if (Fx < 0)
                Fx = world.width - 1;

            if (Fy > world.height - 1)
                Fy = 0;
            else  if (Fy < 0)
                Fy = world.height - 1;
        }

        private void DropFood()
        {
            Random rand = new Random(x * y * index);
            if (world.field[x, y] == World.SPACE)
            {
                world.field[x, y] = World.FOOD;
                hasFOOD = false;
            }
            else
                dir = (Direction)((int)dir + (rand.Next(1,4)-2));
        }

        private void PickupFood()
        {
            world.field[x, y] = World.SPACE;
            hasFOOD = true;
        }


    }
    public class World
    {
        public const int FOOD = 1, SPACE = 0;
        public int height, width;
        public int[,] field;
        public Ant[] ants;
        public Scent scent;

        public World(int initWidth, int initHeight, int numAnts, int FOODPct, Scent s)
        {
            Random randm = new Random();
            field = new int[initHeight, initWidth];
            height = initHeight;
            width = initWidth;
            scent = s;

            for (int r = 0; r < width - 1; r++)
            {
                for (int c = 0; c < height - 1; c++)
                {
                    int randd = randm.Next(100);
                    field[r, c] = (randd < FOODPct ? FOOD : SPACE);
                }
            }

            ants = new Ant[numAnts];
            for (int i = 0; i < numAnts; i++)
            {
                ants[i] = new Ant(this ,scent ,i);
            }
           
        }

        public bool hasFOOD(int x, int y)
        {
            return (field[x, y] == World.FOOD);
        }

        public void TimeStep()
        {
            foreach (Ant ant in ants)
            {
                ant.Act();
            }
            field[100, 100] = World.SPACE;
            field[100, 101] = World.SPACE;
            field[101, 100] = World.SPACE;
            field[101, 101] = World.SPACE;
        }

    }
    public class Scent
    {
        public int None = 0, HOME = 10, FOOD = 10;
        public int height, width;
        public int[,] homefield;
        public int[,] foodfield;

        public Scent(int initWidth, int initHeight)
        {
            homefield = new int[initHeight, initWidth];
            foodfield = new int[initHeight, initWidth];
            height = initHeight;
            width = initWidth;

            for (int r = 0; r < width - 1; r++)
            {
                for (int c = 0; c < height - 1; c++)
                {
                    homefield[r, c] = None;
                    foodfield[r, c] = None;
                }
            }
        }

        public void AddHome(int x, int y)
        {
            homefield[x, y] += HOME;
        }
        
        public void AddFood(int x, int y)
        {
            foodfield[x, y] += FOOD;
        }

        public void Scents(int x, int y, ref int home, ref int food)
        {
            home = homefield[x, y];
            food = foodfield[x, y];
        }

    }
}
