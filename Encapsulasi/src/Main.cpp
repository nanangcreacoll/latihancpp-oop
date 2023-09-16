#include <iostream>
#include <string>

#include "Player.hpp"
#include "Weapon.hpp"

using namespace std;

int main()
{
    Player* player1 = new Player("Sniper");
    Weapon* weapon1 = new Weapon("Senapan", 50);

    player1->equipWeapon(weapon1);

    player1->display();
    weapon1->display();

    return 0;
}
