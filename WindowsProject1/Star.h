#pragma once
#include "Shape.h"
#include <cmath>
#include <vector>
#define M_PI 3.14159262357973

class Star
{
public:
	Star(int Ray, int inner_radius, int outer_radius, Point<float> Point, float corner):Ray(Ray),
			inner_radius(inner_radius), outer_radius(outer_radius), centerPos(Point), corner(corner)
	{};

	~Star() {};
	void Draw(const HDC&);
	void rotar();
	int inner_radius;
	int outer_radius;
	std::vector<Point<float>> m_Point;
	Point<float> centerPos;
	int Ray;
	float corner;
};

