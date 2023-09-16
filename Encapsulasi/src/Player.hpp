#ifndef __PLAYER
#define __PLAYER

#include <string>
#include <iostream>
#include "Weapon.hpp"

using namespace std;

class Player
{
    private:
        string name;
        Weapon* weapon;

    public:
        Player(const char*);
        void display();

        // setter
        void equipWeapon(Weapon*);
};

#endif
