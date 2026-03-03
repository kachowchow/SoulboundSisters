#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
class Boss : public Enemy {
public:
    Boss();
    virtual ~Boss() = default;
    
    void dropWeaponUpgrade();
};

#endif