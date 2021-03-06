// Chess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "def.h"
#include "Point.h"
#include "ChessPoint.h"
#include "ChessPiece.h"
#include "Screen.h"

using namespace std;



class PiecePawn : public ChessPiece
{
  private:
	bool firstMove;

  public:
	  PiecePawn(int color, ChessPoint pos) : ChessPiece("p", color, pos) { 
		  firstMove = true; 
	  }

	bool validMove(Point pos) {
		if ( (pos.c == myPos.getC() && pos.r == myPos.getR() + getDir()) ||
			 (pos.c == myPos.getC() && pos.r == myPos.getR() + getDir()*2 && firstMove)
		   )
			return true;
		else
			return false;
	}

	bool doMove(Point pos) {
		if (ChessPiece::doMove(pos))
		{
			firstMove = false;
			return true;
		}
		else
			return false;
	}
};

class PieceRook : public ChessPiece
{ 
 public:
	PieceRook(int color, ChessPoint pos) : ChessPiece("r", color, pos) {
	}

	bool validMove(Point pos) {
		if ((pos.c == myPos.getC() && pos.r != myPos.getR()) ||
			(pos.c != myPos.getC() && pos.r == myPos.getR())
			)
			return true;
		else
			return false;
	}
};

void drawBoard(Screen& display)
{
	//Draw Board Border
	string wall = "";
	for (int i = 0; i < SCREENWIDTH; i++)
		wall += BOARDTOPWALL;
	display.setScreen(0, 0, wall);

	wall = "";
	for (int i = 0; i < SCREENWIDTH; i++)
		wall += BOARDBOTWALL;
	display.setScreen(SCREENHEIGHT - 1, 0, wall);

	for (int i = 1; i < SCREENHEIGHT - 1; i++)
	{
		wall = BOARDLEFTWALL;
		display.setScreen(i, 0, wall);
		wall = BOARDRIGHTWALL;
		display.setScreen(i, SCREENWIDTH - 1, wall);
	}

	//Draw Board Border Corners
	wall = BOARDCORNERTL;
	display.setScreen(0, 0, wall);
	wall = BOARDCORNERBL;
	display.setScreen(SCREENHEIGHT - 1, 0, wall);
	wall = BOARDCORNERTR;
	display.setScreen(0, SCREENWIDTH - 1, wall);
	wall = BOARDCORNERBR;
	display.setScreen(SCREENHEIGHT - 1, SCREENWIDTH - 1, wall);

	//Draw Board Row Separators
	string line = "";
	for (int i = 1; i < SCREENWIDTH - 1; i++)
		line += BOARDHDIV;
	for (int i = 0; i < BOARDWIDTH - 1; i++)
		display.setScreen(2 + i * 2, 1, line);

	//Draw Board Col Separators
	line = BOARDVDIV;
	for (int r = 0; r < BOARDHEIGHT; r++)
		for (int c = 1; c < BOARDWIDTH; c++)
			display.setScreen(1 + r * 2, c * 4, line);

}


int main()
{
	char x;
	Screen display(SCREENHEIGHT, SCREENWIDTH);
	vector<ChessPiece> whitePieces;
	vector<ChessPiece> blackPieces;

	//Make all the white pieces
	for (int c = 0; c < BOARDWIDTH; c++) {
		ChessPoint newPos(BOARDHEIGHT - 2, c);
		whitePieces.push_back(PiecePawn(WHITE, newPos));
	}
	whitePieces.push_back(PieceRook(WHITE, ChessPoint(BOARDHEIGHT - 1, 0)));
	whitePieces.push_back(PieceRook(WHITE, ChessPoint(BOARDHEIGHT - 1, BOARDWIDTH-1)));


	//Make all the black pieces
	for (int c = 0; c < BOARDWIDTH; c++) {
		ChessPoint newPos(1, c);
		blackPieces.push_back(PiecePawn(BLACK, newPos));
	}
	blackPieces.push_back(PieceRook(BLACK, ChessPoint(0, 0)));
	blackPieces.push_back(PieceRook(BLACK, ChessPoint(0, BOARDWIDTH - 1)));


	drawBoard(display);

	//Draw Pieces
	for (ChessPiece p : whitePieces)
		display.setScreen(p);
	for (ChessPiece p : blackPieces)
		display.setScreen(p);


	display.printScreen();

	cin >> x;

    return 0;
}

