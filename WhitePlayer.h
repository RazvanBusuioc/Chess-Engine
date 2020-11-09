using namespace std;
#ifndef WHITEPLAYER_H_
#define WHITEPLAYER_H_
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Player.h" 

class WhitePlayer : public Player{
    private:
    public:
        WhitePlayer();
        WhitePlayer(Table *table);
        void asign_pieces();
};

#endif