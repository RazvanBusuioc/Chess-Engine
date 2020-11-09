#include "Game.h"
//#include "BoardEvaluator.h"
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>


Game:: Game(){
    board_evaluator = new BoardEvaluator();
    xboard = new XboardInterface();
    debug_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    xboard->setDebugFd(debug_fd);
    new_game();
    xboard->setTable(table);
    init_game();
}
void Game::startGame(){
    while(1){
        force = xboard->getForce();
        resign = xboard->getResignStatus();

        string oppMove = get_move();
        if (oppMove.find("other") != string::npos) {
            continue;
        } else if (oppMove.find("new") != string::npos) {
            new_game();
            continue;
        } else if (oppMove.find("quit") != string::npos) {
            break;
        }

        if(oppMove.find("go") == string::npos) {
            table->opponentMove(oppMove,force);
        } 

        if(!force){
        	/*table->displayTable();
        	fflush(stdout);*/
            string myMove = table->my_move_minimax(this->board_evaluator, MINMAX_DEPTH);
            /*table->displayTable();
        	fflush(stdout);*/
            if (myMove.find("noMove") != string::npos ||
                myMove.find("resign") != string::npos){
                xboard->setResign(true);
            }
            if (resign) {
                xboard->write_to_xboard("resign\n");
                xboard->listen_to_xboard("new");
                new_game();
                continue;
            }

            make_move(myMove);

            //write move to debug file
            /*char buff[10];
            strcpy(buff, myMove.c_str());
            write(debug_fd,buff, strlen(buff));
            buff[0] = '\n';
            write(debug_fd, buff, 1);*/
        }
    }
}
void Game::displayCurrentState(){
    table->displayTable();
}

int Game::new_game() {
    table = new Table();
    table->setFields();
    table->asignPieces();

    this->black_player = new BlackPlayer(this->table);
    this->white_player = new WhitePlayer(this->table);
    this->engine_player = white_player;
    this->opponent_player = black_player;

    table->set_players(this->black_player, this->white_player,
                       this->opponent_player, this->engine_player);

    black_player->asign_pieces();
    white_player->asign_pieces();
    
    xboard->setForce(false);
    xboard->setResign(false);
    return 1;
}

/* get one move and return it as a string
  returned: sbuffer.c_str() to transform to char[] */
string Game::get_move() {
    return xboard->get_move(table);
}

int Game::make_move(string myMove) {
    return xboard->make_move(myMove);
}

/* initialize the game and setting features */
int Game::init_game() {
    return xboard->init_game();
}