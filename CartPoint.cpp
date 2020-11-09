#include "CartPoint.h"
#include <string.h>
#include <string>

CartPoint::CartPoint() {}
CartPoint::CartPoint(int x, int y){
        this->x = x;
        this->y = y;
    }
void CartPoint::setX(int xNou){
        this->x = xNou;
    }
void CartPoint::setY(int yNou){
        this->y = yNou;
    }
int CartPoint::getX(){
        return this->x;
    }
int CartPoint::getY(){
        return this->y;
}
char CartPoint::getChessX(){
    //return pozition on X axis but in chess coordinates(a,b,c..)
    char c = this->x + 'a';
    return  c;
}
char CartPoint::getChessY(){
    //return pozition on Y axis but in chess coordinates
    char c = '8' - this->y;
    return  c;
}



