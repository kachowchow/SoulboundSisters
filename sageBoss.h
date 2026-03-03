#ifndef SAGEBOSS_H
#define SAGEBOSS_H

#include "Boss.h"

class SageBoss : public Boss {
      public:
            SageBoss();

            void deployWallShield();
            void reviveBots();
            void castSlowOrbs();
            
            void move() override;
            void attack() override;
      };

#endif