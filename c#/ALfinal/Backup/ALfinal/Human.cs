using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ALfinal
{
    public class Human
    {
        public enum Direction { North, NorthEast, East, SouthEast, South, SouthWest, West, NorthWest };
        public enum SpeedNum { Stop, Limp, Walk, Run, Sprint };
        private Direction dir;
        private SpeedNum speed;
        private int x, y, index, health, ticksSick, ticksNoZombie;
        private bool alive, sick, infected, panic, immune;
        private World world;
        private static Random rand = new Random();
        private static int Humans = 0;

        public Human(World w, bool immunity)
        {
            Humans++;
            index = Humans;
            immune = immunity;
            world = w;
            x = rand.Next(world.Width-10)+5;
            y = rand.Next(world.Height-10)+5;
            health = 100;
            ticksSick = 0;
            dir = (Direction)rand.Next(7);
            speed = SpeedNum.Walk;
            alive = true;
            panic = false;
        }

        private void Act()
        {
            if (alive)
            {
                if (health <= 0)
                    Kill();
                if (infected)
                    ActInfected();
                else
                    ActHuman();
            }
        }

        private void ActInfected()
        {
            speed = ((speed != SpeedNum.Stop)? SpeedNum.Limp: SpeedNum.Stop);
            for (int i = 0; i < HumansInRange(); i++)
                InfectedNom();

            for (int i = 0; i < InfectedInRange(); i++)
            {
                if (rand.Next(100) < 33)
                {
                    InfectedAttack();
                    InfectedNom();
                }
            }

            dir = AimAtHumans();
            Move();

        }

        private void ActHuman()
        {
            for (int i = 0; i < InfectedInRange(); i++)
            {
                panic = true;
                InfectedAttack();
            }

            if (InfectedInSight() > 0)
            {
                panic = true;
                ticksNoZombie = 0;
            }
            else
            {
                ticksNoZombie++;
                if (ticksNoZombie > 10)
                    panic = false;
            }

            if (sick)
            {
                sick = immune ? false : true;
                if (!sick)
                    return;
                ticksSick++;
                speed = SpeedNum.Limp;
                health -= 3;
                if (rand.Next(100) < ticksSick)
                {
                    infected = true;
                    health += 50;
                }
            }

            else if (panic)
            {
                speed =(InfectedInRange() > 4)? SpeedNum.Sprint: SpeedNum.Run;
                dir = AimAwayFromInfected();
            }
            else
            {
                speed = SpeedNum.Walk;
                if (rand.Next(10) < 5)
                    dir = (Direction)rand.Next(8);
                if ( rand.Next(100) > 50)
                    dir = AimAwayFromInfected();
                 
            }


            Move();
        }

        private Direction Aim(int aimx, int aimy)
        {
            Direction tempdir = dir;
            if (x == aimx)
            {
                if (y < aimy)
                    tempdir = Direction.South;
                else if (y > aimy)
                    tempdir = Direction.North;
            }

            else if (y == aimy)
            {
                if (x < aimx)
                    tempdir = Direction.East;
                else if (x > aimx)
                    tempdir = Direction.West;
            }

            else if (x < aimx)
            {
                if (y < aimy)
                    tempdir = Direction.SouthEast;
                else
                    tempdir = Direction.NorthEast;
            }

            else
            {
                if (y < aimy)
                    tempdir = Direction.SouthWest;
                else
                    tempdir = Direction.NorthWest;
            }
            return tempdir;
        }

        private int Move()
        {
            while ((int)dir < 0 || (int)dir > 7)
            {
                if ((int)dir > 7)
                    dir = (Direction)(0 + ((int)dir - 8));
                else if ((int)dir < 0)
                    dir = (Direction)(7 + ((int)dir + 1));
            }

            if (dir == Direction.East)
                return AttemptMove(1, 0);
            else if (dir == Direction.North)
                return AttemptMove(0, -1);
            else if (dir == Direction.NorthEast)
                return AttemptMove(1, -1);
            else if (dir == Direction.NorthWest)
                return AttemptMove(-1, -1);
            else if (dir == Direction.South)
                return AttemptMove(0, 1);
            else if (dir == Direction.SouthEast)
                return AttemptMove(1, 1);
            else if (dir == Direction.SouthWest)
                return AttemptMove(-1, 1);
            else if (dir == Direction.West)
                return AttemptMove(-1, 0);
            else
                return 0;

        }

        private int AttemptMove(int xMove, int yMove)
        {
            int Fx = x, Fy = y;
            for (int i = 0; i < (int)speed; i++)
            {
                Fx += xMove;
                Fy += yMove;
                Toroidal(ref Fx, ref Fy);
                if (!world.IsOpen(Fx, Fy))
                {
                    return 0;
                }
            }
            x = Fx;
            y = Fy;
            if (infected)
                world.InfectedMark(x, y);
            else if (sick)
                world.SickMark(x, y);
            else
                world.HumanMark(x, y);
            return 1;
        }

        private void Toroidal(ref int Fx, ref int Fy)
        {
            if (Fx > world.Width - 1)
                Fx = 0;
            else if (Fx < 0)
                Fx = world.Width - 1;

            if (Fy > world.Height - 1)
                Fy = 0;
            else if (Fy < 0)
                Fy = world.Height - 1;
        }

        private bool IsInFrontOf(int lookX, int lookY)
        {
            if (dir == Direction.East)
                return ((x < lookX) ? true : false);

            else if (dir == Direction.North)
                return ((y > lookY) ? true : false);

            else if (dir == Direction.NorthEast)
                return ((x < lookX) && (y < lookY) ? true : false);

            else if (dir == Direction.NorthWest)
                return ((x > lookX) && (y < lookY) ? true : false);

            else if (dir == Direction.South)
                return ((y < lookY) ? true : false);

            else if (dir == Direction.SouthEast)
                return ((x < lookX) && (y > lookY) ? true : false);

            else if (dir == Direction.SouthWest)
                return ((x > lookX) && (y > lookY) ? true : false);

            else if (dir == Direction.West)
                return ((x > lookX) ? true : false);
            else
                return false;


        }

        public int HumansInSight()
        {
            int found = 0;
            int[] vec = DirToVec();
            for (int r = 1; r < 4; r++)
            {
                for (int c = 0; c < (Math.Floor((double)r / 2) * 2 + 1); c++)
                {

                    int lookX = x + (r * vec[0]) + ((c - ((int)(r / 2))) * vec[1]);
                    int lookY = y + (r * vec[1]) + ((c - ((int)(r / 2))) * vec[0]);
                    Toroidal(ref lookX, ref lookY);
                    found += world.HumanField[lookX, lookY];
                }
            }
            return found;
        }

        public int InfectedInSight()
        {
            int found = 0;
            int[] vec = DirToVec();
            for (int r = 1; r < 7; r++)
            {
                for (int c = 0; c < (Math.Floor((double) r/3)*2+1); c++)
                {

                    int lookX = x + (r * vec[0]) + ((c - ((int)(r / 3))) * vec[1]);
                    int lookY = y + (r * vec[1]) + ((c - ((int)(r / 3))) * vec[0]);
                    Toroidal(ref lookX, ref lookY);
                    found += world.InfectedField[lookX, lookY];
                }
            }
            return found;
        }

        private int HumansInRange()
        {
            int found = 0;
            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int lookX = x + (r - 1);
                    int lookY = y + (c - 1);
                    Toroidal(ref lookX, ref lookY);
                    found += world.HumanField[lookX, lookY];
                }
            }
            return found;
        }

        private int InfectedInRange()
        {
            int found = 0;
            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int lookX = x + (r - 1);
                    int lookY = y + (c - 1);
                    Toroidal(ref lookX, ref lookY);
                    found += world.InfectedField[lookX, lookY];
                }
            }
            return found;
        }

        private void InfectedAttack()
        {
            health -= 2;
            if (!immune)
            {
                if (rand.Next(150) > health)
                    sick = true;
            }
        }

        private void InfectedNom()
        {
            health += 1;
        }

        private Direction AimAwayFromInfected()
        {
            Direction tempdir = (Direction)((int)dir + 4), olddir = dir;
            
            int most = 0;

            for (int i = 0; i < 9; i++)
            {
                dir = (Direction)i;
                if (InfectedInSight() > most)
                {
                    tempdir = dir;
                    most = InfectedInRange();
                }
                else if (InfectedInSight() >= most && InfectedInSight() != 0)
                {
                    tempdir = (rand.Next(100) > 50) ? dir : tempdir;
                }

                else if (InfectedInSight() >= most && InfectedInSight() == 0)
                {
                    tempdir = olddir + 4;
                }
            }
            dir = olddir;
            tempdir = (Direction)((int)tempdir + 4);
            return tempdir;
        }

        private Direction AimAtHumans()
        {
            Direction tempdir = dir, olddir = dir;

            int most = 0;

            for (int i = 0; i < 3; i++)
            {
                dir = (Direction)((int)olddir + (i - 1));
                if (HumansInSight() > most)
                {
                    tempdir = dir;
                    most = InfectedInRange();
                }
                else if (HumansInSight() >= most && HumansInSight() != 0)
                {
                    tempdir = (rand.Next(100) > 50) ? dir : tempdir;
                }

                else if (HumansInSight() >= most && HumansInSight() == 0)
                {
                    tempdir = olddir;
                }
            }
            dir = olddir;
            return tempdir;
        }

        private int[] DirToVec()
        {
            int[] vec = new int[2];

            while ((int)dir < 0 || (int)dir > 7)
            {
                if ((int)dir > 7)
                    dir = (Direction)(0 + ((int)dir - 8));
                else if ((int)dir < 0)
                    dir = (Direction)(7 + ((int)dir + 1));
            }

            if (dir == Direction.East)
            {
                vec[0] = 1;
                vec[1] = 0;
            }
            else if (dir == Direction.North)
            {
                vec[0] = 0;
                vec[1] = -1;
            }
            else if (dir == Direction.NorthEast)
            {
                vec[0] = 1;
                vec[1] = -1;
            }
            else if (dir == Direction.NorthWest)
            {
                vec[0] = -1;
                vec[1] = -1;
            }
            else if (dir == Direction.South)
                {
                vec[0] = 0;
                vec[1] = 1;
            }
            else if (dir == Direction.SouthEast)
            {
                vec[0] = 1;
                vec[1] = 1;
            }
            else if (dir == Direction.SouthWest)
            {
                vec[0] = -1;
                vec[1] = 1;
            }
            else if (dir == Direction.West)
            {
                vec[0] = -1;
                vec[1] = 0;
            }
            else
            {
                vec[0] = 0;
                vec[1] = 0;
            }
                return vec;

        }

        public void Kill()
        {
            alive = false;
        }

        public void Reset()
        {
            Humans = 0;
        }

        public void TimeStep()
        {
            if (health < 1)
                Kill();

            Act();
        }

        // just get's and set's below here

        public Direction Dir
        {
            get { return dir; }
            set { dir = value;}
        }

        public int TotalHumans
        {
            get { return Humans; }
            set { Humans = value;}
        }

        public int PosX
        {
            get { return x; }
            set { x = value;}
        }

        public int PosY
        {
            get { return y; }
            set { y = value;}
        }

        public int Index
        {
            get { return index; }
        }

        public bool Alive
        {
            get { return alive; }
            set { alive = value;}
        }

        public bool Sick
        {
            get { return sick; }
            set { sick = value;}
        }

        public bool Infected
        {
            get { return infected; }
            set { infected = value;}
        }

        public bool Panic
        {
            get { return panic; }
            set { panic = value;}
        }

        public SpeedNum Speed
        {
            get { return speed; }
            set { speed = value; }
        }
    }
}
