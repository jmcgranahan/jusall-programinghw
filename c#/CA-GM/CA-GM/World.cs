using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CA_GM
{
    public class World
    {
        private int height = 0 , width = 0;
        private Cell[,] cells = new Cell[CA_GM.Window.HEIGHT, CA_GM.Window.WIDTH];

       
        static Random rand = new Random();

        public World(int initWidth, int initHeight)
        {
            height = initHeight;
            width = initWidth;
            
            for (int r = 0; r < initWidth; r++)
            {
                for ( int c = 0; c < initHeight; c++)
                    cells[c,r] = new Cell(this,c,r);
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
            foreach (Cell cell in cells)
            {
                cell.Prepare();
            }

            foreach (Cell cell in cells)
            {
                cell.Mutate();
            }
        }

        public Cell[,] CellOutput()
        {
            return cells;
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

        public Cell[] GetSurroundingCells(int x, int y)
        {
            int index = 0;
            Cell[] surroundingCells = new Cell[8];
            

            for (int c = -1 ; c < 2; c++)
                for (int r = -1; r < 2; r++)
                {
                    if ((x + c >= 0) && (x + c < Window.WIDTH) && (y + r >= 0) && (y + r < Window.WIDTH) && (x + c != x) && (y + r != y))
                    {
                        surroundingCells[index] = cells[x+c, y+r];
                        index++;
                    }
                }

            Cell[] surroundingCellsClean = new Cell[index];

            for (int i = 0; i < index; i++)
            {
                surroundingCellsClean[i] = surroundingCells[i];
            }
            return surroundingCellsClean;
        }

    }   
}
