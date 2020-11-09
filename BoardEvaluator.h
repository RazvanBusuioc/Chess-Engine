using namespace std;
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
#include "Player.h"
#define PAWN_BONUS 100
#define ROOK_BONUS 500
#define BISHOP_BONUS 350
#define KNIGHT_BONUS 300
#define QUEEN_BONUS 1000
#define KING_BONUS 5000

#ifndef BOARDEVALUATOR_H_
#define BOARDEVALUATOR_H_
class Player;
class BoardEvaluator{
    private:
    public:
        BoardEvaluator();
        int evaluate(Table *table);
        int score(Player *player, Table * table);
        int piece_score(Piece *piece);
};

#endif