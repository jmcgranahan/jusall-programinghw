using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using GameEngine.SceneGraph;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;



namespace Redland2
{
    class Enemy : Player
    {
        Random rand = new Random((int)DateTime.Now.Ticks);
        public Enemy() : base(false)
        {
            base.Position = new Vector2(rand.Next(1280),rand.Next(700));
        }

        public override void Update(GameTime gameTime)
        {
            base.Update(gameTime);
            base.ZeroVelocity();
        }
    }
}
