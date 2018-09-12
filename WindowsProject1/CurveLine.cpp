#include "stdafx.h"
#include "CurveLine.h"


void CurveLine::Draw(HDC &hdc)
{

	Point<float> StartPos(400.f, 400.f);
	mPoint = {400.f, 400.f};
	Line mLine;
	int move = 0;
	for (int i = 0; i < rept; i++)
	{

		mLine.Draw(hdc, mPoint, Point<float>(mPoint.x, StartPos.y + 10 + move));
		mPoint.x = StartPos.x - move;
		mPoint.y = StartPos.y + 10 + move;


		mLine.Draw(hdc,mPoint, Point<float>(StartPos.x + 10 + move, mPoint.y));
		mPoint.x = StartPos.x + 10 + move;


		mLine.Draw(hdc, mPoint, Point<float>(mPoint.x, StartPos.y - 10 - move));
		mPoint.y = StartPos.y - 10 - move;

		mLine.Draw(hdc, mPoint, Point<float>(StartPos.x - 10 - move, mPoint.y));
		mPoint.x = StartPos.x - 10 - move;

		move += 10;
		Sleep(timer);
	}
}


