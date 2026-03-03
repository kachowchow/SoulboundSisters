#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
      private:
            float damage;
            float critChance;
            float attackSpeed;
            int level;

      public:
            Weapon();
            void autoUpgrade(int currentKills);
};

#endif