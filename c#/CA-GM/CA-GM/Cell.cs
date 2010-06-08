using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;

namespace CA_GM
{
    public class Cell
    {
        private World world;
        private int x, y;
        private int[] colorGene = new int[256];
        private int[] colorGeneBuffer = new int[256];

        static Random rand = new Random();

        public Cell(World w, int initx, int inity)
        {
            world = w;
            x = initx;
            y = inity;

            int groupColor = rand.Next(1,4);
            for (int i = 0; i < 256; i++)
            {
                
                colorGene[i] = groupColor;

            }


        }

        public void Prepare()
        {
            Cell[] surroundingCells = world.GetSurroundingCells(x,y);
            colorGeneBuffer = GenerateGene(surroundingCells);
            MutateGeneBuffer();
        }
        
        public void Mutate()
        {
            colorGene = colorGeneBuffer;
            
        }

        private void MutateGeneBuffer()
        {
            for (int i = 0; i <256;i++)
            {
                if (rand.Next(100)<5)
                    colorGeneBuffer[i] = rand.Next(1,4);

            }

        }

        private int[] GenerateGene(Cell[] surroundingCells)
        {
            int[] generatedGene = new int[256];
            double genesPerCell = 256/surroundingCells.Count();

            /*for (int i = 0; i < 256; i++)
            {  
                int whichSurroundingCell = Convert.ToInt32(Math.Floor(i/genesPerCell));
                Cell surroundingCell = surroundingCells[whichSurroundingCell];


                generatedGene[i] = surroundingCell.Gene(rand.Next(255));
            }*/

            for (int i = 0; i < 256; i++)
            {
                if (rand.Next(100) < 50)
                    generatedGene[i] = surroundingCells[Convert.ToInt32(Math.Floor(i / genesPerCell))].Gene(rand.Next(255));
                else
                    generatedGene[i] = colorGene[i];
            }

            return generatedGene;          
        }

        public int Gene(int i)
        {
            return colorGene[i];
        }

        public Color cellColor()
        {
            Color cellColor = new Color();
            int R = 0 , G = 0 , B = 0;
            foreach (int gene in colorGene)
            {
                switch (gene)
                {
                    case 1:
                        R++;
                        break;
                    case 2:
                        G++;
                        break;
                    case 3:
                        B++;
                        break;
                }
            }

            cellColor = Color.FromArgb( ((R > 255)?255:R), ((G > 255)?255:G), ((B > 255)?255:B));
            return cellColor;

        }

    }
}
