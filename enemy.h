#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
      protected: 
            int health;
            int level;

      public:
            Enemy();
            virtual ~Enemy() = default;

            virtual void move() = 0;
            virtual void attack() = 0;

            void dropLoot();
            void takeDamage(int damage);
};

#endif