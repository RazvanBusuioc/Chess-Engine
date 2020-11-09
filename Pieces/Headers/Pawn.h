using namespace std;
#ifndef PAWN_H_
#define PAWN_H_
#include "CommonHeaders.h"
#include "Piece.h"
class Table;

class Pawn : public Piece{
    private:
        bool enPassantVulnerability;
        vector<CartPoint *> attacking_range;
    public:
        Pawn();
        Pawn(string name, string color, string currentPosition, Table *table);    
        void setRange();
        void printRange();
        vector<CartPoint *> get_attacking_range();
        void setCartPosition(int x, int y);
        void setEnPassant(bool eP);
        bool getEnPassant();
        bool has_in_attacking_range(int y, int x);
};

#endif