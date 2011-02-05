using System;

namespace GAM205Tutorial
{
#if WINDOWS || XBOX
    static class Program
    {
        static void Main(string[] args)
        {
            using (TutorialGame game = new TutorialGame())
                game.Run();
        }
    }
#endif
}

