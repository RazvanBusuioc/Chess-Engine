using namespace std;
#ifndef KING_H_
#define KING_H_
#include "CommonHeaders.h"
#include "Piece.h"
class Table;

class King : public Piece{
    private:
        CartPoint *check_source;
    public:
        King();
        King(string name, string color, string currentPosition, Table *table);
        void setRange();
        bool is_on_check();
        bool is_on_check_mate();
        bool is_on_stale_mate();
        bool is_defended();
        CartPoint *get_check_source();
};
#endif