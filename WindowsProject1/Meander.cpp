#include "stdafx.h"
#include "Meander.h"


void Meander::Draw(const HDC& dc, int rept, int x, int y, int time)

{
	int move = 0;
	for (int i = 1; i <= rept; i++)
	{

		if (rept == i)

		{

			Line(dc, x + move, y, x + move, y - 40);
			Line(dc, x + move, y - 40, x + 50 + move, y - 40);
			Line(dc, x + 50 + move, y - 40, x + 50 + move, y - 15);
			Line(dc, x + 50 + move, y - 15, x + 35 + move, y - 15);
			Line(dc, x + 35 + move, y - 15, x + 35 + move, y - 25);
			Line(dc, x + 35 + move, y - 25, x + 20 + move, y - 25);
			Line(dc, x + 20 + move, y - 25, x + 20 + move, y);
			Line(dc, x + 20 + move, y, x + 50 + move, y);

		}
		else {
			Line(dc, x + move, y, x + move, y - 40);
			Line(dc, x + move, y - 40, x + 50 + move, y - 40);
			Line(dc, x + 50 + move, y - 40, x + 50 + move, y - 15);
			Line(dc, x + 50 + move, y - 15, x + 35 + move, y - 15);
			Line(dc, x + 35 + move, y - 15, x + 35 + move, y - 25);
			Line(dc, x + 35 + move, y - 25, x + 20 + move, y - 25);
			Line(dc, x + 20 + move, y - 25, x + 20 + move, y);
			Line(dc, x + 20 + move, y, x + 75 + move, y);

		}
		move += 75;
		Sleep(time);

	}
	move = 0;
}




