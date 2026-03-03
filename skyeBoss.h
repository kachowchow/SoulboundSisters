#ifndef SKYEBOSS_H
#define SKYEBOSS_H

#include "Boss.h"

class SkyeBoss : public Boss {
      private:
            int currentStage;

      public:
            SkyeBoss();
            
            void setStage(int stageNumber);
            void move() override;
            void attack() override;
};

#endif