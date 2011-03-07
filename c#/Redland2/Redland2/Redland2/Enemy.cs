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

        public Enemy() : base(false)
        {
        }

        public override void Update(GameTime gameTime)
        {
            base.Update(gameTime);
            base.ZeroVelocity();
        }
    }
}
