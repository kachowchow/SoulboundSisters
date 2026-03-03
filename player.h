#ifndef PLAYER_H
#define PLAYER_H

class Player { 
      private: 
            int killCount; 
            int soulCount; 
            int ultimateBar;
            int shieldHealth;
            int health;
      public: 
            Player(); 

            void attack();
            void dashAttack();
            void cabbageAttack();

            enum class SoulEffect {
                  Healing, 
                  Invulnerability
            };

            void consumeSoul (SoulEffect effect);

            void triggerUltimate();

            void takeDamage (int damage);

            void die();
};

#endif