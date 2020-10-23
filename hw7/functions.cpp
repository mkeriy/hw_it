#include "Figures.hpp"




void Ellipse::about()
{
	std::cout << "Ellipse." << std::endl;
	std::cout << "major semi-axis: " << m_majSemiaxis << std::endl;
	std::cout << "minor semi-axis: " << m_minSemiaxis << std::endl;
	std::cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << std::endl;
	std::cout << "Cordinates: ";

	for (const auto& f : points) {
				std::cout << "(" << std::get<0>(f) << "; " << std::get<1>(f) << "), ";
			}
	std::cout << std::endl;
}
double Ellipse::area() const
{
	return M_PI*m_majSemiaxis*m_minSemiaxis;
}

double Ellipse::perimeter() const
{
	return 4*(M_PI*m_majSemiaxis*m_minSemiaxis + (m_majSemiaxis - m_minSemiaxis))/(m_majSemiaxis + m_minSemiaxis);
}

void Circle::about()
{
	std::cout << "Circle." << std::endl;
	std::cout << "Radius " << m_majSemiaxis << std::endl;

	std::cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << std::endl;
	std::cout << "Cordinates: ";

	for (const auto& f : points) {
				std::cout << "(" << std::get<0>(f) << "; " << std::get<1>(f) << "), ";
			}
	std::cout << std::endl;
}

double Parallelogram::area() const
{
	return m_hight*m_sideB;
}

double Parallelogram::perimeter() const
{
	return 2*(m_sideA + m_sideB);
}
double Parallelogram::angle()
{
	return  asin(m_hight/m_sideA) * (180 / M_PI);
}

void Parallelogram::about()
{
	std::cout << "Parallelogram." << std::endl;
	std::cout << "Sides of a parallelogram: " << m_sideA << " and " << m_sideB << std::endl;
	std::cout << "Parallelogram height: " << m_hight << std::endl;
	std::cout << "Parallelogram angles: " << angle() << " and " << 180 - angle() << std::endl;
	std::cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << std::endl;
	std::cout << "Cordinates: ";

	for (const auto& f : points) {
				std::cout << "(" << std::get<0>(f) << "; " << std::get<1>(f) << "), ";
			}
	std::cout << std::endl;
}

void Rhombus::about()
{
	std::cout << "Rhombus." << std::endl;
	std::cout << "Sides of a Rhombus: " << m_sideA << std::endl;
	std::cout << "Rhombus height: " << m_hight << std::endl;
	std::cout << "Rhombus angles: " << angle() << " and " << 180 - angle() << std::endl;
	std::cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << std::endl;
	std::cout << "Cordinates: ";
	for (const auto& f : points) {
				std::cout << "(" << std::get<0>(f) << "; " << std::get<1>(f) << "), ";
			}
	std::cout << std::endl;
}

void Rectangle::about()
{
	std::cout << "Rectangle." << std::endl;
	std::cout << "Sides of a Rectangle: " << m_sideA << " and " << m_sideB << std::endl;
	std::cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << std::endl;
	std::cout << "Cordinates: ";

	for (const auto& f : points) {
				std::cout << "(" << std::get<0>(f) << "; " << std::get<1>(f) << "), ";
			}
	std::cout << std::endl;
}

void Square::about()
{
	std::cout << "Square." << std::endl;
	std::cout << "Sides of a Square: " << m_sideA << std::endl;
	std::cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << std::endl;
	std::cout << "Cordinates: ";

	for (const auto& f : points) {
				std::cout << "(" << std::get<0>(f) << "; " << std::get<1>(f) << "), ";
			}
	std::cout << std::endl;
}
