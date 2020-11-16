#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Header.hpp"

std::ostream& operator<< (std::ostream& out, const Fraction& drob)
{
	out << drob.a << '/' << drob.b;
	return out;
}

std::istream& operator>> (std::istream& in, Fraction& drob)
{
	in >> drob.a >> drob.b;
	return in;
}

using namespace std;

int main() {

	setlocale(LC_ALL, "ru");

	Fraction frac_1;
	Fraction frac_2;
	int a, b;

	cout << "Введите числитель первой дроби ";
	cin >> a;
	frac_1.set_a(a);

	cout << "Введите знаменатель первой дроби ";
	cin >> b;
	frac_1.set_b(b);

	cout << "Введите числитель второй дроби ";
	cin >> a;
	frac_2.set_a(a);

	cout << "Введите знаменатель второй дроби ";
	cin >> b;
	frac_2.set_b(b);

	Fraction sum = frac_1 + frac_2;
	Fraction dif = frac_1 - frac_2;
	Fraction mult = frac_1 * frac_2;
	Fraction div = frac_1 / frac_2;
	Fraction pre_inc = ++frac_1;
	Fraction post_dec = frac_2--;
	cout << "Сумма " << sum << endl;
	cout << "Разность " << dif << endl;
	cout << "Произведение " << mult << endl;
	cout << "Частное " << div << endl;
	cout << "Рещультат инкремента" << pre_inc << endl;
	cout << "Результат декремента " << post_dec << " и frac_2 =  " << frac_2 << endl;
	bool who = frac_1 < frac_2;
	cout << "Результат сравнения " << who << endl;

	system("pause");
	return EXIT_SUCCESS;
}