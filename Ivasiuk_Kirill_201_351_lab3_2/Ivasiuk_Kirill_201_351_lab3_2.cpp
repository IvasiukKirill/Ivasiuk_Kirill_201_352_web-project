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


void PrintArr(int* Arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i] << "  ";
    }
    cout << endl;
}


void Task3(int* Arr, int size, int* Buf)
{
    for (int i = 0; i < size; i++)
    {
        Buf[i] = count(Arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (Buf[j] > Buf[j + 1])
            {
                swap(Buf[j], Buf[j + 1]);
                swap(Arr[j], Arr[j + 1]);
            }
        }
    }
    PrintArr(Arr, size);
}

int Task4(int* Arr, int size, int* Buf)
{
    for (int i = 0; i < size; i++)
    {
        Buf[i] = Arr[i] % 10;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (Buf[j] > Buf[j + 1])
            {
                swap(Buf[j], Buf[j + 1]);
                swap(Arr[j], Arr[j + 1]);
            }
            else if (Buf[j] == Buf[j + 1])
                if (Arr[j] < Arr[j + 1])
                {
                    swap(Buf[j], Buf[j + 1]);
                    swap(Arr[j], Arr[j + 1]);
                }
        }
    }
    PrintArr(Arr, size);
    return 0;
}

int main()
{
    int input;
    int* Arr = nullptr;//nullptr ссылка на нулевое значение
    int size = 0;
    int* Buf = nullptr;
    while (true)
    {
        setlocale(LC_ALL, "Russian");

        cout << "1. Ввод массива" << endl;
        cout << "2. Вывод массива" << endl;
        cout << "3. Отсортировать массив по сумме цифр, стоящих на четных местах" << endl;
        cout << "4. Отсортировать массив вначале по возрастанию последней цифры, а при совпадении последнх цифр - по убыванию" << endl;
        cout << "5. Выход" << endl;
        cout << "Выбор: ";
        cin >> input;
        switch (input) {
        case 1:
            IntArr(Arr, &size, Buf);
            break;
        case 2:
            PrintArr(Arr, size);
            break;
        case 3:
            Task3(Arr, size, Buf);
            break;
        case 4:
            Task4(Arr, size, Buf);
            break;
        case 5:
            cout << "Good bye!";
            delete[] Arr;
            delete[] Buf;
            return 0;
            break;
        default:
            cout << "Неверно выбрана цифра" << endl;
            break;
        }
    }
    return 0;
}