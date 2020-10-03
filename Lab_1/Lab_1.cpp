#include <iostream>
#include <limits.h>
#include <bitset>
#include<float.h>

using std::cout;
using std::cin;
using std::endl;
using std::bitset;
using std::hex;


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "1." << std::endl;

	cout << "Ivasiuk Kirill Evgenyevich,201-351" << endl;

	cout << "2. " << endl;

	cout << "min int =" << INT_MIN << ", max_int = " << INT_MAX << ". size of int = " << sizeof(int) << endl;
	cout << "min unsigned int = 0" << ", max unsigned int = " << UINT_MAX << ". size of unsigned int = " << sizeof(unsigned) << endl;
	cout << "min short = " << SHRT_MIN << ", max short = " << SHRT_MAX << ". size of short int = " << sizeof(short) << endl;
	cout << "min unsigned short = 0" << ", max unsigned short = " << USHRT_MAX << ". size of unsigned short int = " << sizeof(unsigned short) << endl;
	cout << "min long long = " << LLONG_MIN << ", max long long= " << LLONG_MAX << ". size of long long = " << sizeof(long long) << endl;
	cout << "min double = " << DBL_MIN << ", max double = " << DBL_MAX << ". size of double = " << sizeof(double) << endl;
	cout << "min char = " << CHAR_MIN << ", max char = " << CHAR_MAX << ". size of char = " << sizeof(char) << endl;
	cout << "min bool = 0" << ", max bool = 1" << ". size of bool = " << sizeof(bool) << endl;


	cout << "3.";

	int number;
	cout << "\nEnter number:";
	cin >> number;
	cout << "\nBinary:" << bitset<16>(number);
	cout << "\nHex:" << hex << number << endl;
	cout << "Boolean: " << bool(number) << endl;
	cout << "Char: " << char(number) << endl;

	cout << "4.";

	float a, b;
	cout << "\nEnter coeff a * x = b" << endl;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << a << "*x = " << b << endl;
	cout << "x = " << b << "/" << a << endl;
	cout << "x = " << b / a << endl;

	cout << "5.";

	float x1, x2;
	cout << "\nВведите координаты отрезка на прямой:" << endl;
	cout << "x1:";
	cin >> x1;
	cout << "x2:";
	cin >> x2;
	cout << "\nСередина отрезка находится в точке с координатой " << (x1 + x2) / 2 << endl;
	return 0;

}
