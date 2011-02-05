using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using GameEngine.SceneGraph;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;

namespace GAM205Tutorial
{
    public class GameScene : Scene
    {
        #region members
        List<Block> _blocks = new List<Block>();
        Player _player;
        #endregion members

        #region properties
        #endregion properties

        #region constructors
        public GameScene(IServiceProvider graphicsContainer) : base(graphicsContainer) { }
        protected override void Initalize()
        {
            CreatePlayer();
            CreatePlatform();
            BindPlayerMoveControls();
            base.Initalize();
        }
        #endregion construcors

        #region methods
        protected override void Update(GameTime gameTime)
        {
            UpdatePlayerCollisionWithBlocks();

            base.Update(gameTime);
        }

        /// <summary>
        /// Checks for collision between the player and all the blocks in this scene.
        /// </summary>
        private void UpdatePlayerCollisionWithBlocks()
        {
            foreach (Block platformBlock in _blocks)
                _player.CheckCollision(platformBlock);
        }

        /// <summary>
        /// Creates a series of 10 blocks centered on the screen.
        /// </summary>
        private void CreatePlatform()
        {
            Vector2 blockPosition = new Vector2(352f, 500f);
            for (int x = 0; x < 10; x++)
            {
                _blocks.Add(new Block(Content.Load<Texture2D>("BlockA0"), blockPosition));
                Drawables.Add(_blocks.Last());
                blockPosition.X += 64f;
            }
        }

        /// <summary>
        /// Creates an instance of the player.
        /// </summary>
        private void CreatePlayer()
        {
            _player = new Player(Content.Load<Texture2D>("megaman"), new Vector2(623f, 300f));
            Drawables.Add(_player);
        }

        /// <summary>
        /// Binds the left and right arrow keys to move the player.
        /// </summary>
        private void BindPlayerMoveControls()
        {
            Input.GetKey(Microsoft.Xna.Framework.Input.Keys.Left).ButtonDown += _player.MoveLeft;
            Input.GetKey(Microsoft.Xna.Framework.Input.Keys.Left).ButtonReleased += _player.StopMovement;
            Input.GetKey(Microsoft.Xna.Framework.Input.Keys.Right).ButtonDown += _player.MoveRight;
            Input.GetKey(Microsoft.Xna.Framework.Input.Keys.Right).ButtonReleased += _player.StopMovement;
            Input.GetKey(Microsoft.Xna.Framework.Input.Keys.Space).ButtonPushed += _player.Jump;
            Input.GetKey(Microsoft.Xna.Framework.Input.Keys.Space).ButtonDown += _player.HoldJump;
            Input.GetKey(Microsoft.Xna.Framework.Input.Keys.Space).ButtonReleased += _player.EndJump;
        }
        #endregion methods
    }
}