using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using GameEngine.SceneGraph;
using GameEngine.Drawables;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;

// Here's some useful stuff
// Properties: http://msdn.microsoft.com/en-us/library/x9fsa0sw%28v=VS.100%29.aspx
// Refactoring - Extract Method: http://msdn.microsoft.com/en-us/library/0s21cwxk.aspx
// Using statement - If you have a type that does not have using statement, click on it, and from the dropdown box choose the first option (using...)

namespace Redland2
{
    public class GameScene : Scene
    {
        #region members
            /// <summary>
            /// The grass sprite.
            /// </summary>
            private Sprite _grass;

            /// <summary>
            /// The cursor sprite.
            /// </summary>
            private Sprite _cursor;
            public Player _player;
            private SpriteFont font;
            private SpriteBatch _spritebatch;
            
        #endregion members

        #region properties
        #endregion properties

        #region constructors
            public GameScene(IServiceProvider graphicsContainer) : base(graphicsContainer)
            {

            }

            protected override void Initalize()
            {
                CreateGrass();
                CreateCursor();

                _player = new Player(true);
                font = Content.Load<SpriteFont>("myFont");
               
                //---------------------------

                base.Initalize();
            }

            /// <summary>
            /// Instantiates the cursor.
            /// Sets the cursor's layer.
            /// Offsets the cursor to be centered on it's position.
            /// </summary>
            private void CreateCursor()
            {
                _cursor = new Sprite(Content.Load<Texture2D>("cursor"), Vector2.Zero);
                _cursor.Layer = 1.0f;
                _cursor.SetOffset(Anchor.Center);
                Drawables.Add(_cursor);
            }

            /// <summary>
            /// Instantiates the grass sprite and puts it on the bottomost layer of the scene.
            /// </summary>
            private void CreateGrass()
            {
                _grass = new Sprite(Content.Load<Texture2D>("grass"), Vector2.Zero);
                _grass.Layer = 0.0f;
                Drawables.Add(_grass);
            }
        #endregion construcors

        #region methods
            protected override void Update(GameTime gameTime)
            {
                _cursor.Position = Input.GetMousePosition();
     
                base.Update(gameTime);
            }

        /*
            private void DebugText()
            {
                string debugstring = "DEBUG: ";
                debugstring += "Player Bullets: ";
                debugstring += _player._bullets.Count;
                _spritebatch.DrawString(font, debugstring, new Vector2(20, 20), Color.Red);
            }
         */
        #endregion methods
    }
}
