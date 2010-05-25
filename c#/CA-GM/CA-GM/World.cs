using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CA_GM
{
    public class World
    {
        private int height, width;
        private Cell[] Cells;
       
        static Random rand = new Random();

        public World(int initWidth, int initHeight)
        {
            field = new int[initWidth, initHeight];
            height = initHeight;
            width = initWidth;
            Cells = new Cell[initWidth*initHeight];

            for (int i = 0; i < initWidth * initHeight; i++)
            {
                Cells[i] = new Cell(this);
            }
        }

        private void Toroidal(ref int Fx, ref int Fy)
        {
            if (Fx > width)
                Fx = 0;
            else if (Fx < 0)
                Fx = width;

            if (Fy > height)
                Fy = 0;
            else if (Fy < 0)
                Fy = height;
        }

        public void TimeStep()
        {
            foreach (Human human in humans)
            {
                human.TimeStep();
            }
        }

        public Human[] Humans
        {
            get
            {
                return humans;
            }

        }

        public int[,] HumanField
        {
            get
            {
                return humanField;
            }
        }

        public int[,] SickField
        {
            get
            {
                return sickField;
            }

        }

        public int[,] InfectedField
        {
            get
            {
                return infectedField;
            }

        }

        public void HumanMark(int x, int y)
        {
            humanFieldBuffer[x, y]++;
        }

        public void SickMark(int x, int y)
        {
            sickFieldBuffer[x, y]++;
        }

        public void InfectedMark(int x, int y)
        {
            infectedFieldBuffer[x, y]++;
        }

        public int Width
        {
            get
            {
                return width;
            }
        }

        public int Height
        {
            get
            {
                return height;
            }
        }

        public void SetSpace(int x, int y, int material)
        {
            field[x, y] = material;
        }

        public bool IsOpen(int x, int y)
        {
            return field[x, y] == 0;
        }
        public int[,] Field
        {
            get
            {
                return field;
            }

        }
    }
}
