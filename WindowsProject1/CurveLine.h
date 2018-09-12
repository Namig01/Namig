#pragma once
#include "Shape.h"
#include "windows.h"
class CurveLine
{
public:
	CurveLine(int rept, int timer): 
		rept(rept), timer(timer)
	{}
	void Draw(HDC &);
	Point<float> mPoint;
	int rept;
	int timer;
};

