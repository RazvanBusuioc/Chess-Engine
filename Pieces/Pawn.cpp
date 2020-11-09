#include "Headers/Pawn.h"
#include "../Table.h"

Pawn::Pawn(){}
Pawn::Pawn(string name, string color, string currentPosition, Table *table)
        :Piece(name, color, currentPosition, table){
            enPassantVulnerability = false;
        }
void Pawn::setEnPassant(bool eP){
    this->enPassantVulnerability = eP;
}
bool Pawn::getEnPassant(){
    return this->enPassantVulnerability;
}
void Pawn::setRange(){
   int x1, x2, x3, x4, y1, y2, y3, y4;
    /*Range for a Pawn*/
    if(color.compare("white") == 0){
        //All the 4 possible moves for a white pawn are validated
        CartPoint *possibleMove1 = new CartPoint(cartPosition.getX(), cartPosition.getY() - 1);
        CartPoint *possibleMove2 = new CartPoint(cartPosition.getX(), cartPosition.getY() - 2);
        CartPoint *possibleMove3 = new CartPoint(cartPosition.getX() - 1, cartPosition.getY() - 1);
        CartPoint *possibleMove4 = new CartPoint(cartPosition.getX() + 1, cartPosition.getY() - 1);
        x1 = possibleMove1->getX();
        x2 = possibleMove2->getX();
        x3 = possibleMove3->getX();
        x4 = possibleMove4->getX();
        y1 = possibleMove1->getY();
        y2 = possibleMove2->getY();
        y3 = possibleMove3->getY();
        y4 = possibleMove4->getY();

        //move on left diagonal ++ En Passante case
        if((table->isEmpty(y3, x3) == 0 && table->getPieceColor(y3, x3) != "white") || 
        (table->isEmpty(y3, x3) > 0 && table->isEmpty(y3 + 1, x3) == 0 &&
        table->getPiece(y3 + 1, x3)->getName().find("pawnBlack") != string::npos &&
        ((Pawn*)table->getPiece(y3 + 1, x3))->getEnPassant() )){
            range.push_back(possibleMove3);
        } 
        //move on right diagonal ++ En Passante case
        if((table->isEmpty(y4, x4) == 0 && table->getPieceColor(y4, x4) != "white") || 
        (table->isEmpty(y4, x4) > 0 && table->isEmpty(y4 + 1, x4) == 0 &&
        (table->getPiece(y4 + 1, x4)->getName().find("pawnBlack") != string::npos) &&
        ((Pawn*)table->getPiece(y4 + 1, x4))->getEnPassant() )){
            range.push_back(possibleMove4);
        } 
        //move in front(1 or 2 positions)
        if(table->isEmpty(y1, x1) > 0 ){
            if(cartPosition.getY() == 6 && table->isEmpty(y2, x2)){
                range.push_back(possibleMove2);
            }
            range.push_back(possibleMove1);
        }
        attacking_range.clear();
        attacking_range.push_back(possibleMove3);
        attacking_range.push_back(possibleMove4);

        defense_range.clear();
        if(table->isEmpty(y3, x3) == 0 && table->getPieceColor(y3,x3).find("white") != string::npos){
            defense_range.push_back(possibleMove3);
        }
        if(table->isEmpty(y4, x4) == 0 && table->getPieceColor(y4,x4).find("white") != string::npos){
            defense_range.push_back(possibleMove4);
        }
        
    }
    else{
        //All the 4 possible moves for a black pawn are validated
        CartPoint *possibleMove1 = new CartPoint(cartPosition.getX(), cartPosition.getY() + 1);
        CartPoint *possibleMove2 = new CartPoint(cartPosition.getX(), cartPosition.getY() + 2);
        CartPoint *possibleMove3 = new CartPoint(cartPosition.getX() - 1, cartPosition.getY() + 1);
        CartPoint *possibleMove4 = new CartPoint(cartPosition.getX() + 1, cartPosition.getY() + 1);
        x1 = possibleMove1->getX();
        x2 = possibleMove2->getX();
        x3 = possibleMove3->getX();
        x4 = possibleMove4->getX();
        y1 = possibleMove1->getY();
        y2 = possibleMove2->getY();
        y3 = possibleMove3->getY();
        y4 = possibleMove4->getY();

        //move on left diagonal ++ En Passante case
        if((table->isEmpty(y3, x3) == 0 && table->getPieceColor(y3, x3) != "black") || 
        (table->isEmpty(y3, x3) > 0 && table->isEmpty(y3 - 1, x3) == 0 &&
        table->getPiece(y3 - 1, x3)->getName().find("pawnWhite") != string::npos &&
        ((Pawn*)table->getPiece(y3 - 1, x3))->getEnPassant() )){
            range.push_back(possibleMove3);
        }
        //move on right diagonal ++ En Passante case
        if((table->isEmpty(y4, x4) == 0 && table->getPieceColor(y4, x4) != "black") || 
        (table->isEmpty(y4, x4) > 0 && table->isEmpty(y4 - 1, x4) == 0 &&
        (table->getPiece(y4 - 1, x4)->getName().find("pawnWhite") != string::npos) &&
        ((Pawn*)table->getPiece(y4 - 1, x4))->getEnPassant() )){
            range.push_back(possibleMove4);
        } 
        //move in front(1 or 2 positions)
        if(table->isEmpty(y1, x1) > 0 ){
            if(cartPosition.getY() == 1 && table->isEmpty(y2, x2)){
                range.push_back(possibleMove2);
            }
            range.push_back(possibleMove1);
        }
        attacking_range.clear();
        attacking_range.push_back(possibleMove3);
        attacking_range.push_back(possibleMove4);

        defense_range.clear();
        if(table->isEmpty(y3, x3) == 0 && table->getPieceColor(y3,x3).find("black") != string::npos){
            defense_range.push_back(possibleMove3);
        }
        if(table->isEmpty(y4, x4) == 0 && table->getPieceColor(y4,x4).find("black") != string::npos){
            defense_range.push_back(possibleMove4);
        }
    }
}
void Pawn::printRange(){
    cout<<"Clasa Pion"<<endl;
    for (int i = 0; i < range.size(); i++){
        cout << name << " " << range[i]->getX()<< " " << range[i]->getY()<< endl ;
    }
}
void Pawn::setCartPosition(int x, int y){
}
vector<CartPoint *> Pawn::get_attacking_range(){
    return this->attacking_range;
}
bool Pawn::has_in_attacking_range(int y, int x){
    for(int i = 0; i < attacking_range.size(); i++){
        if(attacking_range[i]->getX() == x &&
           attacking_range[i]->getY() == y){
               return true;
           }
    }
    return false;
}