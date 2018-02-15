#ifndef _POINT_H_
#define _POINT_H_

class Point
{
public:
	int r;
	int c;

	Point(int y, int x) : r(y), c(x)
	{
		//r = y;
		//c = x;
	}

	Point() : r(-1), c(-1)
	{
		//r = -1;
		//c = -1;
	}
};


#endif