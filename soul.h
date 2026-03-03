#ifndef SOUL_H
#define SOUL_H

#include "Collectible.h"

class Soul : public Collectible {
      public:
            Soul();
            void collect() override;
};

#endif