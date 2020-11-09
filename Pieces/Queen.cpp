#include "Headers/Queen.h"
#include "../Table.h"

Queen::Queen(){}
Queen::Queen(string name, string color, string currentPosition, Table *table)
        :Piece(name, color, currentPosition, table){}
void Queen::setRange(){
    clearRange();
    defense_range.clear();
    int queen_y = cartPosition.getY();
    int queen_x = cartPosition.getX();
    int y;

    /*bishop side*/
    /*goinf down right corner*/
    for(int x = queen_x + 1, y = queen_y + 1; x < 8, y < 8; x++, y++){
        if(table->isEmpty(y, x) > 0){
            /*Tile is empty*/
            range.push_back(new CartPoint(x, y));
        }
        else if(table->isEmpty(y, x) == 0 && table->getPiece(y, x)->getColor().find(this->color) == string::npos){
            /*Tile is occupied by an opponent`s piece*/
            range.insert(range.begin(),new CartPoint(x, y));
            break;
        }else{
            /*Tile is occupied by an allied`s piece*/
            defense_range.push_back(new CartPoint(x, y));
            break;
        }
    }
    /*goinf up right corner*/
    for(int x = queen_x + 1, y = queen_y - 1; x < 8, y >= 0; x++, y--){
        if(table->isEmpty(y, x) > 0){
            range.push_back(new CartPoint(x, y));
        }
        else if(table->isEmpty(y, x) == 0 && table->getPiece(y, x)->getColor().find(this->color) == string::npos){
            range.insert(range.begin(),new CartPoint(x, y));
            break;
        }else{
            defense_range.push_back(new CartPoint(x, y));
            break;
        }
    }
    /*goinf top left corner*/
    for(int x = queen_x - 1, y = queen_y - 1; x >= 0, y >= 0; x--, y--){
        if(table->isEmpty(y, x) > 0){
            range.push_back(new CartPoint(x, y));
        }
        else if(table->isEmpty(y, x) == 0 && table->getPiece(y, x)->getColor().find(this->color) == string::npos){
            range.insert(range.begin(),new CartPoint(x, y));
            break;
        }else{
            defense_range.push_back(new CartPoint(x, y));
            break;
        }
    }
    /*goinf down left corner*/
    for(int x = queen_x - 1, y = queen_y + 1; x >= 0, y < 8; x--, y++){
        if(table->isEmpty(y, x) > 0){
            range.push_back(new CartPoint(x, y));
        }
        else if(table->isEmpty(y, x) == 0 && table->getPiece(y, x)->getColor().find(this->color) == string::npos){
            range.insert(range.begin(),new CartPoint(x, y));
            break;
        }else{
            defense_range.push_back(new CartPoint(x, y));
            break;
        }
    }




    /*rook side*/
    /*going right*/
    for(int x = queen_x + 1; x < 8; x++){
        if(table->isEmpty(queen_y, x) > 0){
            range.push_back(new CartPoint(x, queen_y));
        }
        else if(table->isEmpty(queen_y, x) == 0 && table->getPiece(queen_y, x)->getColor().find(this->color) == string::npos){
            range.insert(range.begin(), new CartPoint(x, queen_y));
            break;
        }else{
            defense_range.push_back(new CartPoint(x, queen_y));
            break;
        }
    }
    /*going left*/
    for(int x = queen_x - 1; x >= 0; x--){
        if(table->isEmpty(queen_y, x) > 0){
            range.push_back(new CartPoint(x, queen_y));
        }
        else if(table->isEmpty(queen_y, x) == 0 && table->getPiece(queen_y, x)->getColor().find(this->color) == string::npos){
            range.insert(range.begin(), new CartPoint(x, queen_y));
            break;
        }else{
            defense_range.push_back(new CartPoint(x, queen_y));
            break;
        }
    }
    /*going down*/
    for(int y = queen_y + 1; y < 8; y++){
        if(table->isEmpty(y, queen_x) > 0){
            range.push_back(new CartPoint(queen_x, y));
        }
        else if(table->isEmpty(y, queen_x) == 0 && table->getPiece(y, queen_x)->getColor().find(this->color) == string::npos){
            range.insert(range.begin(), new CartPoint(queen_x, y));
            break;
        }else{
            defense_range.push_back(new CartPoint(queen_x, y));
            break;
        }
    }
    /*going up*/
    for(int y = queen_y - 1; y >= 0; y--){
        if(table->isEmpty(y, queen_x) > 0){
            range.push_back(new CartPoint(queen_x, y));
        }
        else if(table->isEmpty(y, queen_x) == 0 && table->getPiece(y, queen_x)->getColor().find(this->color) == string::npos){
            range.insert(range.begin(), new CartPoint(queen_x, y));
            break;
        }else{
            defense_range.push_back(new CartPoint(queen_x, y));
            break;
        }
    }
}