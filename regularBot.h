#ifndef REGULARBOT_H
#define REGULARBOT_H

#include "enemy.h"
class RegularBot : public Enemy {
      public:
            RegularBot();

            void move() override;
            void attack() override;
};

#endif