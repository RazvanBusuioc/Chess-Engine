using namespace std;
#ifndef PIECE_H_
#define PIECE_H_
#include "CommonHeaders.h"
class Table;

class Piece{
    protected:
        string color;
        string currentPosition;
        string name;
        bool alive;
        Table *table;
        CartPoint cartPosition;
        vector<CartPoint*> range;
        vector<CartPoint*> defense_range;
    public:
        
        Piece();
        Piece(string name, string color, string currentPosition, Table *table);
        Piece(string name, string color, int x, int y, int alive, Table *table);
        void printRange();
        void print_defense_range();
        void setColor(string color);
        void setCurrentPosition(string newPosition);
        void convertStr();
        void convertNr();
        void setCartPosition(int x, int y);
        void clearRange();
        void set_alive_status(bool status);
        virtual void setRange();
        bool getAliveStatus();
        bool hasRange();
        bool has_king_in_range();
        bool has_in_range(int y, int x);
        bool is_defended();
        int getX();
        int getY();
        int getXMove();
        int getYMove();
        string getName();
        string getColor();
        string getCurrentPosition();
        string getMove();
        vector<CartPoint*> get_range();
        vector<CartPoint*> get_defense_range();
        CartPoint * get_CartPoint();
};

#endif /*PIECE_H_*/