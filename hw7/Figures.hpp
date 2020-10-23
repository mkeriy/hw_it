#pragma once
#include <iostream>
#include <vector>
#include <utility>

class Figures
{
	public:
	Figures(double a, double b):
	m_param1(a), m_param2(b)
	{}
	virtual ~Figures(){}

	virtual void about();
	virtual double area();
	virtual double perimeter();

	protected:
	double m_param1;
	double m_param2;
	std::vector<std::pair<double, double>> point;
	const double pi = 3.141592653589793;
};

class Ellipse : public Figures
{
	public:
	Ellipse(double a, double b):
		Figures(a, b)
		{}
	virtual ~Ellipse(){}
	virtual void about() override;
	virtual double  area() override;
	virtual double perimeter() override;

	protected:
	void getCordin();

};

class Circle : public Ellipse
{
	public:
	Circle(double r):
		Ellipse(r, r)
	{}
	virtual ~Circle(){}

	virtual void about() override;
};

class Parallelogram : public Figures
{
	public:
	Parallelogram(double a, double b, double hb):
		Figures(a, b), m_hight(hb)
	{}

	virtual ~Parallelogram(){};

	virtual void about();
	virtual double  area() override;
	virtual double perimeter() override;
	double angle();
	protected:
		void getCordin();
		double m_hight;
};

class Rhombus : public Parallelogram
{
	public:
	Rhombus(double a, double h):
		Parallelogram(a, a, h)
	{}
	virtual ~Rhombus(){}
	virtual void about() override;

};

class Rectangle: public Parallelogram
{
	public:
		Rectangle(double a, double b):
			Parallelogram(b, a, b)
	{}
		virtual ~Rectangle(){}

		virtual void about() override;
};

class Square: public Rectangle
{
	public:
	Square(double a):
	Rectangle(a, a)
	{}
	virtual ~Square(){}
	virtual void about() override;
};


