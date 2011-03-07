using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;
using GameEngine.SceneGraph;


namespace Redland2
{
    public class Bullet : Entity
    {
        #region members
        private const float BULLET_BASE_SPEED = 7.0f;
        private int damage;
        #endregion members

        #region properties
        #endregion properties

        #region constructors
        public Bullet(Vector2 position, Vector2 direction) : base(GameScene.Current.Content.Load<Texture2D>("bullet"), position)
        {
            SetupBullet();
            direction.Normalize();
            this.Velocity = direction * BULLET_BASE_SPEED;
            Scene.Current.Drawables.Add(this);
        }

        private void SetupBullet()
        { 
            this.SetOffset(GameEngine.Drawables.Anchor.Center);
        }
        #endregion constructors

        #region methods
        public void RotateTodirection()
        {
            Vector2 direction = this.Velocity;
            direction.Normalize();
            this.Angle = (float)Math.Atan2(direction.Y, direction.X) - MathHelper.PiOver2;
        }

        public override void Update(GameTime gameTime)
        {
            RotateTodirection();
            base.Update(gameTime);
        }

        public bool offscreen()
        {
            if (this.Position.X > 0 && this.Position.Y > 0 && this.Position.X < 1280 && this.Position.Y < 700)
                return false;
            return true;
        }
        #endregion methods 
    }
}
