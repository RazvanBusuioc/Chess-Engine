#include "Headers/Knight.h"
#include "../Table.h"

Knight::Knight(){}
Knight::Knight(string name, string color, string currentPosition, Table *table)
        :Piece(name, color, currentPosition, table){}
void Knight::setRange(){
    clearRange();
    defense_range.clear();
    int knight_y = cartPosition.getY();
    int knight_x = cartPosition.getX();
    int possilbe_x1;
    int possilbe_x2;
    for(int y = knight_y - 2; y <= knight_y + 2; y++){
        if(y == knight_y) continue;
        if(abs(knight_y - y) == 2){
            possilbe_x1 = knight_x - 1;
            possilbe_x2 = knight_x + 1;
        }else if (abs(knight_y - y) == 1){
            possilbe_x1 = knight_x - 2;
            possilbe_x2 = knight_x + 2;
        }
        if(table->isEmpty(y, possilbe_x1) > 0 || 
        (table->isEmpty(y, possilbe_x1) == 0 &&
        table->getPiece(y,possilbe_x1)->getColor().find(this->color) == string::npos)){
           range.push_back(new CartPoint(possilbe_x1,y));
        }
        if(table->isEmpty(y, possilbe_x2) > 0 || 
        (table->isEmpty(y, possilbe_x2) == 0 &&
        table->getPiece(y,possilbe_x2)->getColor().find(this->color) == string::npos)){
           range.push_back(new CartPoint(possilbe_x2,y));
        }

        if(table->isEmpty(y, possilbe_x1) == 0 && 
        table->getPiece(y,possilbe_x1)->getColor().find(this->color) != string::npos){
            defense_range.push_back(new CartPoint(possilbe_x1, y));
        }
         if(table->isEmpty(y, possilbe_x2) == 0 && 
        table->getPiece(y,possilbe_x2)->getColor().find(this->color) != string::npos){
            defense_range.push_back(new CartPoint(possilbe_x2, y));
        }
    }
}