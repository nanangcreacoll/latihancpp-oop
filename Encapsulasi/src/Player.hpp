#ifndef __PLAYER
#define __PLAYER

#include <string>

using namespace std;

class Player
{
    private:
        string name;

    public:
        Player(const char*);
        void display();
};

#endif
