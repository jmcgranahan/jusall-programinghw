using System;
using System.Collections.Generic;
using GameEngine.SceneGraph;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;

using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Input;

namespace Redland2
{
    public class Player : Entity
    {
        private const float PLAYER_MOVE_SPEED = 3.0F;
        private const Keys MOVE_UP_BUTTON = Keys.W;
        private const Keys MOVE_DOWN_BUTTON = Keys.S;
        private const Keys MOVE_LEFT_BUTTON = Keys.A;
        private const Keys MOVE_RIGHT_BUTTON = Keys.D;
        private const int PLAYER_IDLE_FRAME = 4;
        private int _keyspressed = 0;
        private Vector2 _target = Vector2.Zero;
        private bool _playerOne = false;

        public void moveUp()
        {
            this.YVelocity -= PLAYER_MOVE_SPEED;
        }
        public void moveDown()
        {
            this.YVelocity += PLAYER_MOVE_SPEED;
        }
        public void moveLeft()
        {
            this.XVelocity -= PLAYER_MOVE_SPEED;
        }
        public void moveRight()
        {
            this.XVelocity += PLAYER_MOVE_SPEED;
        }


        public void moveForward()
        {
            Vector2 direction = this.Position - Scene.Current.Input.GetMousePosition();
            if (direction.Length() < 30)
                return;
            direction.Normalize();
            direction *= PLAYER_MOVE_SPEED;

            this.XVelocity += -direction.X;
            this.YVelocity += -direction.Y;
        }
        public void moveBackward()
        {
            Vector2 direction = this.Position - Scene.Current.Input.GetMousePosition();
            direction.Normalize();
            direction *= PLAYER_MOVE_SPEED;

            this.XVelocity += direction.X;
            this.YVelocity += direction.Y;
        }
        public void strafeLeft()
        {
            Vector2 direction = this.Position - Scene.Current.Input.GetMousePosition();
            direction.Normalize();
            direction = Vector2.Transform(direction, Matrix.CreateRotationZ(1.57079633F));

            direction *= PLAYER_MOVE_SPEED;
            this.XVelocity += -direction.X;
            this.YVelocity += -direction.Y;
        }
        public void strafeRight()
        {
            Vector2 direction = this.Position - Scene.Current.Input.GetMousePosition();
            direction.Normalize();
            direction = Vector2.Transform(direction, Matrix.CreateRotationZ(-4.71238898F));

            direction *= PLAYER_MOVE_SPEED;
            this.XVelocity += direction.X;
            this.YVelocity += direction.Y;
        }


        public void startWalking()
        {
            _keyspressed++;
            this.AnimationData.Animated = true;
        }
        public void stopWalking(int duration)
        {
            _keyspressed--;
            if (_keyspressed == 0)
            {
                this.AnimationData.Animated = false;
                this.AnimationData.Frame = PLAYER_IDLE_FRAME;
            }
        }

        private void BindControls()
        {
            _playerOne = true;
            Scene.Current.Input.GetKey(MOVE_UP_BUTTON).ButtonPushed += startWalking;
            Scene.Current.Input.GetKey(MOVE_UP_BUTTON).ButtonDown += moveForward;
            Scene.Current.Input.GetKey(MOVE_UP_BUTTON).ButtonReleased += stopWalking;

            Scene.Current.Input.GetKey(MOVE_DOWN_BUTTON).ButtonPushed += startWalking;
            Scene.Current.Input.GetKey(MOVE_DOWN_BUTTON).ButtonDown += moveBackward;
            Scene.Current.Input.GetKey(MOVE_DOWN_BUTTON).ButtonReleased += stopWalking;

            Scene.Current.Input.GetKey(MOVE_LEFT_BUTTON).ButtonPushed += startWalking;
            Scene.Current.Input.GetKey(MOVE_LEFT_BUTTON).ButtonDown += strafeLeft;
            Scene.Current.Input.GetKey(MOVE_LEFT_BUTTON).ButtonReleased += stopWalking;

            Scene.Current.Input.GetKey(MOVE_RIGHT_BUTTON).ButtonPushed += startWalking;
            Scene.Current.Input.GetKey(MOVE_RIGHT_BUTTON).ButtonDown += strafeRight;
            Scene.Current.Input.GetKey(MOVE_RIGHT_BUTTON).ButtonReleased += stopWalking;

        }

        public void ZeroVelocity()
        {
            this.XVelocity = 0.0F;
            this.YVelocity = 0.0F;
        }

        public Player(bool PlayerOne) : base(GameScene.Current.Content.Load<Texture2D>("player"), new Vector2(200,200))
        {
            SetupPlayer();
            if(PlayerOne)
                BindControls();
            Scene.Current.Drawables.Add(this);
        }

        public void RotatePlayerToFacePoint(Vector2 Target)
        {
            Vector2 direction = this.Position - Target;
            direction.Normalize();
            this.Angle = (float)Math.Atan2(direction.Y, direction.X) - MathHelper.PiOver2;
        }

        public Vector2 TargetPos
        {
            get{    return _target; }
            set{    _target = value;    }
        }

        public void SetupPlayer()
        {
            this.Layer = 0.9F;
            this.AnimationData.RowsColumns = new Vector2(4, 4);
            this.AnimationData.BeginEndFrames = new Vector2(0, 15);
            this.AnimationData.Frame = 4;
            this.AnimationData.AnimationSpeed = 0.035f;
            this.SetOffset(GameEngine.Drawables.Anchor.Center);            
        }

        public override void Update(GameTime gameTime)
        {
            if (_playerOne)
                _target = Scene.Current.Input.GetMousePosition();
            RotatePlayerToFacePoint(_target);
            base.Update(gameTime);
            ZeroVelocity();
        }

    }
}
