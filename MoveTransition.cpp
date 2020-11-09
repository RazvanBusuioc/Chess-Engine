#include "MoveTransition.h"
MoveTransition::MoveTransition(){}
MoveTransition::MoveTransition(Piece* source_piece, Piece* destination_piece,
                            CartPoint* src_point, CartPoint* dest_point){
    
    this->source_piece = source_piece;
    this->destination_piece = destination_piece;
    this->source_point = src_point;
    this->destination_point = dest_point;
}

Piece* MoveTransition::get_source_piece(){
    return this->source_piece;
}
Piece* MoveTransition::get_destination_piece(){
    return this->destination_piece;
}
CartPoint* MoveTransition::get_destination_point(){
    return this->destination_point;
}
CartPoint* MoveTransition::get_source_point(){
    return this->source_point;
}
void MoveTransition::print(){
    cout << "from " << this->source_point->getY() << "-" << this->source_point->getX() << " to " <<
    this->destination_point->getY() << "-" << this->destination_point->getX() << endl;
}