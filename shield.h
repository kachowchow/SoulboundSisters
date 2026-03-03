#ifndef SHIELD_H
#define SHIELD_H

#include "Collectible.h"

class Shield : public Collectible {
      protected:
            int shieldAmount;
      public:
            Shield();
            
            virtual ~Shield() = default;
            void collect() override;
};

#endif