#include "Table.h"
#include <string.h>

Table::Table(){}
Table::Table(Player *black_player, Player *white_player,
            Player *engine_player, Player *opponent_player){
    this->white_player = white_player;
    this->black_player = black_player;
    this->opponent_player = opponent_player;
    this->engine_player = engine_player;
}
void Table::set_players(Player *black_player, Player *white_player,
                    Player *engine_player, Player *opponent_player){
    this->black_player = black_player;
    this->white_player = white_player;
    this->opponent_player = opponent_player;
    this->engine_player = engine_player;
}
void Table::set_engine_on_black(){
    this->engine_player = black_player;
    this->opponent_player = white_player;
}
void Table::set_engine_on_white(){
    this->engine_player = white_player;
    this->opponent_player = black_player;
}
Player *Table::get_engine_player(){
    return this->engine_player;
}
Player *Table::get_opponent_player(){
    return this->opponent_player;
}
void Table::setFields(){
    //Piece initialization
    rookWhite1 = new Rook("rookWhite","white","a1", this);
    rookWhite2 = new Rook("rookWhite","white","h1", this);
    knightWhite1 = new Knight("knightWhite","white","b1", this);
    knightWhite2 = new Knight("knightWhite","white","g1", this);
    bishopWhite1 = new Bishop("bishopWhite","white","c1", this);
    bishopWhite2 = new Bishop("bishopWhite","white","f1", this);
    queenWhite = new Queen("queenWhite","white","d1", this);
    kingWhite = new King("kingWhite","white","e1", this);
    pWhite1 = new Pawn("pawnWhite","white","a2", this);
    pWhite2 = new Pawn("pawnWhite","white","b2", this);
    pWhite3 = new Pawn("pawnWhite","white","c2", this);
    pWhite4 = new Pawn("pawnWhite","white","d2", this);
    pWhite5 = new Pawn("pawnWhite","white","e2", this);
    pWhite6 = new Pawn("pawnWhite","white","f2", this);
    pWhite7 = new Pawn("pawnWhite","white","g2", this);
    pWhite8 = new Pawn("pawnWhite","white","h2", this);
    rookBlack1 = new Rook("rookBlack","black","a8", this);
    rookBlack2 = new Rook("rookBlack","black","h8", this);
    knightBlack1 = new Knight("knightBlack","black","b8", this);
    knightBlack2 = new Knight("knightBlack","black","g8", this);
    bishopBlack1 = new Bishop("bishopBlack","black","c8", this);
    bishopBlack2 = new Bishop("bishopBlack","black","f8", this);
    queenBlack = new Queen("queenBlack","black","d8", this);
    kingBlack = new King("kingBlack","black","e8", this);
    pBlack1 = new Pawn("pawnBlack","black","a7", this);
    pBlack2 = new Pawn("pawnBlack","black","b7", this);
    pBlack3 = new Pawn("pawnBlack","black","c7", this);
    pBlack4 = new Pawn("pawnBlack","black","d7", this);
    pBlack5 = new Pawn("pawnBlack","black","e7", this);
    pBlack6 = new Pawn("pawnBlack","black","f7", this);
    pBlack7 = new Pawn("pawnBlack","black","g7", this);
    pBlack8 = new Pawn("pawnBlack","black","h7", this);
}
void Table::asignPieces(){
    for(int i = 0;i < 8; i++){
        for(int j = 0; j < 8; j++){
            table[i][j] = (new NoPiece("noPiece", "", j,i, this));
        }
    }
    //Pieces are put on the table
    //Team Black baby <3
    table[0][0] = rookBlack1;
    table[0][1] = knightBlack1;
    table[0][2] = bishopBlack1;
    table[0][3] = queenBlack;
    table[0][4] = kingBlack;
    table[0][5] = bishopBlack2;
    table[0][6] = knightBlack2;
    table[0][7] = rookBlack2;
    table[1][0] = pBlack1;
    table[1][1] = pBlack2;
    table[1][2] = pBlack3;
    table[1][3] = pBlack4;
    table[1][4] = pBlack5;
    table[1][5] = pBlack6;
    table[1][6] = pBlack7;
    table[1][7] = pBlack8;
    //Team white
    table[7][0] = rookWhite1;
    table[7][1] = knightWhite1;
    table[7][2] = bishopWhite1;
    table[7][3] = queenWhite;
    table[7][4] = kingWhite;
    table[7][5] = bishopWhite2;
    table[7][6] = knightWhite2;
    table[7][7] = rookWhite2;
    table[6][0] = pWhite1;
    table[6][1] = pWhite2;
    table[6][2] = pWhite3;
    table[6][3] = pWhite4;
    table[6][4] = pWhite5;
    table[6][5] = pWhite6;
    table[6][6] = pWhite7;
    table[6][7] = pWhite8;  
    //Setting the range for all the pieces
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            table[i][j]->setRange();
        }
    }
    for(int y = 0; y < 2; y++){
        for(int x = 0; x < 8; x++){
            black_alive_pieces.push_back(table[y][x]);
            alive_pieces.push_back(table[y][x]);
        }
    }
    for(int y = 6; y < 8; y++){
        for(int x = 0; x < 8; x++){
            white_alive_pieces.push_back(table[y][x]);
            alive_pieces.push_back(table[y][x]);
        }
    }
}
void Table::displayTable(){
    // used for debugging
    int i,j;
    cout << endl;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            cout << (table[i][j])->getAliveStatus() << " ";
        }
        cout << endl;
    }
    cout << endl;
    /*for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            table[i][j]->printRange();
        }
        cout << endl;
    }*/
}
int Table::isEmpty(int x, int y){
    //verify if there is a piece at pos(x, y)
    if( x < 0 || x > 7 || y < 0 || y > 7)
        return -1;
    int bolean = (int)(table[x][y])->getAliveStatus();
    if(bolean == 1) return 0;
    else return 1;
}
string Table::getPieceColor(int x, int y){
    return table[x][y]->getColor();
}
void Table::opponentMove(string oppMove, bool force){
    int initialX = oppMove.at(0) - 'a';
    int initialY = '8' - oppMove.at(1);
    int finalX = oppMove.at(2) - 'a';
    int finalY = '8' - oppMove.at(3);
    
    swap2Pieces(initialY, initialX, finalY, finalX, force);
}
void Table::swap2Pieces(int y1, int x1, int y2, int x2, bool force){
    clearRangeForAllPieces();
    /*Add move to the moves history*/
    move_history.push_back(new MoveTransition(table[y1][x1], table[y2][x2],
                            new CartPoint(x1, y1), new CartPoint(x2, y2)));
    /*verify En Passante vulnerability for a pawn*/
    if(getPieceName(y1,x1).find("Pawn") == string::npos && ( (y1 == 6 && y2 == 4)  || (y1 == 1 && y2 == 3))){
        ((Pawn*)table[y1][x1])->setEnPassant(true);
    }
    //interchanging the cartesian position and the pieces on the table
    table[y2][x2]->setCartPosition(y1, x1);    
    table[y1][x1]->setCartPosition(y2, x2);
    swap(table[y1][x1], table[y2][x2]);
    verifySpecialCases(y1, x1, y2, x2);
    setRangeForAllPieces();
    //displayTable();
}
void Table::undo_move(){
    MoveTransition *aux_move = move_history[move_history.size() - 1];
    int x1 = aux_move->get_source_point()->getX();
    int y1 = aux_move->get_source_point()->getY();
    int x2 = aux_move->get_destination_point()->getX();
    int y2 = aux_move->get_destination_point()->getY();

    table[y1][x1] = aux_move->get_source_piece();
    table[y1][x1]->setCartPosition(y1, x1);
    if(table[y1][x1]->getName().find("noPiece") == string::npos){
        table[y1][x1]->set_alive_status(true);
    }

    table[y2][x2] = aux_move->get_destination_piece();
    table[y2][x2]->setCartPosition(y2,x2);
    if(table[y2][x2]->getName().find("noPiece") == string::npos){
        table[y2][x2]->set_alive_status(true);
    }

    move_history.pop_back();
    setRangeForAllPieces();

}

