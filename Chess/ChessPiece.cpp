#include "stdafx.h"
#include <string>
#include "def.h"
#include "Point.h"
#include "ChessPoint.h"
#include "ChessPiece.h"


ChessPiece::ChessPiece(std::string symbol, int color, ChessPoint pos) : myPos(pos), playerSymbol(symbol), playerColor(color)
{
	//playerSymbol = symbol;
	//playerColor = color;
}

Point ChessPiece::getPos() { return myPos; }

int ChessPiece::getColor() { return playerColor; }

int ChessPiece::getDir() { return playerColor; }

bool ChessPiece::validMove(Point pos) { return true; }

bool ChessPiece::doMove(Point pos)
{
	if (validMove(pos))
		return (myPos.setR(pos.r) && myPos.setC(pos.c));
	else
		return false;
}

std::string ChessPiece::getSymbol() {
	if (getColor() == BLACK)
		return playerSymbol;
	else
	{
		std::string ret = "";
		ret += toupper(playerSymbol[0]);
		return ret;
	}
}
