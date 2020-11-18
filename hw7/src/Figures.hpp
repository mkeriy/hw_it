#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#define _USE_MATH_DEFINES
using  point_t = std::pair<double, double>;

class Figure
{
	public:
	Figure(){}
	virtual ~Figure() = default;

	virtual void about() = 0;
	virtual double  area() const = 0;
	virtual double perimeter() const = 0;

	protected:
	std::vector<point_t> points;
};

class Ellipse : public Figure
{
	public:
	Ellipse(double x0, double y0, double xa, double yb):
		m_centerX(x0), m_centerY(y0), m_majSemiaxis(xa), m_minSemiaxis(yb)
	{
		points.push_back({m_centerX, m_centerY});
		points.push_back({m_majSemiaxis, m_centerY});
		points.push_back({m_centerX, m_minSemiaxis});
	}

	virtual ~Ellipse() = default;
	virtual void about();

	protected:
	void getCordin();
	double m_centerX;
	double m_centerY;
	double m_majSemiaxis;
	double m_minSemiaxis;
	virtual double area() const;
	virtual double perimeter() const;


};

class Circle : public Ellipse
{
	public:
	Circle(double r):
		Ellipse(r, r)
	{
		points.push_back({0.0, 0.0});
	}
	virtual ~Circle() = default;

	virtual void about();
};

class Parallelogram : public Figure
{
	public:
	Parallelogram(double a, double b, double hb):
		m_sideA(a), m_sideB(b), m_hight(hb)
	{
		points.push_back({0.0, 0.0});
		points.push_back({m_sideB, 0.0});
		points.push_back({m_sideA*cos((M_PI/180)*angle()), m_hight});
		points.push_back({m_sideA*cos((M_PI/180)*angle()) + m_sideB, m_hight});
	}

	virtual ~Parallelogram() = default;

	virtual void about();
	virtual double  area() const override;
	virtual double perimeter() const override;
	double angle();
	protected:
		double m_sideA;
		double m_sideB;
		double m_hight;
};

class Rhombus : public Parallelogram
{
	public:
	Rhombus(double a, double h):
		Parallelogram(a, a, h)
	{
		points.push_back({0.0, 0.0});
		points.push_back({m_sideB, 0.0});
		points.push_back({m_sideA*cos((M_PI/180)*angle()), m_hight});
		points.push_back({m_sideA*cos((M_PI/180)*angle()) + m_sideB, m_hight});
	}
	virtual ~Rhombus() = default;
	virtual void about();

};

class Rectangle: public Parallelogram
{
	public:
		Rectangle(double a, double b):
			Parallelogram(a, b, a)
	{
			points.push_back({0.0, 0.0});
			points.push_back({m_sideB, 0.0});
     		points.push_back({0.0, m_sideA});
			points.push_back({m_sideB, m_sideA});
	}
		virtual ~Rectangle() = default;

		virtual void about();
};

class Square: public Rectangle
{
	public:
	Square(double a):
	Rectangle(a, a)
	{
		points.push_back({0.0, 0.0});
	points.push_back({m_sideA, 0.0});
	points.push_back({m_sideA, m_sideA});
	points.push_back({m_sideA, m_sideA});
	}
	virtual ~Square() = default;
	virtual void about();
};