string Table::getPieceName(int y, int x){
    return table[y][x]->getName();
}
Piece* Table::getPiece(int y, int x){
    return table[y][x];
}
void Table::verifySpecialCases(int y1, int x1, int y2, int x2){
    if(table[y1][x1]->getAliveStatus()){
        table[y1][x1]->set_alive_status(false);
        table[y1][x1] = new NoPiece("noPiece", "", x1,y1, this);
    }
    else if(((y1 == 3 && y2 == 2) || (y1 == 4 && y2 == 5)) && abs(x1 - x2) == 1 && 
            table[y2][x2]->getName().find("pawn") !=  string::npos){
        //en passante case
        table[y1][x2] = new NoPiece("noPiece", "", x1,y1, this);
    }
    else if((y2 == 7 || y2 == 0) && table[y2][x2]->getName().find("pawn") !=  string::npos){
        if(y2 == 7){
            //pawn promotion for black
            table[y2][x2] = new Queen("queenBlack2","black", "d2", this);
            table[y2][x2]->setCartPosition(y2, x2);
            table[y2][x2]->setRange();
            black_player->add_piece(table[y2][x2]);
            displayTable();
        }
        else if(y2 == 0){
            //pawn promotion for white
            table[y2][x2] = new Queen("queenWhite2","white", "d2", this);
            table[y2][x2]->setCartPosition(y2, x2);
            table[y2][x2]->setRange();
            white_player->add_piece(table[y2][x2]);
            displayTable();
        }
    }
    else if( y1 == 7 && y2 == 7 && x1 == 4 && x2 == 6 &&
    table[y2][x2]->getName().find("kingWhite") !=  string::npos){
        //King side castle for black
        table[y2][x1 + 1]->setCartPosition(y2, x2 + 1);    
        table[y2][x2 + 1]->setCartPosition(y2, x1 + 1);
        swap(table[y2][x1 + 1], table[y2][x2 + 1]);
    }
    else if( y1 == 7 && y2 == 7 && x1 == 4 && x2 == 2 && 
    table[y2][x2]->getName().find("kingWhite") !=  string::npos){
        //Queen side castle for white
        table[y2][x2 - 2]->setCartPosition(y2, x1 - 1);    
        table[y2][x1 - 1]->setCartPosition(y2, x2 - 2);
        swap(table[y2][x2 - 2], table[y2][x1 - 1]);
    }
    else if( y1 == 0 && y2 == 0 && x1 == 4 && x2 == 6 &&
    table[y2][x2]->getName().find("kingBlack") !=  string::npos){
        //King side castle for black
        table[y2][x1 + 1]->setCartPosition(y2, x2 + 1);    
        table[y2][x2 + 1]->setCartPosition(y2, x1 + 1);
        swap(table[y2][x1 + 1], table[y2][x2 + 1]);
    }
    else if( y1 == 0 && y2 == 0 && x1 == 4 && x2 == 2 && 
    table[y2][x2]->getName().find("kingBlack") !=  string::npos){
        //Queen side castle for black
        table[y2][x2 - 2]->setCartPosition(y2, x1 - 1);    
        table[y2][x1 - 1]->setCartPosition(y2, x2 - 2);
        swap(table[y2][x2 - 2], table[y2][x1 - 1]);
    }
}
void Table::clearRangeForAllPieces(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            table[i][j]->clearRange();
            if(getPieceName(i,j).find("pawn") != string::npos){
                ((Pawn*)table[i][j])->setEnPassant(false);
            }

        }
    }
}
void Table::setRangeForAllPieces(){
    clearRangeForAllPieces();
    vector<pair<int, int>> left_over;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(table[i][j]->getName().find("king") != string::npos){
                left_over.push_back(make_pair(i, j));
                continue;
            }
            table[i][j]->setRange();
        }
    }
    for(int i = 0; i < left_over.size(); i++){
        table[left_over[i].first][left_over[i].second]->setRange();
    }
}
bool Table:: is_tile_threatened_by_white(int y, int x){
    //returns true if the given tile is in range of a white piece
    if(table[y][x]->getAliveStatus() == true && 
        table[y][x]->getColor().find("white") != string::npos && 
        table[y][x]->is_defended()){
        return true;
    }
    for(int i = 0 ; i < white_alive_pieces.size(); i++){
        if(white_alive_pieces[i]->getName().find("pawn") != string::npos){
            if(((Pawn *)white_alive_pieces[i])->has_in_attacking_range(y, x)){
                return true;
            }
        }
        else if(white_alive_pieces[i]->has_in_range(y,x) ){
            return true;
        }
    }
    return false;
}
bool Table:: is_tile_threatened_by_black(int y, int x){
    //returns true if the given tile is in range of a black piece
    if(table[y][x]->getAliveStatus() == true && 
        table[y][x]->getColor().find("black") != string::npos && 
        table[y][x]->is_defended()){
        return true;
    }
    for(int i = 0 ; i < black_alive_pieces.size(); i++){
        if(black_alive_pieces[i]->getName().find("pawn") != string::npos){
            if(((Pawn *)black_alive_pieces[i])->has_in_attacking_range(y, x)){
                return true;
            }
        }
        else if(black_alive_pieces[i]->has_in_range(y,x)){
            return true;
        }
    }
    return false;
}

