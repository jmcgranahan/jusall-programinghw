using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Hello_World_GA
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        const int POP_SIZE = 25;
        const double MUTATION_RATE = 0.02;
        const string TARGET = "Hello world!";

        Random rnd = new Random();

        private void button1_Click(object sender, EventArgs e)
        {
            string[] pop = new string[POP_SIZE];

            pop = GenerateRandomPopulation(POP_SIZE);

            RunGA(pop);
        }

        private string[] GenerateRandomPopulation(int populationSize)
        {
            string[] pop = new string[populationSize];
            for (int index = 0; index < populationSize; index++)
                pop[index] = GenerateRandomGenome();

            return pop;
        }

        private string GenerateRandomGenome()
        {
            StringBuilder sb = new StringBuilder();
            for (int gene = 0; gene < TARGET.Length; gene++)
                sb.Append((char)(rnd.Next(128)));

            return sb.ToString();
        }

        private void RunGA(string[] pop)
        {
            int genCount = 0;

            do
            {
                string[] nextGen = CreateNextGeneration(pop);
                nextGen.CopyTo(pop, 0);
                genCount++;
                DisplayGeneration(pop, genCount);

            } while (!SolutionFound(pop));
        }
        private string[] CreateNextGeneration(string[] pop)
        {
            string[] nextGen = new string[POP_SIZE];

            for (int index = 0; index < POP_SIZE; index++)
            {
                string copyOfParent = PickAFitParent(pop);
                string child = ApplyMutation(copyOfParent, MUTATION_RATE);
                nextGen[index] = child;
            }

            return nextGen;
        }

        private string PickAFitParent(string[] pop)
        {
            int parentIndex1 = rnd.Next(POP_SIZE);
            int parentIndex2 = rnd.Next(POP_SIZE);

            string copyOfParent;

            if (FitnessOf(pop[parentIndex1]) > FitnessOf(pop[parentIndex2]))
                copyOfParent = pop[parentIndex1];
            else
                copyOfParent = pop[parentIndex2];

            return copyOfParent;
        }

        private string ApplyMutation(string genome, double mutationRate)
        {
            StringBuilder sb = new StringBuilder(genome);

            for (int gene = 0; gene < TARGET.Length; gene++)
                if (rnd.NextDouble() < mutationRate)
                    sb[gene] = (char)(rnd.Next(128));

            return sb.ToString();
        }

        private int FitnessOf(string genome)
        {
            int fitness = 0;

            for (int index = 0; index < TARGET.Length; index++)
                if (genome[index] == TARGET[index])
                    fitness++;

            return fitness;
        }

        private bool SolutionFound(string[] pop)
        {
            foreach (string genome in pop)
                if (genome == TARGET)
                    return true;

            return false;
        }

        private void DisplayGeneration(string[] pop, int genCount)
        {
            textBox1.Clear();
            foreach (string genome in pop)
            {
                textBox1.Text += genome + " " 
                    + "[" + FitnessOf(genome) + "]\r\n";
            }

            textBox1.Refresh();

            this.Text = "Gen = " + genCount.ToString();
        }
    }
}
