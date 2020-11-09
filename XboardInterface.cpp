#include "XboardInterface.h"

/* initialize the game and setting features */
int XboardInterface::init_game() {
    setbuf(stdout, NULL);
    listen_to_xboard("protover");
    write_to_xboard("feature usermove=1 sigint=0 done=1 time=0 san=0\n");
    listen_to_xboard("accepted san");
    dprintf(debug_fd, "Init Finished\n");
    return 1;
}

int XboardInterface::make_move(string myMove) {
    string move = "move " + myMove + "\n";
    write_to_xboard(move);
    return 1;
}

string XboardInterface::get_move(Table *table) {
    // ----------- not working properly get_times for now
    //get_times();
    struct timeval t;
    t.tv_sec = 250;
    t.tv_usec = 0;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    char buffer[BUFFER_LENGTH];
    char error[] = "nu e ok\n";
    char quit[] = "quit command\n";
    int number_of_bytes;
    int bytes_read;
    string sbuffer;
    while (1) {
        memset(buffer, 0, BUFFER_LENGTH);
        fflush(stdin);
        cin.clear();
        cin.getline(buffer, BUFFER_LENGTH);
        sbuffer = buffer;
        dprintf(debug_fd, "%s\n", buffer);
        if (sbuffer.find("force") != string::npos) {
            dprintf(debug_fd, "%s\n", "[Force] True");
            setForce(true);
        }
        else if (sbuffer.find("white") != string::npos){
            //change engine color to black and set white on move
            table->set_engine_on_white();

            if (sbuffer.find("go") != string::npos){
                setForce(false);
                cout<<"go found"<<endl;
                break;
            }
            sbuffer = "other";
        }
        else if (sbuffer.find("black") != string::npos){
            //change color to white and set black on move
            table->set_engine_on_black();

            if (sbuffer.find("go") != string::npos){
                setForce(false);
                cout<<"go found"<<endl;
                break;
            }
            sbuffer = "other";
        }
        else if (sbuffer.find("go") != string::npos){
            dprintf(debug_fd, "%s\n", "[Go] [Force] False");
            setForce(false);
            break;
        }
        else if (sbuffer.find("new") != string::npos){
            //change color to white and set black on move
            return "new";
        }
        else if (sbuffer.find("quit") != string::npos){
            dprintf(debug_fd, "%s\n", quit);
            fflush(stdout);
            return "quit";
        }
        else if (sbuffer.find("usermove") != string::npos && sbuffer.length() < 10) {
            //citire doar mutarea, usermove a fost deja citit somehow
            memset(buffer, 0, BUFFER_LENGTH);
            fflush(stdin);
            cin.clear();
            cin >> buffer;
            sbuffer = buffer;
            dprintf(debug_fd, "%s\n", buffer);
            fflush(stdout);
            sbuffer = sbuffer.substr(0, 4);
            break;
        }
        else if (sbuffer.find("usermove") != string::npos) {
            sbuffer = sbuffer.substr(9, 4);
            break;
        } 
        
        else {
            sbuffer = "other";
        }
    }
    return sbuffer;
}

void XboardInterface::setForce(bool force){
    this->force = force;
}

void XboardInterface::setResign(bool resign){
    this->resign = resign;
}

bool XboardInterface::getForce(){
    return force;
}

bool XboardInterface::getResignStatus(){
    return resign;
}

void XboardInterface::setDebugFd(int fd){
    this->debug_fd = fd;
}

void XboardInterface::setTable(Table * table) {
    this->table = table;
}

/* send to xboard command_to_write */
int XboardInterface::write_to_xboard(string command_to_write) {
    cout << command_to_write;
    fflush(stdout);
    return 1;
}

int XboardInterface::write_to_debug_file(string command_to_write) {
    char buffer[BUFFER_LENGTH];
    memset(buffer, 0, BUFFER_LENGTH);
    strcpy(buffer, command_to_write.c_str());
    write(debug_fd, buffer, strlen(buffer));
    return 1;
}

/* listen to xboard until command_to_wait_for parameter */
int XboardInterface::listen_to_xboard(string command_to_wait_for) {
    char buffer[BUFFER_LENGTH];
    memset(buffer, 0, BUFFER_LENGTH);
    fflush(stdin);
    cin.clear();
    cin.getline(buffer, BUFFER_LENGTH);
    dprintf(debug_fd, "%s\n", buffer);
    fflush(stdout);
    string sbuffer = buffer;
    while (sbuffer.find(command_to_wait_for) == string::npos) {
        if (sbuffer.find("white") != string::npos){
            table->set_engine_on_white();
            if (sbuffer.find("go") != string::npos){
                setForce(false);
            }
        }
        else if (sbuffer.find("black") != string::npos){
            table->set_engine_on_black();
            if (sbuffer.find("go") != string::npos){
                setForce(false);
            }
        }
        else if (sbuffer.find("go") != string::npos){
            setForce(false);
        }
        memset(buffer, 0, BUFFER_LENGTH);
        cin.getline(buffer, BUFFER_LENGTH);
        dprintf(debug_fd, "%s\n", buffer);
        fflush(stdout);
        sbuffer = buffer;
    }
    return 1;
}
int XboardInterface::get_one_time(string time_type) {
    char buffer[BUFFER_LENGTH];
    memset(buffer, 0, BUFFER_LENGTH);
    vector<string> split_vector;
    read(IN_FD, buffer, strlen(buffer));
    string sbuffer = buffer;
    while (sbuffer.find(time_type) == string::npos) {
        write(debug_fd, buffer, strlen(buffer));
        memset(buffer, 0, BUFFER_LENGTH);
        read(IN_FD, buffer, BUFFER_LENGTH);
        sbuffer = buffer;
    }
    sbuffer = sbuffer.substr(5, 5);
    return stoi(sbuffer, nullptr, 10);
}

int XboardInterface::get_times() {
    engine_time = get_one_time("time");
    opponent_time = get_one_time("otim");
}