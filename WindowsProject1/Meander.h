#pragma once
#include <cmath>
#include <vector>
#include "windows.h"

class Meander
{
public:
	void Draw(const HDC&, int, int, int, int);

	void Line(const HDC& dc, const int x1, const int y1, const int x2, const int y2) {
		MoveToEx(dc, x1, y1, 0);
		LineTo(dc, x2, y2);
	}
};



