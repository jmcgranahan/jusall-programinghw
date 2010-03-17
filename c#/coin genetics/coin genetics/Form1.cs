using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace coin_genetics
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int POP_SIZE = 25;
        int GENOME_SIZE = 100;
        double MUTATION_RATE = 0.02;
        int TARGET = 500;
        int closest;
        int totalfitness=0;
        int totalgenomes=0;
      
        

        Random rnd = new Random();
        enum Coins {penny=1, nickel=5, dime=10, quarter=25, halfdollar=50, dollar=100};
        enum CoinsShort { p=1, n=2, d=3, q=4, h=5, z=6}
        
        private void button1_Click(object sender, EventArgs e)
        {
            
            string[] coins = new string[POP_SIZE];

            coins = GenerateRandomPopulation(POP_SIZE);

            totalfitness = 0;
            totalgenomes = 0;

            RunGA(coins);
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
            for (int gene = 0; gene < GENOME_SIZE; gene++)
            {
                int rndnum = rnd.Next(6);
                char coin = 'z';
                switch (rndnum)
                {
                    case 6:
                        coin = 'z';
                        if (!checkBox_dollar.Checked)
                            goto case 5;
                        break;
                    case 5:
                        coin = 'h';
                        if (!checkBox_halfdollar.Checked)
                            goto case 4;
                        break;
                    case 4:
                        coin = 'q';
                        if (!checkBox_quater.Checked)
                            goto case 3;
                        break;
                    case 3:
                        coin = 'd';
                        if (!checkBox_dime.Checked)
                            goto case 2;
                        break;
                    case 2:
                        coin = 'n';
                        if (!checkBox_nickel.Checked)
                            goto case 1;
                        break;
                    case 1:
                        coin = 'p';
                        if (!checkBox_penny.Checked)
                            goto case 6;
                        break;
                }
                sb.Append(coin);
            }
            return sb.ToString();
        }

        private void RunGA(string[] pop)
        {
            int genCount = 0;

            do
            {
                string[] nextGen = CreateNextGeneration(pop,genCount);
                nextGen.CopyTo(pop, 0);
                genCount++;
                DisplayGeneration(pop, genCount);

            } while (!SolutionFound(pop));
        }

        private string[] CreateNextGeneration(string[] pop,int genCount)
        {
            string[] nextGen = new string[POP_SIZE];

            for (int index = 0; index < POP_SIZE; index++)
            {
                string copyOfParent = PickAFitParent(pop,genCount);
                string child = ApplyMutation(copyOfParent, MUTATION_RATE);
                nextGen[index] = child;
            }

            return nextGen;
        }

        private string PickAFitParent(string[] pop,int genCount)
        {
            int parentIndex1 = rnd.Next(POP_SIZE);
            int parentIndex2 = rnd.Next(POP_SIZE);

            string copyOfParent;

            if (FitnessOf(pop[parentIndex1]) < FitnessOf(pop[parentIndex2]))
                copyOfParent = pop[parentIndex1];
            else
                copyOfParent = pop[parentIndex2];

            return copyOfParent;
        }

        private string ApplyMutation(string genome, double mutationRate)
        {
            StringBuilder sb = new StringBuilder(genome);

            for (int gene = 0; gene < GENOME_SIZE; gene++)
                if (rnd.NextDouble() < mutationRate)
                {
                    int rndnum = rnd.Next(6);
                    char coin = 'p';
                    switch (rndnum)
                    {
                        case 6:
                            coin = 'z';
                            if (!checkBox_dollar.Checked)
                                goto case 5;
                            break;
                        case 5:
                            coin = 'h';
                            if (!checkBox_halfdollar.Checked)
                                goto case 4;
                            break;
                        case 4:
                            coin = 'q';
                            if (!checkBox_quater.Checked)
                                goto case 3;
                            break;
                        case 3:
                            coin = 'd';
                            if (!checkBox_dime.Checked)
                                goto case 2;
                            break;
                        case 2:
                            coin = 'n';
                            if (!checkBox_nickel.Checked)
                                goto case 1;
                            break;
                        case 1:
                            coin = 'p';
                            if (!checkBox_penny.Checked)
                                goto case 6;
                            break;
                    }

                    
                    sb.Replace(sb[gene], coin,gene,1);
                }

            return sb.ToString();
        }

        private int FitnessOf(string genome)
        {
            int fitness = TARGET - GenomeValue(genome) ;
            return Math.Abs(fitness);
        }
        private int FitnessOfNoABS(string genome)
        {
            int fitness = TARGET - GenomeValue(genome);
            return fitness;
        }

        private bool SolutionFound(string[] pop)
        {
            foreach (string genome in pop)
                if (GenomeValue(genome) == TARGET)
                    return true;

            return false;
        }

        private int GenomeValue(string genome)
        {
            int value = 0;
            foreach (char coin in genome){
                switch (coin)
                {
                    case 'p':
                        value += (int)Coins.penny;
                        break;
                    case 'n':
                        value += (int)Coins.nickel;
                        break;
                    case 'd':
                        value += (int)Coins.dime;
                        break;
                    case 'q':
                        value += (int)Coins.quarter;
                        break;
                    case 'h':
                        value += (int)Coins.halfdollar;
                        break;
                    case 'z':
                        value += (int)Coins.dollar;
                        break;
                }
                    
                //if(coin == 'p')
                //    value += (int) Coins.penny;
                //else if(coin == 'n')
                //    value += (int) Coins.nickel;
                //else if(coin == 'd')
                //    value += (int) Coins.dime;
                //else if(coin == 'q')
                //    value += (int) Coins.quarter;
                //else if(coin == 'h')
                //    value += (int) Coins.halfdollar;
                //else if(coin == 'z')
                //    value += (int) Coins.dollar;
            }
            return value;
        }

        private void DisplayGeneration(string[] pop, int genCount)
        {
            textBox1.Clear();
            closest = 100000;
            int genfitness = 0;
            foreach (string genome in pop)
            {
                int fitness = FitnessOf(genome);
                string targetselect = (fitness == 0) ? "<<<<" : "";
                textBox1.Text += genome + " "
                    + "[" + fitness + "] [" + GenomeValue(genome) + "]" + targetselect + "\r\n\n";
                closest = ( fitness < closest) ? fitness : closest;
                genfitness += FitnessOfNoABS(genome);
                totalfitness += FitnessOfNoABS(genome);
                totalgenomes++;
            }

            textBox1.Refresh();

            
            textBox2.Clear();
            textBox2.Text += "closest: " + closest + "\r\n";
            textBox2.Text += "generation average: " + (genfitness / POP_SIZE) + "\r\n";
            textBox2.Text += "total population: " + totalgenomes + "\r\n";
            textBox2.Text += "population average: " + (totalfitness / totalgenomes) + "\r\n";
            textBox2.Text += "Gen = " + genCount.ToString();
            textBox2.Refresh();
            
        }

        private void Target_Value_ValueChanged(object sender, EventArgs e)
        {
            TARGET = (int) Target_Value.Value;
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            MUTATION_RATE = (double)numericUpDown1.Value;
        }

        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {
            POP_SIZE = (int)numericUpDown2.Value;
        }

        private void numericUpDown3_ValueChanged(object sender, EventArgs e)
        {
            GENOME_SIZE = (int)numericUpDown3.Value;
        }
    }
}
