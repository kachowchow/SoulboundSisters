#ifndef JETTBOSS_H
#define JETTBOSS_H

#include "boss.h"

class JettBoss : public Boss {
      public: 
            JettBoss();

            void dashAttack();
            void fireKnife();
            void move() override;
            void attack() override;
};

#endif