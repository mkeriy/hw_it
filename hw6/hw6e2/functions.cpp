#include <iostream>
#include "Header.hpp"

Fraction operator+(const Fraction &f1, const Fraction &f2)
{
	return Fraction(f1.m_numerator*f2.m_deminator + f2.m_numerator*f1.m_deminator, f1.m_deminator*f2.m_deminator);
}

Fraction operator+(int value, const Fraction &f2)
{
	return Fraction(value*f2.m_deminator + f2.m_numerator, f2.m_deminator);
}

Fraction operator+(const Fraction &f1, int value)
{
		return Fraction(f1.m_numerator+value*f1.m_deminator, f1.m_deminator);
}

void Fraction::operator+=(const Fraction & f2)
{
	*this = Fraction(m_numerator * f2.m_deminator + f2.m_numerator * m_deminator, m_deminator * f2.m_deminator);
}

Fraction operator-(const Fraction &f1, const Fraction &f2)
{
	return Fraction(f1.m_numerator*f2.m_deminator - f2.m_numerator*f1.m_deminator, f1.m_deminator*f2.m_deminator);
}

Fraction operator-(const Fraction &f1, int value)
{
	return Fraction(f1.m_numerator - value*f1.m_deminator, f1.m_deminator);
}

Fraction operator-(int value, const Fraction &f2)
{
	return Fraction( value*f2.m_deminator + f2.m_numerator, f2.m_deminator);
}

void Fraction::operator-=(const Fraction & f2)
{
	*this = Fraction(m_numerator*f2.m_deminator - f2.m_numerator*m_deminator, m_deminator*f2.m_deminator);
}
Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	return Fraction(f1.m_numerator*f2.m_numerator, f1.m_deminator*f2.m_deminator);
}

Fraction operator*(const Fraction &f1, int value)
{
	return Fraction(f1.m_numerator*value, f1.m_deminator);
}

Fraction operator*(int value, const Fraction &f2)
{
	return Fraction(value*f2.m_numerator, f2.m_deminator);
}

void Fraction::operator*=(const Fraction & f2)
{
	*this = Fraction(m_numerator*f2.m_numerator, m_deminator*f2.m_deminator);
}

Fraction operator/(const Fraction & f1, const Fraction & f2)
{
	return Fraction(f1.m_numerator*f2.m_deminator, f1.m_deminator*f2.m_numerator);
}

Fraction operator/(const Fraction & f1, int value)
{
	return Fraction(f1.m_numerator, f1.m_deminator*value);
}

Fraction operator/(int value, const Fraction & f2)
{
	return Fraction(value*f2.m_deminator, f2.m_numerator);
}

void Fraction::operator/=(const Fraction & f2)
{
	*this = Fraction(m_numerator*f2.m_deminator, m_deminator*f2.m_numerator);
}
bool operator==(const Fraction & f1, const Fraction & f2)
{
	return (f1.m_numerator == f2.m_numerator && f1.m_deminator == f2.m_deminator);
}
bool operator<=(const Fraction & f1, const Fraction & f2)
{
	return (f1.m_numerator <= f2.m_numerator && f1.m_deminator <= f2.m_deminator);
}
bool operator>=(const Fraction & f1, const Fraction & f2)
{
	return (f1.m_numerator >= f2.m_numerator && f1.m_deminator >= f2.m_deminator);
}
bool operator!=(const Fraction & f1, const Fraction & f2)
{
	return (f1.m_numerator != f2.m_numerator || f1.m_deminator != f2.m_deminator);
}
bool operator>(const Fraction & f1, const Fraction & f2)
{
	return (f1.m_numerator > f2.m_numerator && f1.m_deminator > f2.m_deminator);
}
bool operator<(const Fraction & f1, const Fraction & f2)
{
	return (f1.m_numerator < f2.m_numerator && f1.m_deminator < f2.m_deminator);
}

Fraction& Fraction::operator++()
{
	m_numerator += m_deminator;
	return *this;
}

Fraction& Fraction::operator--()
{
	m_numerator += m_deminator;
	return *this;
}

Fraction Fraction::operator++(int)
{
	m_numerator += m_deminator;
		return *this;
}

Fraction Fraction::operator--(int)
{
	m_numerator -= m_deminator;
	return *this;
}
void Fraction::reduction()
{
	int nod = Fraction::nod(m_numerator, m_deminator);
	m_numerator /= nod;
	m_deminator /= nod;
}

void Fraction::print()
{
	std::cout << m_numerator << "/" << m_deminator << std::endl;
}
void Fraction::input()
{
	std::cin >> m_numerator;
	std::cout << "/";
	std::cin >> m_deminator;
	std::cout << std::endl;
}

double Fraction::toDouble()
{
	double result = static_cast <double> (m_numerator)/m_deminator;
	return result;
}

