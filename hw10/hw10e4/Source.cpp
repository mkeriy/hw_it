#include <iostream>

class Figure_with_virtual
{
public:
	virtual void print() = 0;
	~Figure_with_virtual() = default;
};

class Circle_virtual : public Figure_with_virtual

{
public:
	Circle_virtual(int r) :
		radius(r) {}

	virtual void print()
	{
		std::cout << radius << std::endl;
	}

	~Circle_virtual() = default;

private:
	double radius;
};


template <typename T>
class Figure
{
public:
	void print()
	{
		self()->m_print();
	}

	virtual ~Figure() = default;
private:
	T* self()
	{
		return static_cast<T*>(this);
	}
};

class Circle : public Figure<Circle>
{

public:
	void m_print()
	{
		std::cout << m_value << std::endl;
	}


	Circle(int new_value) :
		m_value(new_value) {}

	virtual ~Circle() = default;
private:
	int m_value;
};



int main()
{
	Circle c(220);

	c.print();

	Figure_with_virtual* v = new Circle_virtual(1);

	v->print();

	delete v;
	return 0;
}