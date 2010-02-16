using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Conways
{
    class ConwaysCA
    {
        public int[,] grid;
        private int[,] tempGrid;
        private int[] rules = new int[31];
        private string[] paterns = new string[31] {"00000","00001","00010","00011","00100","00101"
                                                  ,"00110","00111","01000","01001","01010"
                                                  ,"01011","01100","01101","01110","10000"
                                                  ,"10001","10010","10011","10100","10101"
                                                  ,"10110","10111","11000","11001","11010"
                                                  ,"11011","11100","11101","11110","11111"};
        private int gridWidth, gridHeight;
        private bool isFile = false;
        private bool useRules = false;
        
        public ConwaysCA(int height, int width)
        {
            grid = new int[height, width];
            tempGrid = new int[height, width];

            gridWidth = width;
            gridHeight = height;

            RandomPop(.25f);
        }

        public ConwaysCA(string filename)
        {
            FileSet(filename);
        }

        Random rnd = new Random();
        public void RandomPop(float percentLive)
        {
            for (int row = 0; row < gridHeight; row++)
            {
                for (int col = 0; col < gridWidth; col++)
                {
                    if (rnd.NextDouble() < percentLive)
                        grid[row, col] = 1;
                    else
                        grid[row, col] = 0;
                }
            }
            isFile = false;
        }

        public void SetRules()
        {
            
            for (int c = 0; c < 31;c++)
            {
                Console.Clear();
                Console.WriteLine("Please enter state for rule[0/1]:");
                Console.WriteLine(" {0} ", paterns[c][0]);
                Console.WriteLine("{0}{1}{2}",paterns[c][1],paterns[c][2],paterns[c][3]);
                Console.WriteLine(" {0} ", paterns[c][4]);
               
                int done = 0;
                string input = "";
                while (done == 0)
                {
                    input = Console.ReadLine().ToLower();
                    done = (input == "1" || input == "0") ? 1 : 0;
                }
                Console.Clear();
                rules[c] = input == "1" ? 1 : 0;
                          
            }
            useRules = true;
        }

        public void NextGen()
        {
            if (useRules)
                NextGenRules();
            else
                NextGenConways();

            Array.Copy(tempGrid, grid, gridWidth * gridHeight);
        }

        private void NextGenConways()
        {
            for (int row = 0; row < gridHeight; row++)
            {
                for (int col = 0; col < gridWidth; col++)
                {
                    int numLiveNeighbors =
                        CountLiveNeighbors(row, col);
                    if (grid[row, col] == 1) // live cell
                    {
                        if (numLiveNeighbors == 2 ||
                            numLiveNeighbors == 3)
                        {// stay alive
                            tempGrid[row, col] = 1;
                        }
                        else
                        {// die
                            tempGrid[row, col] = 0;
                        }
                    }
                    else // dead cell
                    {
                        if (numLiveNeighbors == 3)
                        {// come alive
                            tempGrid[row, col] = 1;
                        }
                        else
                        {// stay dead
                            tempGrid[row, col] = 0;
                        }
                    }
                }
            }
        }

        private void NextGenRules()
        {
            for (int row = 0; row < gridHeight; row++)
            {
                for (int col = 0; col < gridWidth; col++)
                {
                    int life = CheckRules(row, col);
                    tempGrid[row,col] = life == 1 ? 1 : 0;
                }
            }
        }


        public void Reset(int height, int width)
        {
            grid = new int[height, width];
            tempGrid = new int[height, width];

            gridWidth = width;
            gridHeight = height;

            RandomPop(.25f);
        }

        public void FileSet(string filename)
        {
            isFile = true;
            StreamReader text = new StreamReader(filename);
            int height = numRows(filename);
            int width = numCols(filename);

            grid = new int[height, width];
            tempGrid = new int[height, width];

            gridWidth = width;
            gridHeight = height;
            char[] cell = new char[gridWidth];
            for (int row = 0; row < gridHeight; row++)
            {
                cell = text.ReadLine().ToCharArray();
                for (int col = 0; col < gridWidth; col++)
                {
                    if (cell[col] == '1')
                        grid[row, col] = 1;
                    else
                        grid[row, col] = 0;
                }
            }
            text.Close();

        }

        private int CountLiveNeighbors(int row, int col)
        {
            int numNeighbors = 0;
            int leftOfCol = col - 1;
            int rightOfCol = col + 1;
            int topOfRow = row - 1;
            int bottomOfRow = row + 1;

            if (col == 0) leftOfCol = gridWidth - 1;
            else if (col == gridWidth - 1) rightOfCol = 0;

            if (row == 0) topOfRow = gridHeight - 1;
            else if (row == gridHeight - 1) bottomOfRow = 0;

            numNeighbors =
                  grid[topOfRow, leftOfCol]
                + grid[row, leftOfCol]
                + grid[bottomOfRow, leftOfCol]
                + grid[topOfRow, col]
                + grid[bottomOfRow, col]
                + grid[topOfRow, rightOfCol]
                + grid[row, rightOfCol]
                + grid[bottomOfRow, rightOfCol];

            return numNeighbors;
        }

        private int CheckRules(int row, int col)
        {
            int leftOfCol = col - 1;
            int rightOfCol = col + 1;
            int topOfRow = row - 1;
            int bottomOfRow = row + 1;

            if (col == 0) leftOfCol = gridWidth - 1;
            else if (col == gridWidth - 1) rightOfCol = 0;

            if (row == 0) topOfRow = gridHeight - 1;
            else if (row == gridHeight - 1) bottomOfRow = 0;

            int top = grid[topOfRow,col];
            int left = grid[row,leftOfCol];
            int center = grid[row,col];
            int right = grid[row,rightOfCol];
            int bottom = grid[bottomOfRow, col];
            string foundPatern = top.ToString() + left.ToString() + center.ToString() + right.ToString() + bottom.ToString();
            int i = 0;
            int found = 0;
            while(i < 31 && found==0)
            {
                if (paterns[i].Equals(foundPatern))
                    found = i;
                i++;
            }
            return rules[found];

        }



        private int numRows(string filename)
        {
            StreamReader reader = new StreamReader(filename);
            char[] text = reader.ReadToEnd().ToCharArray();
            int count = 1;
            for(int i = 0 ; i < text.Length; i++)
                if (text[i] == '\n')
                       count++;
            reader.Close();
            return count;
            

        }
        private int numCols(string filename)
        {
            StreamReader reader = new StreamReader(filename);
            string text = reader.ReadLine();
            int count = text.Length;
            reader.Close();
            return count;

        }

        public int Rows
        {
            get
            {
                return gridHeight;
            }
            set
            {
                gridHeight = value;
            }
        }
        public int Cols
        {
            get
            {
                return gridWidth;
            }
            set
            {
                gridWidth = value;
            }
        }
        public bool isAFile()
        {
            return isFile;         
        }


    }
}
