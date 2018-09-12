#pragma once
#include "stdafx.h"
#include "windows.h"
#include <vector>

	template<typename T>
	class Point
	{
	public:
		Point(T x = 100, T  y = 100) :x(x), y(y) {};
		Point(const Point<T> &Point)
		{
			x = Point.x;
			y = Point.y;
		}
		~Point() {};
		const Point& operator+(const Point &Second) {
			return Point(this->x + Second.x, this->y + Second.y);
		};
		const Point& operator-(const Point &Second) {
			return Point(this->x - Second.x, this->y - Second.y);
		};
		const Point& operator*(const Point &Second) {
			return Point(this->x * Second.x, this->y * Second.y);
		};
		const Point& operator/(const Point &Second) {
			return Point(this->x / Second.x, this->y / Second.y);
		};

		operator Point<float>()
		{
			return {
				(float)this->x,
				(float)this->y
			};
		};

		void operator=(const Point<T> &Second)
		{
			this->x = Second.x;
			this->y = Second.y;
		};

	public:
		T x, y;
	};

	class Property
	{
	public:
		Property()
		{
			time = width = rept = 1;
		};
		~Property() {};


	public:
		int width;
		int rept;
		struct Color
		{
			int r;
			int g;
			int b;

		};

		Color m_Color;
		Point<int> m_Point;
		int time;
		float corner = 45.f;
	};


	class Line
	{
	public:
		Line() {};
		Line(const Point<float> &a, const Point<float> &b) : First(a), Second(b)
		{};
		virtual ~Line() {};
		virtual void Draw(HDC &hdc)const
		{
			MoveToEx(hdc, First.x, First.y, NULL);
			LineTo(hdc, Second.x, Second.y);
		}
		void CurveDraw(const HDC& dc, std::vector<Point<float>> &VecPoint)
		{
			MoveToEx(dc, VecPoint[0].x, VecPoint[0].y, NULL);
			for (int i = 1; i < VecPoint.size(); i++)
				LineTo(dc, VecPoint[i].x, VecPoint[i].y);

			LineTo(dc, VecPoint[0].x, VecPoint[0].y);
		}

	private:
		Point<float> First, Second;
	};


