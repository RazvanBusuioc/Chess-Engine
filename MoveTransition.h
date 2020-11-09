using namespace std;
#ifndef MOVETRANSITION_H_
#define MOVETRANSITION_H_
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>  
#include "Pieces/Headers/Piece.h"
#include "CartPoint.h"

class MoveTransition{
    private:  
        Piece *destination_piece;
        Piece *source_piece;
        CartPoint* destination_point;
        CartPoint* source_point;
    public:
        MoveTransition();
        MoveTransition(Piece* source_piece, Piece* destination_piece,
                        CartPoint* src_point, CartPoint* dest_point);
        Piece *get_source_piece();
        Piece *get_destination_piece();
        CartPoint* get_destination_point();
        CartPoint* get_source_point();
        void print(); 

};      

#endif