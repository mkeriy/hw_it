#include "Figure.hpp"

points_t operator-(points_t& f1, points_t& f2)
{
	return { f1.first - f2.first, f1.second - f2.second };
}

points_t operator+(points_t& f1, points_t& f2)
{
	return { f1.first + f2.first, f1.second + f2.second };
}

std::istream& operator>>(std::istream& in, points_t& f)
{
	char c;
	in >> c;
	in >> f.first;
	in >> c;
	in >> f.second;
	in >> c;
	return in;
}

double length(points_t f1, points_t f2) 
{
	f1 = f1 - f2;
	double result = std::pow(f1.first * f1.first + f1.second * f1.second, 0.5);
	return result;
}

double Ellipse::perimeter() const
{
	return 4 * (M_PI * length(c_majSemi, c_center) * length(c_minSemi, c_center) + (length(c_majSemi, c_center) - length(c_minSemi, c_center))) / (length(c_majSemi, c_center) + length(c_minSemi, c_center));
}

double Ellipse::area() const
{
	return M_PI * length(c_majSemi, c_center) * length(c_minSemi, c_center);
}

void Ellipse::about()
{
	std::cout << "ELLIPSE." << std::endl;
	std::cout << "Enter coordinates.(write like this (x, y))" << std::endl;
	std::cout << "Coordinate of major SemiAxis: ";
	std::cin >> c_majSemi;
	std::cout << "Coordinate of center: ";
	std::cin >> c_center;
	std::cout << "Coordinate of minor SemiAxis: ";
	std::cin >> c_minSemi;

	std::cout << "Perimeter: " << perimeter()
		<< "Area: " << area() << std::endl;
}

void Circle::about()
{
	std::cout << "CIRCLE." << std::endl;
	std::cout << "Enter coordinates.(write like this (x, y))" << std::endl;
	std::cout << "Coordinate of center: ";
	std::cin >> c_center;
	std::cout << "Coordinate of Radius: ";
	std::cin >> c_minSemi;

	std::cout << "Perimeter: " << perimeter()
		<< " Area: " << area() << std::endl;
}

void Parallelogram::about()
{
	std::cout << "PARALLELOGRAM." << std::endl;
	std::cout << "Enter coordinates.(write like this (x, y))" << std::endl;
	std::cout << "Coordinate of vertex A: ";
	std::cin >> c_A;
	std::cout << "Coordinate of vertex B: ";
	std::cin >> c_B;
	std::cout << "Coordinate of vertex D: ";
	std::cin >> c_D;

	std::cout << "Angles: " << angle() << " and " << 180 - angle() << std::endl;
	std::cout << "Diagonal AÑ: " << length(c_A, vertexÑ()) << " Diagonal BD: " << length(c_B, c_D) << std::endl;
	std::cout << "Perimeter: " << perimeter()
		<< " Area: " << area() << std::endl;
}

points_t Parallelogram::vertexÑ()
{
	points_t vec = c_D - c_A;
	return c_B + vec;
}

double Parallelogram::perimeter() const 
{
	return 2 * (length(c_A, c_B) + length(c_A, c_D));
}

double Parallelogram::area() const
{
	return m_height * length(c_A, c_D);
}

double Parallelogram::angle() const
{
	return  asin(m_height / length(c_A, c_B)) * (180 / M_PI);
}

void Rhombus::about()
{
	std::cout << "RHOUMBUS."<< std::endl;
	std::cout << "Enter coordinates.(write like this (x, y))" << std::endl;
	std::cout << "Coordinate of vertex A: ";
	std::cin >> c_A;
	std::cout << "Coordinate of vertex B: ";
	std::cin >> c_B;
	std::cout << "Coordinate of vertex D: ";
	std::cin >> c_D;


	std::cout << "Angles: " << angle() << " and " << 180 - angle() << std::endl;
	std::cout << "Diagonal AÑ: " << length(c_A, vertexÑ()) << " Diagonal BD: " << length(c_B, c_D) << std::endl;
	std::cout << "Perimeter: " << perimeter()
		<< " Area: " << area() << std::endl;
}

void Rectangle::about()
{

	std::cout << "RECTANGLE." << std::endl;
	std::cout << "Enter coordinates.(write like this (x, y))" << std::endl;
	std::cout << "Coordinate of vertex A: ";
	std::cin >> c_A;
	std::cout << "Coordinate of vertex B: ";
	std::cin >> c_B;
	std::cout << "Coordinate of vertex D: ";
	std::cin >> c_D;

	std::cout << "Diagonal AÑ: " << length(c_A, vertexÑ()) << " Diagonal BD: " << length(c_B, c_D) << std::endl;
	std::cout << "Perimeter: " << perimeter()
			<< " Area: " << area() << std::endl;
	
}

void Square::about()
{
	std::cout << "SQUARE." << std::endl;
	std::cout << "Enter coordinates.(write like this (x, y))" << std::endl;
	std::cout << "Coordinate of vertex A: ";
	std::cin >> c_A;
	std::cout << "Coordinate of vertex B: ";
	std::cin >> c_B;
	std::cout << "Coordinate of vertex D: ";
	std::cin >> c_D;

	std::cout << "Diagonal AÑ: " << length(c_A, vertexÑ()) << " Diagonal BD: " << length(c_B, c_D) << std::endl;
	std::cout << "Perimeter: " << perimeter()
		<< " Area: " << area() << std::endl;
}

double Triangle::perimeter() const
{
	return length(c_A, c_B) + length(c_A, c_D) + length(c_B, c_D);
}

double Triangle::area() const
{
	double p = perimeter() / 2;
	return std::pow(p * (p - length(c_A, c_B)) * (p - length(c_A, c_D)) * (p - length(c_B, c_D)), 0.5);
}

double Triangle::angle() const
{
	double m_h = 2 * Triangle::area() / length(c_A, c_D);
	return  asin(m_h / length(c_A, c_B)) * (180 / M_PI);
}
double Triangle::angle2() const
{
	double m_h = 2 * Triangle::area() / length(c_A, c_D);
	return  asin(m_h / length(c_A, c_B)) * (180 / M_PI);
}

void Triangle::about()
{
	std::cout << "TRIANGLE." << std::endl;
	std::cout << "Enter coordinates.(write like this (x, y))" << std::endl;
	std::cout << "Coordinate of vertex A: ";
	std::cin >> c_A;
	std::cout << "Coordinate of vertex B: ";
	std::cin >> c_B;
	std::cout << "Coordinate of vertex C: ";
	std::cin >> c_D;

	std::cout << "Angles: " << angle() << " and " << 180 - angle() - angle2() << " and " <<  angle2() << std::endl;
	std::cout << "Perimeter: " << perimeter()
		<< " Area: " << area() << std::endl;
}