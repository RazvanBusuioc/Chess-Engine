#include "BlackPlayer.h"

BlackPlayer::BlackPlayer(Table *table)
    :Player("black", table){}
BlackPlayer::BlackPlayer(){}
void BlackPlayer::asign_pieces(){
    pieces.push_back(table->getPiece(1,4));
    pieces.push_back(table->getPiece(1,5));
    pieces.push_back(table->getPiece(1,3));
    pieces.push_back(table->getPiece(1,2));
    pieces.push_back(table->getPiece(1,6));
    pieces.push_back(table->getPiece(1,1));
    pieces.push_back(table->getPiece(1,0));
    pieces.push_back(table->getPiece(1,7));

    pieces.push_back(table->getPiece(0,1));
    pieces.push_back(table->getPiece(0,6));
    pieces.push_back(table->getPiece(0,2));
    pieces.push_back(table->getPiece(0,5));
    pieces.push_back(table->getPiece(0,3));
    pieces.push_back(table->getPiece(0,7));
    pieces.push_back(table->getPiece(0,0));
    pieces.push_back(table->getPiece(0,4));

}