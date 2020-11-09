#include "WhitePlayer.h"

WhitePlayer::WhitePlayer( Table *table)
    :Player("white", table){}
WhitePlayer::WhitePlayer(){}
void WhitePlayer::asign_pieces(){
    pieces.push_back(table->getPiece(6,4));
    pieces.push_back(table->getPiece(6,5));
    pieces.push_back(table->getPiece(6,3));
    pieces.push_back(table->getPiece(6,2));
    pieces.push_back(table->getPiece(6,6));
    pieces.push_back(table->getPiece(6,1));
    pieces.push_back(table->getPiece(6,0));
    pieces.push_back(table->getPiece(6,7));

    pieces.push_back(table->getPiece(7,1));
    pieces.push_back(table->getPiece(7,6));
    pieces.push_back(table->getPiece(7,2));
    pieces.push_back(table->getPiece(7,5));
    pieces.push_back(table->getPiece(7,3));
    pieces.push_back(table->getPiece(7,7));
    pieces.push_back(table->getPiece(7,0));
    pieces.push_back(table->getPiece(7,4));
    
}