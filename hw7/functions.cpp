#include "Figures.hpp"
#include <cmath>


void Figures::about()
{
	std::cout << "FIGURES" << std::endl;
}
double Figures::area()
{
	return 0;
}

double Figures::perimeter()
{
	return 0;
}
void Ellipse::about()
{
	std::cout << "Ellipse." << std::endl;
	std::cout << "semi-major axis: " << m_param1 << std::endl;
	std::cout << "minor semiaxis: " << m_param2 << std::endl;
	std::cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << std::endl;
	std::cout << "Cordinates: ";
	getCordin();
	for (const auto& f : point) {
				std::cout << "(" << std::get<0>(f) << "; " << std::get<1>(f) << "), ";
			}
	std::cout << std::endl;
}
double Ellipse::area()
{
	return pi*m_param1*m_param2;
}

double Ellipse::perimeter()
{
	return 4*(pi*m_param1*m_param2 + (m_param1 - m_param2))/(m_param1 + m_param2);
}

void Ellipse::getCordin()
{
	point.push_back({0.0, 0.0});
	point.push_back({0.0, m_param2});
	point.push_back({m_param1, 0.0});
	point.push_back({0.0, -m_param2});
	point.push_back({-m_param1, 0.0});
}

void Circle::about()
{
	std::cout << "Circle." << std::endl;
	std::cout << "Radius " << m_param1 << std::endl;

	std::cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << std::endl;
	std::cout << "Cordinates: ";
	getCordin();
	for (const auto& f : point) {
				std::cout << "(" << std::get<0>(f) << "; " << std::get<1>(f) << "), ";
			}
	std::cout << std::endl;
}

double Parallelogram::area()
{
	return m_hight*m_param2;
}

double Parallelogram::perimeter()
{
	return 2*(m_param2 + m_param1);
}
double Parallelogram::angle()
{
	return  asin(m_hight/m_param1) * (180 / pi);
}
void Parallelogram::getCordin()
{
	point.push_back({0.0, 0.0});
	point.push_back({0.0, m_param2});
	point.push_back({m_param1*cos((pi/180)*angle()), m_hight});
	point.push_back({m_param1*cos((pi/180)*angle()) + m_param2, m_hight});
}
void Parallelogram::about()
{
	std::cout << "Parallelogram." << std::endl;
	std::cout << "Sides of a parallelogram: " << m_param1 << " and " << m_param2 << std::endl;
	std::cout << "Parallelogram height: " << m_hight << std::endl;
	std::cout << "Parallelogram angles: " << angle() << " and " << 180 - angle() << std::endl;
	std::cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << std::endl;
	std::cout << "Cordinates: ";
	getCordin();
	for (const auto& f : point) {
				std::cout << "(" << std::get<0>(f) << "; " << std::get<1>(f) << "), ";
			}
	std::cout << std::endl;
}

void Rhombus::about()
{
	std::cout << "Rhombus." << std::endl;
	std::cout << "Sides of a Rhombus: " << m_param1 << std::endl;
	std::cout << "Rhombus height: " << m_hight << std::endl;
	std::cout << "Rhombus angles: " << angle() << " and " << 180 - angle() << std::endl;
	std::cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << std::endl;
	std::cout << "Cordinates: ";
	getCordin();
	for (const auto& f : point) {
				std::cout << "(" << std::get<0>(f) << "; " << std::get<1>(f) << "), ";
			}
	std::cout << std::endl;
}

void Rectangle::about()
{
	std::cout << "Rectangle." << std::endl;
	std::cout << "Sides of a Rectangle: " << m_param1 << " and " << m_param2 << std::endl;
	std::cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << std::endl;
	std::cout << "Cordinates: ";
	getCordin();
	for (const auto& f : point) {
				std::cout << "(" << std::get<0>(f) << "; " << std::get<1>(f) << "), ";
			}
	std::cout << std::endl;
}

void Square::about()
{
	std::cout << "Square." << std::endl;
	std::cout << "Sides of a Square: " << m_param1 << std::endl;
	std::cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << std::endl;
	std::cout << "Cordinates: ";
	getCordin();
	for (const auto& f : point) {
				std::cout << "(" << std::get<0>(f) << "; " << std::get<1>(f) << "), ";
			}
	std::cout << std::endl;
}
