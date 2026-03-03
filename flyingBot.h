#ifndef FLYINGBOT_H
#define FLYINGBOT_H

#include "Enemy.h"
class FlyingBot : public Enemy {
      public:
      FlyingBot();
      
      void move() override;
      void attack() override;
};

#endif