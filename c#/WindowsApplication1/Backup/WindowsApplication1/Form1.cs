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

            string axiom = "a";
            string[] rules = new string[10];
            rules[0] = "a->b";
            rules[1] = "b->c";
            rules[2] = "c->d";
            rules[3] = "d->e";
            rules[4] = "e->f";
            rules[5] = "f->g";
            rules[6] = "g->h";
            rules[7] = "h->i";
            rules[8] = "i->j";
            rules[9] = "j->tits";
   
            int numGens = 100;
            textBox1.Text = "Axiom = " + axiom + "\r\n";
            string thisgen = axiom;

            for (int gen = 0; gen < numGens; gen++)
            {
                foreach (char c in thisgen)
                {
                    bool foundRule = false;
                    foreach (string rule in rules)
                    {
                        if (rule[0] == c)
                        {
                            sb.Append(rule.Substring(3));
                            foundRule = true;
                            break;
                        }
                    }
                    if (!foundRule)
                        sb.Append(c);
                }
                thisgen = sb.ToString();
                sb.Length = 0;

                textBox1.Text += "Gen = " + gen.ToString() + " = " + thisgen + "\r\n";
            }
        
        }
    }
}