#include "stdafx.h"
#include "Star.h"


void Star::Draw(const HDC& dc)
{
	//m_Point m_Point[size];


	//for (int i = 1; i <= size; i++)
	//{
	//	if (!(i % 2))
	//	{
	//		m_Point[i - 1].x = x + sin((i * 2 - 1)*M_PI / Ray)*inner_radius;
	//		m_Point[i - 1].y = y - cos((i * 2 - 1)*M_PI / Ray)*inner_radius;
	//	}
	//	//MyStar.push_back(cm_Point(x + sin((i * 2 - 1)*M_PI / size)*inner_radius, y - cos((i * 2 - 1)*M_PI / size)*inner_radius));

	//	else {
	//		m_Point[i - 1].x = x + sin(i * 2 * M_PI / Ray)*outer_radius + 1;
	//		m_Point[i - 1].y = y - cos(i * 2 * M_PI / Ray)*outer_radius - 1;
	//	}
	//	//MyStar.push_back(cm_Point(x + sin(i * 2 * M_PI / size)*outer_radius + 1, y - cos(i * 2 * M_PI / size)*outer_radius - 1));

	//}

	//Polygon(dc, m_Point, size);


	//Polyline(dc, m_Point, size);
	//PolyDraw(dc, m_Point, polytype, size);

	//Line(dc, MyStar);
	Line mLine;
	for (int i = 1; i <= Ray; i++)
	{

		m_Point.push_back(Point<float>(centerPos.x + sin((i * 2 - 1)*M_PI / Ray)*inner_radius, centerPos.y - cos((i * 2 - 1)*M_PI / Ray)*inner_radius));

		m_Point.push_back(Point<float>(centerPos.x + sin(i * 2 * M_PI / Ray)*outer_radius + 1, centerPos.y - cos(i * 2 * M_PI / Ray)*outer_radius - 1));

	}
	int n = 25;
	while (n--)
	{
		rotar();
		mLine.CurveDraw(dc, m_Point);
		Sleep(150);
	}

}


void Star::rotar()
{
	Point<float> p;

	for (int i = 0; i < m_Point.size(); i++)
	{
			m_Point[i].x = m_Point[i].x - centerPos.x;
			m_Point[i].y = m_Point[i].y - centerPos.y;


			p.x = m_Point[i].x*cos(corner) - m_Point[i].y*sin(corner);
			p.y = m_Point[i].y*cos(corner) + m_Point[i].x*sin(corner);


			m_Point[i].x = p.x + centerPos.x;
			m_Point[i].y = p.y + centerPos.y;
	}
};
