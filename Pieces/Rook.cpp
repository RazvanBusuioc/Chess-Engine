#include "Headers/Rook.h"
#include "../Table.h"

Rook::Rook(){}
Rook::Rook(string name, string color, string currentPosition, Table *table)
        :Piece(name, color, currentPosition, table){}
void Rook::setRange(){
    defense_range.clear();
    int rook_x = cartPosition.getX();
    int rook_y = cartPosition.getY();

    /*going right*/
    for(int x = rook_x + 1; x < 8; x++){
        if(table->isEmpty(rook_y, x) > 0){
            range.push_back(new CartPoint(x, rook_y));
        }
        else if(table->isEmpty(rook_y, x) == 0 && table->getPiece(rook_y, x)->getColor().find(this->color) == string::npos){
            range.insert(range.begin(), new CartPoint(x, rook_y));
            break;
        }else{
            defense_range.push_back(new CartPoint(x, rook_y));
            break;
        }
    }
    /*going left*/
    for(int x = rook_x - 1; x >= 0; x--){
        if(table->isEmpty(rook_y, x) > 0){
            range.push_back(new CartPoint(x, rook_y));
        }
        else if(table->isEmpty(rook_y, x) == 0 && table->getPiece(rook_y, x)->getColor().find(this->color) == string::npos){
            range.insert(range.begin(), new CartPoint(x, rook_y));
            break;
        }else{
            defense_range.push_back(new CartPoint(x, rook_y));
            break;
        }
    }
    /*going down*/
    for(int y = rook_y + 1; y < 8; y++){
        if(table->isEmpty(y, rook_x) > 0){
            range.push_back(new CartPoint(rook_x, y));
        }
        else if(table->isEmpty(y, rook_x) == 0 && table->getPiece(y, rook_x)->getColor().find(this->color) == string::npos){
            range.insert(range.begin(), new CartPoint(rook_x, y));
            break;
        }else{
            defense_range.push_back(new CartPoint(rook_x, y));
            break;
        }
    }
    /*going up*/
    for(int y = rook_y - 1; y >= 0; y--){
        if(table->isEmpty(y, rook_x) > 0){
            range.push_back(new CartPoint(rook_x, y));
        }
        else if(table->isEmpty(y, rook_x) == 0 && table->getPiece(y, rook_x)->getColor().find(this->color) == string::npos){
            range.insert(range.begin(), new CartPoint(rook_x, y));
            break;
        }else{
            defense_range.push_back(new CartPoint(rook_x, y));
            break;
        }
    }
}