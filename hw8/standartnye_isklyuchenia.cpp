#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <typeinfo>

void size(int value_1);
void array(int* arr);
void logic(int side);
void data_type(int d); // она просто есть


int main()
{
	setlocale(LC_ALL, "Russian");
	int value_1 = 18;
	unsigned int side = 1;
	unsigned int const size_arr = 2;
	int arr[size_arr];

	try
	{
		array(arr);
	}
	catch (const std::out_of_range& exception)
	{
		std::cerr << "Ошибка: " << exception.what() << '\n';
	}


	try
	{
		size(value_1);
	}
	catch (const std::range_error& exception)
	{
		std::cerr << "Ошибка: " << exception.what() << '\n';
	}


	try
	{
		logic(side);
	}
	catch (const std::logic_error& exception)
	{
		std::cerr << "Ошибка: " << exception.what() << '\n';
	}


	try //
	{
		std::string line = "I will miss the next lesson";
		throw(std::invalid_argument("Несогласованность типов данных")); 
	}
	catch (const std::invalid_argument& exception)
	{
		{
			std::cerr << "Ошибка: " << exception.what() << '\n';
		}
	}


	try
	{
		std::string next_line = "line";
		if (next_line.length() > 2)
			throw(std::length_error("Превышение длины строки"));
	}
	catch (std::length_error& exception)
	{
		std::cerr << "Ошибка: " << exception.what() << '\n';
	}

	system("pause");
	return 0;
}

void array(int* arr)
{
	for (int i = 0U; i < 6; ++i)
	{
		if (i > 4)
			throw std::out_of_range("Выход за пределы массива");
		arr[i] = 1;
	}
}

void size(int value_1)
{
	if (value_1 > 16)
		throw(std::range_error("Вы ввели число, которое превосходит максимальное значение в диапазоне"));
	 int value_2 = value_1;
}

void logic(int side)
{
	int hypotenuse = side; //в результате каких-то преобразований
	if (hypotenuse = side)
		throw(std::logic_error("Энергия не может быть равна силе"));
}

void data_type(int d) {};