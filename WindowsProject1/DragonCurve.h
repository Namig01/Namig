#pragma once
#include "Shape.h"
#include <cmath>
#define CONSTANT_ANGLE 135
#define M_PI 3.14159262357973
class DragonCurve
{
public:
	void Draw(HDC &hdc, int n, Point<float> &, Point<float> &, Point<float> &);
};

