using namespace std;
#ifndef KNIGHT_H_
#define KNIGHT_H_
#include "CommonHeaders.h"
#include "Piece.h"
class Table;

class Knight : public Piece{
    private:

    public:
        Knight();
        Knight(string name, string color, string currentPosition, Table *table);
        void setRange();
};

#endif