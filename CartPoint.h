using namespace std;
#ifndef CARTPOINT_H_
#define CARTPOINT_H_
#include <iostream>
#include <string>
#include <vector>

class CartPoint {
	public:
		CartPoint();
		CartPoint(int x, int y);
		int getX();
		int getY();
		void setX(int x);
		void setY(int y);
		char getChessX();
		char getChessY();
	private:
		int x;
		int y;
};

#endif /* CARTPOINT_H_ */
