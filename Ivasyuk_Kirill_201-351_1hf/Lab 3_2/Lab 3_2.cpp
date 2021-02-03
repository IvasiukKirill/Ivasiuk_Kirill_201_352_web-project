#include <iostream>

using namespace std;


void IntArr(int*& Arr, int* size, int*& Buf)//"&" унарная операция взятия адреса &. Такая операция извлекает адрес объявленных переменных, для того, чтобы его присвоить указателю.
{
    cout << "Введите кол-во элементов массива:";
    cin >> *size;
    Arr = new int[*size];// выделение памяти под динамический массив
    Buf = new int[*size];
    cout << "Введите " << *size << " элементов" << endl;

    for (int i = 0; i < *size; i++)
    {

        cin >> Arr[i];
    }
    cout << "\n";
}

int count(int n)
{
    int ch = 0;
    int nch = 0;
    int k = 0;
    int s = 0;
    while (n)
    {
        k++;
        if (!(k % 2))
            ch += n % 10;
        else
            nch += n % 10;
        n /= 10;
    }
    if (!(k % 2))
        s = nch;
    else
        s = ch;
    return s;
}
