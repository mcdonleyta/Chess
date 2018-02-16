#ifndef _CHESSPIECE_H_
#define _CHESSPIECE_H_

#include <string>
#include "Point.h"
#include "ChessPoint.h"

class ChessPiece
{
private:
	int			playerColor;
	std::string		playerSymbol;

protected:
	ChessPoint  myPos;

public:
	ChessPiece(std::string symbol, int color, ChessPoint pos);

	Point getPos();
	int getColor();
	int getDir();
	virtual bool validMove(Point pos);
	virtual bool doMove(Point pos);
	std::string getSymbol();
};



#endif