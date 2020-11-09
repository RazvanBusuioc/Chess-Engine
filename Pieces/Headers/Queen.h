using namespace std;
#ifndef QUEEN_H_
#define QUEEN_H_
#include "CommonHeaders.h"
#include "Piece.h"
class Table;

class Queen : public Piece{
    private:

    public:
        Queen();
        Queen(string name, string color, string currentPosition, Table *table);
        void setRange();
};

#endif