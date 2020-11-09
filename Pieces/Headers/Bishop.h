using namespace std;
#ifndef BISHOP_H_
#define BISHOP_H_
#include "CommonHeaders.h"
#include "Piece.h"
class Table;

class Bishop : public Piece{
    private:

    public:
        Bishop();
        Bishop(string name, string color, string currentPosition, Table *table);
        void setRange();
};

#endif