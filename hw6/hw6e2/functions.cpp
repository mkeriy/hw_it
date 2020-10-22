#include <iostream>
#include <algorithm>

#include "Header.hpp"

Fraction operator+(const Fraction &f1, const Fraction &f2)
{
	Fraction result(f1);
	result += f2;
	result.reduction();
	return result;
}


void Fraction::operator+=(const Fraction & f2)
{
	*this = Fraction(m_numerator * f2.m_deminator + f2.m_numerator * m_deminator, m_deminator * f2.m_deminator);
	reduction();
}

Fraction operator-(const Fraction &f1, const Fraction &f2)
{
		Fraction result(f1);
		result -= f2;
		result.reduction();
		return result;
}

void Fraction::operator-=(const Fraction & f2)
{
	*this = Fraction(m_numerator*f2.m_deminator - f2.m_numerator*m_deminator, m_deminator*f2.m_deminator);
	reduction();
}
Fraction operator*(const Fraction &f1, const Fraction &f2)
{
		Fraction result(f1);
		result *= f2;
		result.reduction();
		return result;
}

void Fraction::operator*=(const Fraction & f2)
{
	*this = Fraction(m_numerator*f2.m_numerator, m_deminator*f2.m_deminator);
}

Fraction operator/(const Fraction & f1, const Fraction & f2)
{
		Fraction result(f1);
		result /= f2;
		result.reduction();
		return result;
}

void Fraction::operator/=(const Fraction & f2)
{
	*this = Fraction(m_numerator*f2.m_deminator, m_deminator*f2.m_numerator);
	reduction();
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
	this->m_numerator += this->m_deminator;
			reduction();
			return *this;
}

Fraction& Fraction::operator--()
{
	this->m_numerator -= this->m_deminator;
			reduction();
			return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction temp(this->m_numerator + this->m_deminator, this->m_deminator);
			return temp;
}

Fraction Fraction::operator--(int)
{
	Fraction temp(this->m_numerator - this->m_deminator, this->m_deminator);
				return temp;
	}
void Fraction::reduction()
{
	int nod = std::__gcd(m_numerator, m_deminator);
	m_numerator /= nod;
	m_deminator /= nod;
}

std::ostream & operator<<(std::ostream & out, const Fraction &f)
{
	out << f.m_numerator << "/" << f.m_deminator;
	return out;
}
std::istream & operator>>(std::istream & in, Fraction &f)
{
	char c;
	in >> f.m_numerator;
	in >> c;
	in >> f.m_deminator;

	f.reduction();
	return in;
}


Fraction::operator double() const {
		return (double)m_numerator / m_deminator;
	}


