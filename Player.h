using namespace std;
#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 
#include "Pieces/Headers/Piece.h"
#include "Table.h"


class Player{
    protected:
        vector<Piece *> pieces;
        vector<pair<CartPoint*, CartPoint*>> moves;
        string color;
        Table *table;
    public:
        Player();
        Player(string color, Table *table);
        bool is_on_move();   
        bool is_engine_on();
        bool is_on_check();
        bool is_on_check_mate();
        bool is_on_stale_mate();
        void add_piece(Piece *piece);
        string get_color();
        int get_number_of_pieces();
        vector<Piece *> get_pieces();
        vector<pair<CartPoint*, CartPoint*>> get_moves();

};
#endif