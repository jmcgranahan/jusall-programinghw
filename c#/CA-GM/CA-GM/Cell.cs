using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;

namespace CA_GM
{
    class Cell
    {
        private World world;
        int x, y;
        private int[] colorGene = new int[256];
        private int[] colorGeneBuffer = new int[256];

        static Random rand = new Random();

        public Cell(World w, int x, int y)
        {
            world = w;

            for (int i = 0; i < 255; i += 32)
            {
                int groupColor = rand.Next(3);
                for (int c = i; c < i + 32; c++)
                    colorGene[c] = groupColor;

            }
        }

        public void Prepare()
        {
            int[,] surroundingCellsGenes = world.GetSuroundingCells(x,y);
            colorGeneBuffer = GenerateGene(surroundingCellsGenes);
        }
        
        public void Mutate()
        {
            
        }


    }
}
