using namespace std;
#ifndef TABLE_H_
#define TABLE_H_
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>  
#include "Pieces/Headers/Piece.h"
#include "Pieces/Headers/King.h"
#include "Pieces/Headers/Queen.h"
#include "Pieces/Headers/Bishop.h"
#include "Pieces/Headers/Knight.h"
#include "Pieces/Headers/Rook.h"
#include "Pieces/Headers/Pawn.h"
#include "Pieces/Headers/NoPiece.h"
#include "MoveTransition.h"
#include "CartPoint.h"
#include "BoardEvaluator.h"
#include "Player.h"
class Player;
class Table{
    private:
        vector<Piece *> alive_pieces;
        vector<Piece *> white_alive_pieces;
        vector<Piece *> black_alive_pieces;
        vector<MoveTransition *> move_history;
        Player *white_player;
        Player *black_player;
        Player *engine_player;
        Player *opponent_player;
        Piece *table[8][8];
        King *kingWhite, *kingBlack;
        Queen *queenWhite, *queenBlack;
        Bishop *bishopWhite1, *bishopWhite2, *bishopBlack1, *bishopBlack2;
        Knight *knightWhite1, *knightWhite2, *knightBlack1, *knightBlack2;
        Rook *rookWhite1, *rookWhite2, *rookBlack1, *rookBlack2;
        Pawn *pWhite1, *pWhite2, *pWhite3, *pWhite4, *pWhite5, *pWhite6, *pWhite7, *pWhite8,
            *pBlack1, *pBlack2, *pBlack3, *pBlack4, *pBlack5, *pBlack6, *pBlack7, *pBlack8;
        NoPiece *np;
    public:
        Table();
        Table(Player *black_player, Player *white_player, Player *engine_player, Player *opponent_player);
        void setFields();
        void set_engine_on_black();
        void set_engine_on_white();
        void asignPieces();
        void displayTable();
        void opponentMove(string oppMove, bool force);
        void swap2Pieces(int y1, int x1,  int y2, int x2, bool force);
        void undo_move();
        void verifySpecialCases(int y1, int x1,  int y2, int x2);
        void clearRangeForAllPieces();
        void setRangeForAllPieces();
        void set_players(Player *black_player, Player *white_player, Player *engine_player, Player *opponent_player);
        bool kingOnChess(string myCOlor);
        bool is_tile_threatened_by_white(int y, int x);
        bool is_tile_threatened_by_black(int y, int x);
        int isEmpty(int x, int y);
        pair<int, int> min(BoardEvaluator *board_evaluator, int alpha, int betha, int depth);
        pair<int, int> max(BoardEvaluator *board_evaluator, int alpha, int betha, int depth);
        string make_string_move(int x1, int y1, int x2, int y2);
        string getPieceColor(int x, int y);
        string getPieceName(int x, int y);
        string myMove(string myColor, bool force);
        string my_move_minimax(BoardEvaluator *board_evaluator, int depth);
        Piece* getPiece(int x, int y);
        vector <Piece *> get_alive_pieces();
        vector <Piece *> get_white_alive_pieces();
        vector <Piece *> get_black_alive_pieces();
        Player *get_black_player();
        Player *get_white_player(); 
        Player *get_engine_player();
        Player *get_opponent_player();

};
#endif /* TABLE_H_ */