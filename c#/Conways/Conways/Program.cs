using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
namespace Conways
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = "";
            int width = 79;
            int height = 24;
            ConwaysCA ca;
            Random rand = new Random();
            bool Answer;

            Answer = YesNoQuestion("Do you want to load from file?", "n");

            if (Answer)
            {
                ca = new ConwaysCA("CA.txt");
            }

            else
            {
                Console.WriteLine("grid Width[80]:");
                input = Console.ReadLine();
                if(input != "")
                    width = Convert.ToInt16(input);
                Console.Clear();
                Console.WriteLine("grid Height[25]:");
                input = Console.ReadLine();
                if (input != "")
                    height = Convert.ToInt16(input);
                ca = new ConwaysCA(height,width);
                Console.Clear();
            }

            Answer = YesNoQuestion("Do you want to use custom rules?", "n");
            if (Answer)
            {
                ca.SetRules();
            }


            bool cont = true;    
            input = "";
            while (cont)
            {
                DisplayCA(ca);
                input = Console.ReadLine();
                if (input == "")
                    ca.NextGen();
                else if (input == "x")
                    cont = false;
                else
                    Cmd(input,ca);               
            }
        }

        static void DisplayCA(ConwaysCA ca)
        {
            Console.Clear();
            for (int row = 0; row < ca.Rows; row++)
            {
                for (int col = 0; col < ca.Cols; col++)
                {
                    if (ca.grid[row, col] == 1)
                        Console.Write("☼");
                    else
                        Console.Write(" ");
                }
                if(!ca.isAFile()|| ca.Cols < 79)
                    Console.WriteLine();
                
            }
            Thread.Sleep(30);
        }

        static void Cmd(string input, ConwaysCA ca)
        {
            input.Trim();
            input.ToLower();
            if (input == "random")
                ca.RandomPop(.5f);
            else if (input == "file")
                ca.FileSet("CA.txt");
            else if (input == "new")
            {
                Console.Clear();
                int width = 79;
                int height = 24;
                Console.WriteLine("grid Width[80]:");
                input = Console.ReadLine();
                if (input != "")
                    width = Convert.ToInt16(input);
                Console.Clear();
                Console.WriteLine("grid Height[25]:");
                input = Console.ReadLine();
                if (input != "")
                    height = Convert.ToInt16(input);

                ca.Reset(height, width);
            }
            else if (input == "auto")
            {
                Console.Clear();
                int gens = 20;
                Console.WriteLine("generations to run[20]:");
                input = Console.ReadLine();
                if (input != "")
                    gens = Convert.ToInt16(input);
                for (int gen = 0; gen < gens; gen++)
                {
                    ca.NextGen();
                    DisplayCA(ca);
                }
            } 
        }

        static bool YesNoQuestion(string question, string norm)
        {
            question += (norm == "y") ? "[Y/n]" : "[y/N]";
            Console.WriteLine(question);
            int done = 0;
            string input = "";
            while (done == 0)
            {
                
                input = Console.ReadLine().ToLower();
                Console.Clear();
                done = (input == "y" || input == "n" || input == "") ? 1 : 0;
            }
            return input == "y" ? true : false;
            Console.Clear();

        }
    }
}
