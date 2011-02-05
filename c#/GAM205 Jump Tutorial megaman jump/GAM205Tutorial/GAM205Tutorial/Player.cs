using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;

namespace GAM205Tutorial
{
    public partial class Player : GameObject
    {
        #region members
        private const float PLAYER_MOVE_SPEED = 3f;
        
        #endregion members

        #region properties
        #endregion properties

        #region constructors
        public Player(Texture2D texture, Vector2 position) : base(texture, position) { }
        #endregion construcors

        #region methods
        public override void Update(GameTime gameTime)
        {
            YVelocity = 0;

            CheckIfStanding();

            UpdatePlayer();


            base.Update(gameTime);
        }


        private void CheckIfStanding()
        {
            if (CollidingWith.Count(o => (o.Key is Block) && ((o.Value & CollisionType.Bottom) == CollisionType.Bottom)) == 0)
            {
                _standing = false;
            }
            else
                _standing = true;
        }

        /// <summary>
        /// Move the player to the right.
        /// </summary>
        public void MoveRight()
        {
            XVelocity = PLAYER_MOVE_SPEED;
        }

        /// <summary>
        /// Move the player to the left.
        /// </summary>
        public void MoveLeft()
        {
            XVelocity = -PLAYER_MOVE_SPEED;
        }

        /// <summary>
        /// Stop the player's X movement.
        /// </summary>
        public void StopMovement(int duration)
        {
            XVelocity = 0f;
        }
        #endregion methods
    }
}