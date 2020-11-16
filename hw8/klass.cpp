#include "Header.hpp"
#include <iostream>


Fraction::Fraction() 
{
	a = 0;
	b = 1;
	void chek_zero(b);
}

void check_zero(const Fraction& other)
{
	if (other.b == 0)
	{
		throw std::domain_error("Ошибка: деление на 0");
	}
}


Fraction::Fraction(int a_, std::size_t b_) : a(a_), b(b_) {}

Fraction::Fraction(double a_, double b_) : a(a_), b(b_) {}

// нахождение НОД //
int Fraction::GSD() 
{
	int c = abs(a);
	int d = b;
	while (c > 0 && d > 0)
		if (c > d)
			c %= d;
		else
			d %= c;

	return c + d;
}

// сокращение дроби //
void Fraction::reduction()
{
	int gsd = this->GSD();
	this->a /= gsd;
	this->b /= gsd;
}

// сложение //
Fraction operator+(Fraction lhs, Fraction rhs)
{
	Fraction tmp;
	tmp.a = lhs.a * rhs.b + lhs.b * rhs.a;
	tmp.b = lhs.b * rhs.b;
	tmp.reduction();
	return tmp;
}

// вычетание //
Fraction operator-(Fraction lhs, Fraction rhs)
{
	Fraction tmp;
	tmp.a = lhs.a * rhs.b - lhs.b * rhs.a;
	tmp.b = lhs.b * rhs.b;
	tmp.reduction();
	return tmp;
}

// умножение //
Fraction operator*(Fraction lhs, Fraction rhs)
{
	Fraction tmp;
	tmp.a = lhs.a * rhs.a;
	tmp.b = lhs.b * rhs.b;
	tmp.reduction();
	return tmp;
}

// деление //
Fraction operator/(Fraction lhs, Fraction rhs)
{
	Fraction tmp;
	void chek_zero(rhs.a);
	tmp.a = lhs.a * rhs.b;
	tmp.b = lhs.b * rhs.a;
	tmp.reduction();
	return tmp;
}

Fraction::~Fraction()
{
}

// равенство дробей //
bool Fraction::operator==(Fraction rhs) 
{
	return this->a * rhs.b == this->b * rhs.a;
}

// не равенство дробей //
bool Fraction::operator!=(Fraction rhs)
{
	return !(this->a * rhs.b == this->b * rhs.a);
}

// сравнение "больше" //
bool Fraction::operator>(Fraction rhs)
{
	return this->a * rhs.b - this->b * rhs.a > 0;
}

// сравнение "меньше" //
bool Fraction::operator<(Fraction rhs)
{
	return this->a * rhs.b - this->b * rhs.a < 0;
}

// приведение дроби к double //
Fraction Fraction::operator()(Fraction other)
{
	Fraction tmp;
	tmp.a = static_cast<double> (other.a);
	tmp.b = static_cast<double> (other.b);
	return tmp;
}

// префиксный инкремент //
Fraction& operator++(Fraction& rhs) 
{
	rhs.a = rhs.a + rhs.b;
	return rhs;
}

// постфиксный декремент //
Fraction Fraction::operator--() 
{
	Fraction rhs = *this;
	this->a = this->a - this->b;
	return rhs;
}