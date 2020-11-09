using namespace std;
#ifndef NOPIECE_H_
#define NOPIECE_H_
#include "CommonHeaders.h"
#include "Piece.h"
class Table;

class NoPiece : public Piece{
    private:
    public:
        NoPiece();
        NoPiece(string name, string color, int x, int y, Table *table);
        void setRange();  
};

#endif