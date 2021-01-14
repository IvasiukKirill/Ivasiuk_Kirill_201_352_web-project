#include <iostream>
#include "Matrix.h"
using std::cout;
using std::cin;
using std::endl;


int main()
{

    Matrix m2(3, 3);
    m2.input();
    m2.print();
    {
        std::cout << std::endl;
    }
    Matrix m3(3, 3);
    m3.input();
    m3.print();
    {
        std::cout << std::endl;
    }
    Matrix m4 = m2 - m3;
    m4.print();
    {
        std::cout << std::endl;
    }

}