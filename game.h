#ifndef GAME_H
#define GAME_H
class Game {
      private:
            int currentLevel;

      public:
            Game();
            
            void restartGame(); [cite_start]// [cite: 7]
            void saveCheckpoint(); [cite_start]// [cite: 55]
            void updateHUD();
};

#endif