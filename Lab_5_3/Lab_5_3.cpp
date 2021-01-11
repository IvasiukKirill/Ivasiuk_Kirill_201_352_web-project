#include <iostream>
#include "Matrix.h"
int main()
{
	Matrix m1(2, 2);
	std::cout << "vvod: ";
	m1.input();
	m1.operator+(m1).print();
	{
		std::cout << std::endl;
	}
	(-m1).print();
	{
		std::cout << std::endl;
	}
	Matrix m2(2, 2);
	m2.input();
	{
		std::cout << std::endl;
	}
	Matrix m3(2, 2);
	m3.input();
	{
		std::cout << std::endl;
	}
	Matrix m4 = m2 + m3;
	m4.print();
	{
		std::cout << std::endl;
	}
	Matrix m5 = m2 - m3;
	m5.print();
	{
		std::cout << std::endl;
	}
	Matrix m6 = m1 * 3;
	m6.print();
	{
		std::cout << std::endl;
	}
	m1.operator<<(m1);
	{
		std::cout << std::endl;
	}
	m6.operator>>(m6);
	{
		std::cout << std::endl;
	}

}