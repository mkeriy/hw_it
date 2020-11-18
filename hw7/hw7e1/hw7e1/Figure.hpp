#pragma once
#include <iostream>
#include <vector>
#include <utility>
#define _USE_MATH_DEFINES
#include <math.h>
using points_t = std::pair< double, double>;

class Figure
{
public:
		Figure(){}
		virtual ~Figure() = default;
		std::vector<points_t> points;
		virtual void about() = 0;
	
	protected:
		
		friend double length(points_t f1, points_t f2);
		virtual double perimeter() const = 0;
		virtual double area() const = 0;
		friend std::istream& operator>>(std::istream& in, points_t& f);
		friend points_t operator-(points_t& f1, points_t& f2);
		friend points_t operator+(points_t& f1, points_t& f2);
};

class Ellipse: public Figure
{
	public:
		Ellipse(){}
		Ellipse(points_t c, points_t a, points_t b) :
			c_center(c), c_majSemi(a), c_minSemi(b)
		{
			points.push_back(c_center);
			points.push_back(c_majSemi);
			points.push_back(c_minSemi);
		}
		virtual ~Ellipse() = default;
		virtual void about() override;
	protected:
		virtual double perimeter() const override;
		virtual double area() const override;
		points_t c_center;
		points_t c_majSemi;
		points_t c_minSemi;

};

class Circle : public Ellipse
{
	public:
		Circle(){}
		Circle(points_t c, points_t r):
			Ellipse(c, r, r)
		{}
		virtual ~Circle() = default;
		virtual void about() override;
};

class Parallelogram: public	Figure
{
	public:
		Parallelogram(){}
		Parallelogram(points_t a, points_t b, points_t d):
		c_A(a), c_B(b), c_D(d)
		{
			points.push_back(c_A);
			points.push_back(c_B);
			points.push_back(c_D);
		}
		virtual ~Parallelogram() = default;
		virtual void about();
	
	protected:
		points_t c_A;
		points_t c_B;
		points_t c_D;
		double m_height = std::pow(c_A.first * c_A.first + (c_A.second - c_B.second) * (c_A.second - c_B.second), 0.5);
		virtual double perimeter() const override;
		virtual double area() const override;
		virtual points_t vertex—();
		virtual double angle() const;

};

class Rhombus : public Parallelogram
{
	public:
		Rhombus(){}
		Rhombus(points_t a, points_t b, points_t d) :
			Parallelogram(a, b, d)
		{}
		virtual ~Rhombus() = default;
		virtual void about() override;
};

class Rectangle : public Parallelogram
{
	public:
		Rectangle(){}
		Rectangle(points_t a, points_t b, points_t d):
			Parallelogram(a, b, d)
		{}
		virtual void about() override;
};

class Square : public Rectangle
{
	public:
		Square(){}
		Square(points_t a, points_t b, points_t d):
			Rectangle(a, b, d)
		{}
		virtual void about() override;
}; 

class Triangle : public Parallelogram
{
	public: 
		Triangle(){}
		Triangle(points_t a, points_t b, points_t c):
			Parallelogram(a, b, c)
		{}
		virtual void about() override;
		virtual double perimeter() const override;
		virtual double area() const override;
		virtual double angle() const override;
		double angle2() const;
};