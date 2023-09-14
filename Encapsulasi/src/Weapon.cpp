#include "Weapon.hpp"

#include <iostream>

using namespace std;


Weapon::Weapon(const char* name, double attackPower)
{
    this->name = name;
    this->attackPower = attackPower;
}

void Weapon::display()
{
    cout << "Weapon ini adalah " << this->name;
    cout << ", Power = " << this->attackPower << endl;
}