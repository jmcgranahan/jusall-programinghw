using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ALfinal
{
    public class World
    {
        public const int WALL = 1, SPACE = 0;
        private int height, width;
        private Cell[] Cells;
        private int[,,] field;

        static Random rand = new Random();

        public World(int initWidth, int initHeight, int numCells, int perImmune)
        {
            field = new int[initWidth, initHeight];

            height = initHeight;
            width = initWidth;
            
            Cells = new Cell[numCells];
            for (int i = 0; i < numCells; i++)
            {
                Cells[i] = new Cell(this, ((rand.Next(100) < perImmune) ? true : false));
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
            foreach (Cell cell in Cells)
            {
                cell.TimeStep();
            }
        }

        public Cell[] Cells
        {
            get
            {
                return Cells;
            }

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

        public int[,] Field
        {
            get
            {
                return field;
            }

        }
    }
}
