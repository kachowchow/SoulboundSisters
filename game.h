#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Defines the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN,
    GAME_OVER
};

class Game {
      private:
            int currentLevel;

      public:
            GameState state;
            bool keys[1024];
            unsigned int width, height;

            Game(unsigned int width, unsigned int height);
            ~Game();

            void Init();
            void ProcessInput(float dt);
            void Update(float dt);
            void Render();

            void restartGame();
            void updateHUD();
};

#endif