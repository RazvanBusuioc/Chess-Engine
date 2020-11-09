#include "BoardEvaluator.h"
#include "Player.h"
#include "BlackPlayer.h"
#include "WhitePlayer.h"


BoardEvaluator::BoardEvaluator(){
}
int BoardEvaluator::evaluate(Table *table){
    return score(table->get_engine_player(), table) - 
           score(table->get_opponent_player(), table);
}

int BoardEvaluator::score(Player *player, Table *table){
    int score = 0;
    vector<Piece *> pieces = player->get_pieces();
    for(int i = 0; i < pieces.size(); i++ ){
        if(!pieces[i]->getAliveStatus()){
            continue;
        }
        score += piece_score(pieces[i]);
    }
    if(player->is_on_check_mate()){
        score -= 20000;
    }
    return score;
}

int BoardEvaluator::piece_score(Piece *piece){
    if(piece->getName().find("pawn") != string::npos){
        return PAWN_BONUS;
    }else if (piece->getName().find("rook") != string::npos){
        return ROOK_BONUS;
    }else if (piece->getName().find("knight") != string::npos){
        return KNIGHT_BONUS;
    }else if (piece->getName().find("bishop") != string::npos){
        return BISHOP_BONUS;
    }else if (piece->getName().find("queen") != string::npos){
        return QUEEN_BONUS;
    }else if (piece->getName().find("king") != string::npos){
        return KING_BONUS;
    }
}