#pragma once
#include <iostream>


class Fraction
{
public:
	Fraction();
	Fraction(int a_, std::size_t b_);
	Fraction(double a_, double b_);

	inline int get_a() const { return a; };
	inline void set_a(int a_) { a = a_; };

	inline int get_b() const { return b; };
	inline void set_b(int b_) { b = b_; };


	friend Fraction operator+(Fraction, Fraction);		//сложение
	friend Fraction operator-(Fraction, Fraction);		//вычитание
	friend Fraction operator*(Fraction, Fraction);		//умножение
	friend Fraction operator/(Fraction, Fraction);		//деление
	Fraction operator()(Fraction);						//приведение дроби к double
	Fraction operator--();								// постфиксный декремент
	friend Fraction& operator++(Fraction&);				// префиксный инкремент


	int GSD();											//нахождение наибольшего общего делителя
	void reduction();									//сокрaщение дроби
	void chek_zero();									//проверка равенства нулю


	bool operator==(Fraction rhs);						//равенство дробей 
	bool operator!=(Fraction rhs);						//не равенство дробей 
	bool operator<(Fraction rhs);						//сравнение "больше" 
	bool operator>(Fraction rhs);						//сравнение "меньше"




	// вывод дроби//
	friend std::ostream& operator<< (std::ostream& out, const Fraction& drob);
	friend std::istream& operator>> (std::istream& in, Fraction& drob);
	~Fraction();

private:
	int a;
	std::size_t b;
};



