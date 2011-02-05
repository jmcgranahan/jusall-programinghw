using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;

namespace GAM205Tutorial
{
    public class TutorialGame : Game
    {
        private GraphicsDeviceManager _graphics;
        public TutorialGame()
        {
            _graphics = new GraphicsDeviceManager(this);
        }
        protected override void Initialize()
        {
            _graphics.PreferredBackBufferWidth = 1280;
            _graphics.PreferredBackBufferHeight = 720;
            Window.Title = "GAM205 Tutorial Project";
            _graphics.ApplyChanges();

            GameScene _startingScene = new GameScene(this.Services);
            Components.Add(GameEngine.Wrappers.SceneComponentWrapper.CreateSceneComponentWrapper(this, _startingScene));
            base.Initialize();
        }
    }
}
