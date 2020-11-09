#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <bits/stdc++.h>
#include <vector>
#include "Table.h"
#define BUFFER_LENGTH 100
#define IN_FD 0
#define OUT_FD 1
#define USERMOVE_LENGTH 14

using namespace std;

class XboardInterface{
    public:
        int write_to_xboard(string command_to_write);
        int write_to_debug_file(string command_to_write);
        int listen_to_xboard(string command_to_wait_for);
        int get_one_time(string time_type);
        int wait_to_start();
        int get_times();
        int init_game();
        string get_move(Table *table);
        int make_move(string myMove);
        void setForce(bool force);
        void setResign(bool resign);
        bool getForce();
        bool getResignStatus();
        void setDebugFd(int fd);
        void setTable(Table * table);
    private:
        bool force;
        bool resign;
        int debug_fd;
		int engine_time;
		int opponent_time;
        Table * table;
};