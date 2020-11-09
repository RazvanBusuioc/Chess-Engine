#include "Headers/King.h"
#include "../Table.h"

King::King(){
    
}
King::King(string name, string color, string currentPosition, Table *table)
    :Piece(name, color, currentPosition, table){
        check_source = new CartPoint(-1, -1);
    }

void King::setRange(){
    clearRange();
    defense_range.clear();
    int king_y = cartPosition.getY();
    int king_x = cartPosition.getX();
    /*first move*/

    for(int y = king_y - 1; y <= king_y + 1; y++){
        for(int x = king_x - 1; x <= king_x + 1; x++){
             if (table->isEmpty(y, x) > 0 ||
            (table->isEmpty(y, x) == 0 && 
            table->getPiece(y, x)->getColor().find(this->color) == string::npos)) {

                if(this->color.find("black") != string::npos){
                    if(table->is_tile_threatened_by_white(y, x) == false){
                        range.push_back(new CartPoint(x, y));
                    }
                }else{
                    if(!table->is_tile_threatened_by_black(y, x)){
                        range.push_back(new CartPoint(x, y));
                    }
                } 
            }
            if((table->isEmpty(y, x) == 0 && table->getPiece(y, x)->getColor().find(this->color) != string::npos)){
                defense_range.push_back(new CartPoint(x,y));
            }

        }
    }
}

bool King::is_on_check(){
    vector<Piece *> opponent_pieces;
    if(this->color.find("black") != string::npos){
        opponent_pieces = table->get_white_alive_pieces();
    }else{
        opponent_pieces = table->get_black_alive_pieces();
    }
    for(int i = 0 ; i < opponent_pieces.size(); i++){
        if((opponent_pieces[i])->has_king_in_range() == true){
            check_source->setX(opponent_pieces[i]->get_CartPoint()->getX());
            check_source->setY(opponent_pieces[i]->get_CartPoint()->getY());
            return true;
        }
    }
    return false;
}
bool King::is_on_check_mate(){
    if(is_on_check() == false){
        return false;
    }
    /*if(range.size() != 0){
        return false;
    }*/
    vector<pair<CartPoint*, CartPoint*>> allied_pieces_moves;
    if(this->color.find("black") != string::npos){
        allied_pieces_moves = table->get_black_player()->get_moves();
    }else{
        allied_pieces_moves = table->get_white_player()->get_moves();
    }
    for(int i = 0; i < allied_pieces_moves.size(); i++){
        table->swap2Pieces(allied_pieces_moves[i].first->getY(),
                           allied_pieces_moves[i].first->getX(),
                           allied_pieces_moves[i].second->getY(),
                           allied_pieces_moves[i].second->getX(), true);
        if(is_on_check() == false){
            table->undo_move();
            return false;
        }else{
            table->undo_move();
        }
    }
    return true;
}
bool King::is_on_stale_mate(){
    if(is_on_check() == true){
        return false;
    }
    vector<pair<CartPoint* , CartPoint*>> my_moves;
    if(this->color.find("black") != string::npos){
        my_moves = table->get_black_player()->get_moves();
    }else{
        my_moves = table->get_white_player()->get_moves();
    }
    if(my_moves.size() == 0){
        return true;
    }
    return false;
}



CartPoint * King::get_check_source(){
    return this->check_source;
}