vector <Piece *> Table:: get_alive_pieces(){
    return this->alive_pieces;
}
vector <Piece *> Table:: get_white_alive_pieces(){
    return this->white_alive_pieces;
}
vector <Piece *> Table:: get_black_alive_pieces(){
    return this->black_alive_pieces;
}
Player* Table::get_black_player(){
    return this->black_player;
}
Player* Table::get_white_player(){
    return this->white_player;
}

string Table::make_string_move(int x1, int y1, int x2, int y2){
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    string s1, s2, s3, s4;
    s1 = x1 + 'a';
    s2 = '8' - y1;
    s3 = x2 + 'a';
    s4 = '8' - y2;
    return s1 + s2 + s3 + s4;
}

string Table::my_move_minimax(BoardEvaluator *board_evaluator, int depth){
    
    if(engine_player->is_on_check_mate()){
        return "resign";
    }
    pair<int, int> test = max(board_evaluator, INT16_MIN, INT16_MAX, depth);
    setRangeForAllPieces(); 
    vector<pair<CartPoint* , CartPoint *>> moves = engine_player->get_moves();
    
    int x1 = moves[test.second].first->getX();
    int y1 = moves[test.second].first->getY();
    int x2 = moves[test.second].second->getX();
    int y2 = moves[test.second].second->getY();
    swap2Pieces(y1, x1, y2, x2, true);
    return make_string_move(x1, y1, x2, y2);
}

