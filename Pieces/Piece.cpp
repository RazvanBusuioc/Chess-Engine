#include "Headers/Piece.h"
#include "../Table.h"
#include <string>

Piece::Piece(){
    this->alive = 0;
}
Piece::Piece(string name, string color, string currentPosition, Table *table){
    this->name = name;
    this->color = color;
    this->currentPosition = currentPosition;
    this->table = table;
    this->alive = 1;
    convertStr();//converts the string currentPosition into CartezianPoint
}
Piece::Piece(string name, string color, int x, int y, int alive, Table *table){
    this->name = name;
    this->color = color;
    this->cartPosition.setX(x);
    this->cartPosition.setY(y);
    this->table = table;
    this->alive = alive;
    convertNr();//converts the CartezianPoint into currentPosition string
}
void Piece::printRange(){
    //used for debugging
    cout << "range for : "<< name <<"("<<cartPosition.getChessX() << cartPosition.getChessY()<<")" << ": "<<endl;
    for (int i = 0; i < range.size(); i++){
        int x = range[i]->getX();
        int y = range[i]->getY();
        cout << range[i]->getChessX()<< 
        range[i]->getChessY()<< " or(matrix): " << y << " " << x << endl;
    }
}
void Piece::print_defense_range(){
    //used for debugging
    /*cout << "defense range for : "<< name <<"("<<cartPosition.getChessX() << cartPosition.getChessY()<<")" << ": "<<endl;
    for (int i = 0; i < range.size(); i++){
        int x = defense_range[i]->getX();
        int y = defense_range[i]->getY();
        cout << defense_range[i]->getChessX()<< 
        defense_range[i]->getChessY()<< " or(matrix): " << y << " " << x << endl;
    }*/
}
void Piece::set_alive_status(bool status){
    this->alive = status;
}
void Piece::setColor(string color){
    this->color = color;
}
void Piece::setRange(){    
}
void Piece::setCartPosition(int y, int x){
    this->cartPosition.setX(x);
    this->cartPosition.setY(y);
    convertNr();
}
void Piece::clearRange(){
    this->range.clear();
}
void Piece::convertStr(){
    //converts the string currentPosition into CartezianPoint
    int x = currentPosition.at(0) - 'a';
    int y = 7 - (currentPosition.at(1) - '1');
    this->cartPosition.setX(x);
    this->cartPosition.setY(y);
}
void Piece::convertNr(){
    //converts the CartezianPoint into currentPosition string
    currentPosition.clear();
    char str1 = 'a' + this->cartPosition.getX() ;
    char str2 = 7 - this->cartPosition.getY() + '1';
    string s;
    s += str1;
    s += str2;
    this->currentPosition = s;
}
void Piece::setCurrentPosition(string newPosition){
    currentPosition = newPosition;
}
int Piece::getX(){
    return this->cartPosition.getX();
}
int Piece::getY(){
    return this->cartPosition.getY();
}
string Piece::getName(){
    return this->name;
}
string Piece::getColor(){
    return this->color;
}
string Piece::getCurrentPosition(){
    return this->currentPosition;
}
string Piece::getMove(){
    //returns the first move in the range vector(as a string) for this piece
    char c1 = this->range[range.size() - 1]->getChessX();
    char c2 = this->range[range.size() - 1]->getChessY();
    string s ;
    s += c1;
    s += c2;
    return s;
}
bool Piece::hasRange(){
    //verify if the piece can move
    if(this->range.size() == 0) return false;
    return true;
}
bool Piece::getAliveStatus(){
    return this->alive;
}
bool Piece::has_king_in_range(){
    for(int i = 0 ; i < range.size(); i++){
        string piece_name = (table->getPiece(range[i]->getY(), range[i]->getX()))->getName();
        if(piece_name.find("king") != string::npos){
            return true;
        }
    }
    return false;
}
bool Piece:: has_in_range(int y, int x){
    for(int i = 0; i < range.size(); i++){
        if(range[i]->getX() == x && range[i]->getY() == y){
            return true;
        }
    }
    return false;
}
int Piece::getXMove(){
    //returns the first possible move(on X axis) for this piece
    srand(10);
    int nr = rand() % range.size();
    cout << nr;
    return this->range[nr]->getX();
}   
int Piece::getYMove(){
    //returns the first possible move(on Y axis) for this piece
    srand(10);  
    int nr = rand() % range.size();
    cout << nr;
    return this->range[nr]->getY();
}
vector<CartPoint*> Piece::get_range(){
    return this->range;
}
vector<CartPoint*> Piece::get_defense_range(){
    return this->defense_range;
}
CartPoint* Piece::get_CartPoint(){
    return &this->cartPosition;
}

bool Piece::is_defended(){
     vector<Piece*> allied_pieces;
     vector<CartPoint*> defense_range;
    if(this->color.find("black") != string::npos){
        allied_pieces = table->get_black_player()->get_pieces();
    }else{
        allied_pieces = table->get_white_player()->get_pieces();
    }
    for(int i = 0; i < allied_pieces.size(); i++){
        defense_range = allied_pieces[i]->get_defense_range();
        for(int j = 0; j < defense_range.size(); j++){
            if(defense_range[j]->getY() == cartPosition.getY() &&
                defense_range[j]->getX() == cartPosition.getX()){
                    return true;
                }
        }
    }
    return false;
}
