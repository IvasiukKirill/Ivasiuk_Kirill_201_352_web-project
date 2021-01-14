#include <iostream>
#include "Matrix1.h"
using std::cout;
using std::cin;
using std::endl;


int main()
{

    Matrix1 m2(3, 3);
    m2.input();
    m2.print();
    {
        std::cout << std::endl;
    }
    Matrix1 m3(3, 3);
    m3.input();
    m3.print();
    {
        std::cout << std::endl;
    }
    Matrix1 m4 = m2 - m3;
    m4.print();
    {
        std::cout << std::endl;
    }

}