pair<int, int> Table::min(BoardEvaluator *board_evaluator, int alpha, int betha, int depth){
    if(depth == 0 || engine_player->is_on_check_mate() || engine_player->is_on_stale_mate() ){
        return make_pair(board_evaluator->evaluate(this), 0);
    }
    int minimum = INT16_MAX;
    int idx = -1;
    vector<pair<CartPoint* , CartPoint *>> moves = opponent_player->get_moves();
    for(int i = 0; i < moves.size(); i++){
        int x1, x2, y1, y2;
        x1 = moves[i].first->getX();
        y1 = moves[i].first->getY();
        x2 = moves[i].second->getX();
        y2 = moves[i].second->getY();
        swap2Pieces(y1, x1, y2, x2, true);
        if(opponent_player->is_on_check()){
            undo_move();
            continue;
        }
        int score = (max(board_evaluator, alpha, betha, depth - 1)).first;
        if (score < minimum){
            minimum = score;
            idx = i;
        }
        undo_move();
        betha = std::min(betha, score);
        if(betha <= alpha){
            break;
        }
    }
    return make_pair(minimum, idx);
}

pair<int, int> Table::max(BoardEvaluator *board_evaluator, int alpha, int betha, int depth){
    if(depth == 0 || engine_player->is_on_check_mate() || engine_player->is_on_stale_mate() ){
        return make_pair(board_evaluator->evaluate(this), 0);
    }
    int maximum = INT16_MIN;
    int idx = -1;
    vector<pair<CartPoint* , CartPoint *>> moves = engine_player->get_moves();
    for(int i = 0; i < moves.size(); i++){
        int x1, x2, y1, y2;
        x1 = moves[i].first->getX();
        y1 = moves[i].first->getY();
        x2 = moves[i].second->getX();
        y2 = moves[i].second->getY();
        swap2Pieces(y1, x1, y2, x2, true);
        if(engine_player->is_on_check()){
            undo_move();
            continue;
        }
        int score = min(board_evaluator, alpha, betha, depth - 1).first;
        if (score > maximum){
            maximum = score;
            idx = i;
        }
        undo_move();
        alpha = std::max(alpha, score);
        if(betha <= alpha){
            break;
        }
    }
    return make_pair(maximum, idx);
}