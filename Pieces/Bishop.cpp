#include "Headers/Bishop.h"
#include "../Table.h"

Bishop::Bishop(){}
Bishop::Bishop(string name, string color, string currentPosition, Table *table)
        :Piece(name, color, currentPosition, table){}
        
void Bishop::setRange(){
    clearRange();
    defense_range.clear();
    int bishop_y = cartPosition.getY();
    int bishop_x = cartPosition.getX();
    int y;
    /*down right corner*/
    for(int x = bishop_x + 1, y = bishop_y + 1; x < 8, y < 8; x++, y++){
        if(table->isEmpty(y, x) > 0){
            /*That tile is empty*/
            range.push_back(new CartPoint(x, y));
        }
        else if(table->isEmpty(y, x) == 0 && table->getPiece(y, x)->getColor().find(this->color) == string::npos){
            /*That tile is occupied by an opponent*/
            range.insert(range.begin(),new CartPoint(x, y));
            break;
        }else{
            /*Tile is ocupied by one of the allies`s pieces*/
            defense_range.push_back(new CartPoint(x, y));
            break;
        }
    }
    /*up right corner*/
    for(int x = bishop_x + 1, y = bishop_y - 1; x < 8, y >= 0; x++, y--){
        if(table->isEmpty(y, x) > 0){
            /*That tile is empty*/
            range.push_back(new CartPoint(x, y));
        }
        else if(table->isEmpty(y, x) == 0 && table->getPiece(y, x)->getColor().find(this->color) == string::npos){
            /*That tile is occupied by an opponent*/
            range.insert(range.begin(),new CartPoint(x, y));
            break;
        }else{
            /*Tile is ocupied by one of the allies`s pieces*/
            defense_range.push_back(new CartPoint(x, y));
            break;
        }
    }
    /*up left corner*/
    for(int x = bishop_x - 1, y = bishop_y - 1; x >= 0, y >= 0; x--, y--){
        if(table->isEmpty(y, x) > 0){
            /*That tile is empty*/
            range.push_back(new CartPoint(x, y));
        }
        else if(table->isEmpty(y, x) == 0 && table->getPiece(y, x)->getColor().find(this->color) == string::npos){
            /*That tile is occupied by an opponent*/
            range.insert(range.begin(),new CartPoint(x, y));
            break;
        }else{
            /*Tile is ocupied by one of the allies`s pieces*/
            defense_range.push_back(new CartPoint(x, y));
            break;
        }
    }
    /*down left corner*/
    for(int x = bishop_x - 1, y = bishop_y + 1; x >= 0, y < 8; x--, y++){
        if(table->isEmpty(y, x) > 0){
            /*That tile is empty*/
            range.push_back(new CartPoint(x, y));
        }
        else if(table->isEmpty(y, x) == 0 && table->getPiece(y, x)->getColor().find(this->color) == string::npos){
            /*That tile is occupied by an opponent*/
            range.insert(range.begin(),new CartPoint(x, y));
            break;
        }else{
            /*Tile is ocupied by one of the allies`s pieces*/
            defense_range.push_back(new CartPoint(x, y));
            break;
        }
    }
}