#include "Player.h"

Player::Player(){}
Player::Player(string color, Table *table){
    this->color = color;
    this->table = table;
}
string Player::get_color(){
    return this->color;
}
int Player::get_number_of_pieces(){
    int nr = 0;
    for(int i = 0; i < pieces.size(); i++){
        if(pieces[i]->getAliveStatus() == 1)
        nr++;
    }
    return nr;
}
void Player::add_piece(Piece *piece){
    this->pieces.push_back(piece);
}
bool Player::is_on_check(){
    for(int i = 0; i < pieces.size(); i++){
        if(pieces[i]->getName().find("king") != string::npos){
            return ((King *)pieces[i])->is_on_check();
        }
    }
    cout<<"Daca se ajunge aici e nasol... nu mai avem rege xD\n";
    return false;
}

bool Player::is_on_check_mate(){
    for(int i = 0; i < pieces.size(); i++){
        if(pieces[i]->getName().find("king") != string::npos){
            return ((King *)pieces[i])->is_on_check_mate();
        }
    }
    return false;
    cout<<"Daca se ajunge aici e nasol... nu mai avem rege xD\n";
}

bool Player::is_on_stale_mate(){
    for(int i = 0; i < pieces.size(); i++){
        if(pieces[i]->getName().find("king") != string::npos){
            return ((King *)pieces[i])->is_on_stale_mate();
        }
    }
    return false;
    cout<<"Daca se ajunge aici e nasol... nu mai avem rege xD\n";
}


vector<pair<CartPoint*, CartPoint*>> Player::get_moves(){
    moves.clear();
    for(int i = 0; i < pieces.size(); i++){
        vector<CartPoint*> range = pieces[i]->get_range();
        for(int j = 0 ; j < range.size(); j++){
            moves.push_back(make_pair(pieces[i]->get_CartPoint(),range[j]));
        }
    }
    return moves;
}

vector<Piece *> Player::get_pieces(){
    return this->pieces;
}