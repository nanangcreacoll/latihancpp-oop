#include "Player.hpp"
#include <iostream>

using namespace std;


Player::Player(const char* name)
{
    this->name = name;
}

void Player::display()
{
    cout << "Player ini adalah " << this->name << endl;
}