#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

class Collectible {
      public:
            Collectible();
            virtual ~Collectible() = default;
            virtual void collect() = 0;
};

#endif