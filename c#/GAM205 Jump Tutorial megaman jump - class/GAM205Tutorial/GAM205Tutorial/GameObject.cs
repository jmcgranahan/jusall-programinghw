using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using GameEngine.Drawables;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace GAM205Tutorial
{
    public class GameObject : Sprite
    {
        #region members
        private Vector2 _velocity = Vector2.Zero;
        private Dictionary<GameObject, CollisionType> _collidingWith = new Dictionary<GameObject, CollisionType>();
        #endregion members

        #region properties
        /// <summary>
        /// A dictionary containing a list of things this object is colliding with.
        /// </summary>
        public Dictionary<GameObject, CollisionType> CollidingWith
        {
            get { return _collidingWith; }
        }
        /// <summary>
        /// This GameObject's X Velocity.
        /// </summary>
        public float XVelocity
        {
            get { return _velocity.X; }
            set { _velocity.X = value; }
        }

        /// <summary>
        /// This GameObject's Y Velocity.
        /// </summary>
        public float YVelocity
        {
            get { return _velocity.Y; }
            set { _velocity.Y = value; }
        }
        #endregion properties

        #region constructors
        public GameObject(Texture2D texture, Vector2 position) : base(texture, position) { }
        #endregion construcors

        #region methods
        /// <summary>
        /// Updates this GameObject's position by applying it's velocity.
        /// </summary>
        private void UpdatePosition()
        {
            X += XVelocity;
            Y += YVelocity;
        }

        public void CheckCollision(GameObject target)
        {
            CollisionType collision = CollisionType.None;

            // check each side for collision
            if (BoundingBox.Left <= target.BoundingBox.Right && BoundingBox.Left >= target.BoundingBox.Left)
                collision |= CollisionType.Left;
            if (BoundingBox.Right >= target.BoundingBox.Left && BoundingBox.Right <= target.BoundingBox.Right)
                collision |= CollisionType.Right;
            if (BoundingBox.Bottom >= target.BoundingBox.Top && BoundingBox.Bottom <= target.BoundingBox.Bottom)
                collision |= CollisionType.Bottom;
            if (BoundingBox.Top <= target.BoundingBox.Bottom && BoundingBox.Top >= target.BoundingBox.Top)
                collision |= CollisionType.Top;

            // make sure there's actual collision (collision on a side and top/bottom)
            if ((collision & (CollisionType.Top | CollisionType.Bottom)) > (CollisionType.Left | CollisionType.Right) &&
                 (collision & (CollisionType.Left | CollisionType.Right)) > 0)
                _collidingWith.Add(target, collision);
        }

        public override void Update(GameTime gameTime)
        {
            _collidingWith.Clear();
            UpdatePosition();
            base.Update(gameTime);
        }
        #endregion methods
    }
}