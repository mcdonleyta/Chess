#ifndef _SCREEN_H_
#define _SCREEN_H_

#include<vector>
#include<string>
#include "def.h"
#include "ChessPiece.h"

class Screen
{
 private:
	int width;
	int height;
	std::vector<std::string> buffer;

 public:
	 Screen(int height, int width);
	 void clrBuffer();
	 void setScreen(ChessPiece p);
	 void setScreen(int r, int c, std::string line);
	 void printScreen();
	
};

#endif