#include "stdafx.h"
#include "DragonCurve.h"


void DragonCurve::Draw(HDC &hdc, int n, Point<float> &OneCoordinate, Point<float> &TwoCoordinate, Point<float> &ThreeCoordinate)
{
	if (n == 1)
	{
		Line First(OneCoordinate, TwoCoordinate);
		Line Second(TwoCoordinate, ThreeCoordinate);

		First.Draw(hdc);
		Second.Draw(hdc);
	}
	else
	{
		Point<float> NewOneCoordinate
		(
			cos(M_PI / 180 * CONSTANT_ANGLE) * (OneCoordinate.x - TwoCoordinate.x) * 1.f / sqrt(2.f) - sin(M_PI / 180 * CONSTANT_ANGLE) * (OneCoordinate.y - TwoCoordinate.y) * 1.f / sqrt(2.f) + OneCoordinate.x,
			sin(M_PI / 180 * CONSTANT_ANGLE) * (OneCoordinate.x - TwoCoordinate.x) * 1.f / sqrt(2.f) + cos(M_PI / 180 * CONSTANT_ANGLE) * (OneCoordinate.y - TwoCoordinate.y) * 1.f / sqrt(2.f) + OneCoordinate.y
		);

		Point<float> NewTwoCoordinate
		(
			cos(M_PI / 180 * -CONSTANT_ANGLE) * (TwoCoordinate.x - ThreeCoordinate.x) * 1.f / sqrt(2.f) - sin(M_PI / 180 * -CONSTANT_ANGLE) * (TwoCoordinate.y - ThreeCoordinate.y) * 1.f / sqrt(2.f) + TwoCoordinate.x,
			sin(M_PI / 180 * -CONSTANT_ANGLE) * (TwoCoordinate.x - ThreeCoordinate.x) * 1.f / sqrt(2.f) + cos(M_PI / 180 * -CONSTANT_ANGLE) * (TwoCoordinate.y - ThreeCoordinate.y) * 1.f / sqrt(2.f) + TwoCoordinate.y
		);



		Draw(hdc, n - 1, OneCoordinate, NewOneCoordinate, TwoCoordinate);
		Draw(hdc, n - 1, TwoCoordinate, NewTwoCoordinate, ThreeCoordinate);
	}
}