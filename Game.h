using namespace std;
#ifndef GAME_H_
#define Game_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <bits/stdc++.h>
#include <vector>
#include "BoardEvaluator.h"
#include "Table.h"
#include "Player.h"
#include "BlackPlayer.h"
#include "WhitePlayer.h"
#include "XboardInterface.h"

#define MINMAX_DEPTH 3

class Game{
    public:
        Game();
        void startGame();
        void displayCurrentState();
        void setMyColor(string color);
        void setOpponentColor(string color);
        string get_move();
        int make_move(string move);
        int init_game();
        int new_game();
        BoardEvaluator *board_evaluator;
        XboardInterface *xboard;
    private:
        Table *table;
        WhitePlayer *white_player;
        BlackPlayer *black_player;
        Player *opponent_player;
        Player *engine_player;
        bool force;
        bool resign;
        int debug_fd;
};

#endif