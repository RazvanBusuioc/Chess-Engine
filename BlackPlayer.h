using namespace std;
#ifndef BLACKPLAYER_H_
#define BLACKPLAYER_H_
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Player.h" 

class BlackPlayer : public Player{
    private:
    public:
        BlackPlayer();
        BlackPlayer(Table *table);
        void asign_pieces();
};

#endif