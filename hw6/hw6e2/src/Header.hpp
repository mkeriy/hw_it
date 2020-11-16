#pragma once
class Fraction
{
	public:
	Fraction(int numerator = 0, int deminator = 1):
		m_numerator(numerator), m_deminator(deminator)
	{}
	Fraction(int a):
		m_numerator(a), m_deminator(1){}
	Fraction():
		m_numerator(0), m_deminator(1){}
	Fraction(const Fraction& a) = default;
	Fraction(const int& a) :
		m_numerator(a), m_deminator(1){}

	~Fraction(){}

	friend Fraction operator+(const Fraction & f1, const Fraction & f2);
	void operator+=(const Fraction & f2);
	friend Fraction operator-(const Fraction & f1, const Fraction & f2);
	void operator-=(const Fraction & f2);
	friend Fraction operator*(const Fraction & f1, const Fraction & f2);
	void operator*=(const Fraction & f2);
	friend Fraction operator/(const Fraction & f1, const Fraction & f2);
	void operator/=(const Fraction & f2);


	friend bool operator==(const Fraction & f1, const Fraction & f2);
	friend bool operator<=(const Fraction & f1, const Fraction & f2);
	friend bool operator>=(const Fraction & f1, const Fraction & f2);
	friend bool operator!=(const Fraction & f1, const Fraction & f2);
	friend bool operator>(const Fraction & f1, const Fraction & f2);
	friend bool operator<(const Fraction & f1, const Fraction & f2);


	friend std::ostream & operator<<(std::ostream & out, const Fraction &f);
	friend std::istream & operator>>(std::istream & in, Fraction &f);

	Fraction& operator++();
    Fraction& operator--();
    Fraction operator++(int);
    Fraction operator--(int);
    operator double() const;

	private:
		int m_numerator;
		int m_deminator;
		void reduction();
};
