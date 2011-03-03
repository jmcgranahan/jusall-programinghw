using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using GameEngine.Drawables;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;

namespace Redland2
{
    public class Entity : Sprite
    {
        #region members
            private Vector2 _velocity = Vector2.Zero;
        #endregion members

        #region properties
            /// <summary>
            /// Gets/Sets the X component of the _velocity vector.
            /// </summary>
            public float XVelocity
            {
                get { return _velocity.X; }
                set { _velocity.X = value; }
            }

            /// <summary>
            /// Gets/Sets the Y component of the _velocity vector.
            /// </summary>
            public float YVelocity
            {
                get { return _velocity.Y; }
                set { _velocity.Y = value; }
            }
        #endregion properties

        #region constructors
            public Entity(Texture2D texture, Vector2 position) : base(texture, position)
            {
                
            }
        #endregion construcors

        #region methods
            public override void Update(GameTime gameTime)
            {
                this.Position += _velocity;

                base.Update(gameTime);
            }
        #endregion methods
    }
}
