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
        private Human[] humans;
        private int[,] field, humanField, sickField, infectedField, humanFieldBuffer, sickFieldBuffer, infectedFieldBuffer;

        static Random rand = new Random();

        public World(int initWidth, int initHeight, int numHumans, int perImmune)
        {
            field = new int[initWidth, initHeight];

            humanField = new int[initWidth, initHeight];
            humanFieldBuffer = new int[initWidth, initHeight];

            sickField = new int[initWidth, initHeight];
            sickFieldBuffer = new int[initWidth, initHeight];

            infectedField = new int[initWidth, initHeight];
            infectedFieldBuffer = new int[initWidth, initHeight];

            height = initHeight;
            width = initWidth;
            
            humans = new Human[numHumans];
            for (int i = 0; i < numHumans; i++)
            {
                humans[i] = new Human(this, ((rand.Next(100) < perImmune) ? true : false));
            }
            humans[0].Infected = true;
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
            foreach (Human human in humans)
            {
                human.TimeStep();
            }

            humanField = humanFieldBuffer;
            sickField = sickFieldBuffer;
            infectedField = infectedFieldBuffer;
            humanFieldBuffer = new int[width, height];
            sickFieldBuffer = new int[width, height];
            infectedFieldBuffer = new int[width, height];
        }

        public Human[] Humans
        {
            get
            {
                return humans;
            }

        }

        public int[,] HumanField
        {
            get
            {
                return humanField;
            }
        }

        public int[,] SickField
        {
            get
            {
                return sickField;
            }

        }

        public int[,] InfectedField
        {
            get
            {
                return infectedField;
            }

        }

        public void HumanMark(int x, int y)
        {
            humanFieldBuffer[x, y]++;
        }

        public void SickMark(int x, int y)
        {
            sickFieldBuffer[x, y]++;
        }

        public void InfectedMark(int x, int y)
        {
            infectedFieldBuffer[x, y]++;
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

        public void SetSpace(int x, int y, int material)
        {
            field[x, y] = material;
        }

        public bool IsOpen(int x, int y)
        {
            return field[x, y] == 0;
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
