#include "stdafx.h"
#include "Screen.h"
#include "def.h"
#include "ChessPiece.h"
#include <iostream>

Screen::Screen(int height, int width)
{
	this->width = width;
	this->height = height;
	clrBuffer();
}

void Screen::clrBuffer()
{
	buffer = {};
	for (int h = 0; h < height; h++) {
		std::string line = "";
		for (int w = 0; w < width; w++)
			if ((w % 8 < 4 && h % 4 < 2) || (w % 8 >= 4 && h % 4 >= 2))
				line += BOARDBLANK;
			else
				line += " ";
		buffer.push_back(line);
	}
}

void Screen::setScreen(int r, int c, std::string line)
{
	int amount = line.size();
	if (r >= 0 && r < height)
	{
		if (c + amount > SCREENWIDTH)
			amount = SCREENWIDTH - c;

		buffer[r].replace(c, amount, line);
	}
}


void Screen::setScreen(ChessPiece p)
{
	std::string line = p.getSymbol();
	Point pos = p.getPos();
	setScreen(1 + pos.r * 2, 2 + pos.c * 4, line);
}


void Screen::printScreen()
{
	for (std::string l : buffer)
		std::cout << l << std::endl;
}

