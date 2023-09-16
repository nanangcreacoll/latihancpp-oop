#include "Player.hpp"

Player::Player(const char* name)
{
    this->name = name;
}

void Player::display()
{
    cout << "Player ini adalah\t: " << this->name << endl;
    cout << "Menggunakan senjata\t: " << this->weapon->getName() << endl;
}

void Player::equipWeapon(Weapon* weapon)
{
    this->weapon = weapon;
}