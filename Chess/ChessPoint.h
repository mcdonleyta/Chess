#ifndef _CHESSPOINT_H_
#define _CHESSPOINT_H_

#include "Point.h"

class ChessPoint : public Point
{
 public:
	int getR() {
		return r;
	}
	int getC() {
		return c;
	}

	//Description: Check 0 <= val < 8 before setting
	//Returns: True if set was successful (ie: val is between 0 and 8)
	bool setR(int val) {
		if (val >= 0 && val < BOARDHEIGHT)
		{
			r = val;
			return true;
		}
		return false;
	}

	bool setC(int val) {
		if (val >= 0 && val < BOARDWIDTH)
		{
			c = val;
			return true;
		}
		return false;
	}

	ChessPoint(Point pos) : Point(pos) {
	}

	ChessPoint(int r, int c): Point(r, c) {
		//setR(r);
		//setC(c);
	}
};


#endif