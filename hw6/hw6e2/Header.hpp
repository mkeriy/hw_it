#pragma once
class Fraction
{
	private:
	int m_numerator;
	int m_deminator;

	public:
	Fraction(int numerator, int deminator):
		m_numerator(numerator), m_deminator(deminator)
	{}
	~Fraction(){}

	static int nod(int a, int b)
	{
		return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
	}
	void reduction();
	void print();
	void input();
	double toDouble();

	friend Fraction operator+(const Fraction & f1, const Fraction & f2);
	friend Fraction operator+(int value, const Fraction & f2);
	friend Fraction operator+(const Fraction & f1, int value);
	friend Fraction operator+=(const Fraction & f1, const Fraction & f2);
	friend Fraction operator-(const Fraction & f1, const Fraction & f2);
	friend Fraction operator-(const Fraction & f1, int value);
	friend Fraction operator-(int value, const Fraction & f2);
	friend Fraction operator-=(const Fraction & f1, const Fraction & f2);
	friend Fraction operator*(const Fraction & f1, const Fraction & f2);
	friend Fraction operator*(const Fraction & f1, int value);
	friend Fraction operator*(int value, const Fraction & f2);
	friend Fraction operator*=(const Fraction & f1, const Fraction & f2);
	friend Fraction operator/(const Fraction & f1, const Fraction & f2);
	friend Fraction operator/(const Fraction & f1, int value);
	friend Fraction operator/(int value, const Fraction & f2);
	friend Fraction operator/=(const Fraction & f1, const Fraction & f2);
	friend bool operator==(const Fraction & f1, const Fraction & f2);
	friend bool operator<=(const Fraction & f1, const Fraction & f2);
	friend bool operator>=(const Fraction & f1, const Fraction & f2);
	friend bool operator!=(const Fraction & f1, const Fraction & f2);
	friend bool operator>(const Fraction & f1, const Fraction & f2);
	friend bool operator<(const Fraction & f1, const Fraction & f2);

    Fraction& operator++();
    Fraction& operator--();
    Fraction operator++(int);
    Fraction operator--(int);

};
