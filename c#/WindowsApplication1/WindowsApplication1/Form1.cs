using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;


namespace WindowsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            StringBuilder sb = new StringBuilder(1000);
            int NUMRULES = 10;
            string axiom = axiomtextbox.Text;
            string[,] rules = new string[NUMRULES, 2];
            textBox1.Text = "";
            for (int i = 0; i < NUMRULES; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    rules[i, j] = "";
                }
            }

            //blockrules  not positive on better way to do this
            rules[0,0] = rule00.Text;
            rules[0,1] = rule01.Text;
            rules[1,0] = rule10.Text;
            rules[1,1] = rule11.Text;
            rules[2,0] = rule20.Text;
            rules[2,1] = rule21.Text;
            rules[3,0] = rule30.Text;
            rules[3,1] = rule31.Text;
            rules[4,0] = rule40.Text;
            rules[4,1] = rule41.Text;
            rules[5,0] = rule50.Text;
            rules[5,1] = rule51.Text;
            rules[6,0] = rule60.Text;
            rules[6,1] = rule61.Text;
            rules[7,0] = rule70.Text;
            rules[7,1] = rule71.Text;
            //end rules
            decimal numGens = genselect.Value;
            if (rules[0, 0].Length == 0)
            {
                textBox1.Text = "please enter a rule in the first slot \r\n";
                numGens = 0;
            }

              

   
            
            textBox1.Text += "Axiom = " + axiom + "\r\n";
            string thisgen = axiom;

            for (int gen = 0; gen < numGens; gen++)
            {
                foreach (char c in thisgen)
                {
                    bool foundRule = false;
                    int i = 0;
                    while(i < NUMRULES && !foundRule)
                    {
                        if ((rules[i, 0].Length != 0) && (rules[i, 0][0] == c))
                        {
                            sb.Append(rules[i,1]);
                            foundRule = true;
                            break;
                        }
                        i++;
                    }
                    if (!foundRule)
                        sb.Append(c);
                }
                thisgen = sb.ToString();
                sb.Length = 0;

                textBox1.Text += "Gen " + (gen+1).ToString() + " = " + thisgen + "\r\n";
            }
        
        }

    }
}