
#include <iostream>
#include "matr.h"




int main()
{

    matr matrA, matrB;
    matrA.input();
    matrB.input();

    std::cout << "A=\n";
    matrA.print();
    std::cout << "B=\n";
    matrB.print();

    //Количество строк:
    matrA.get_rows();
    //Количество столбцов:
    matrA.get_cols();


    //Произведение матриц А и В =
    matrA.mult(&matrB);
    matrA.print();

    //Сумма матриц А и В =
    matrA.sum(&matrB);
    std::cout << "matrА + matrB";
    matrA.print();

}