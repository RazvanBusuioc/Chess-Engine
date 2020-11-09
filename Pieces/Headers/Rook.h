using namespace std;
#ifndef ROOK_H_
#define ROOK_H_
#include "CommonHeaders.h"
#include "Piece.h"
class Table;

class Rook : public Piece{
    private:

    public:
        Rook();
        Rook(string name, string color, string currentPosition, Table *table);
        void setRange();
};

#endif