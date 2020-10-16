#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::swap;


void PrintArr(int* a, int n)
{
    cout << "Массив в отсортированном виде: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;
}


void PrintArr(char* a, int n)
{
    cout << "Массив в отсортированном виде: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;
}



void BoubleSort(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}


void CountSort(char* a, int n)
{
    int const Len = 26;
    int Buf[Len] = { 0 };

    int j = 0;

    for (int i = 0; i < n; i++)
    {
        j = int(a[i] - 'a');
        Buf[j]++;
    }
    int i = 0;
    j = 0;
    while (j <= Len) {
        if (Buf[j] > 0) {
            a[i] = char(int('a') + j);
            i++;
            Buf[j]--;
        }
        else {
            j++;
        }
    }
}



void Merge(int arr[], int* d, int begin, int end)
{
    int i = begin;
    int t = 0;
    int sred = begin + (end - begin) / 2;
    int j = sred + 1;

    while (i <= sred && j <= end) {
        if (arr[i] <= arr[j]) {
            d[t] = arr[i];
            i++;
        }
        else {
            d[t] = arr[j];
            j++;
        }
        t++;
    }
    while (i <= sred) {
        d[t] = arr[i]; i++; t++;
    }
    while (j <= end) {
        d[t] = arr[j]; j++; t++;
    }
    for (i = 0; i < t; i++)
        arr[begin + i] = d[i];
}

void MergeSort(int* arr, int* d, int left, int right)
{
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
    int  t;
    if (left < right)
        if (right - left == 1) {
            if (arr[right] < arr[left]) {
                t = arr[left];
                arr[left] = arr[right];
                arr[right] = t;
            }
        }
        else {
            MergeSort(arr, d, left, left + (right - left) / 2);
            MergeSort(arr, d, left + (right - left) / 2 + 1, right);
            Merge(arr, d, left, right);
        }
}








void Task1()
{
    int n;   //Длина массива
    int i = 0;
    int arr[1000];
    cout << "Введите кол-во элементов массива: ";
    cin >> n;
    cout << "Введите " << n << " чисел для заполнения массива: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    BoubleSort(arr, n);
    PrintArr(arr, n);
}


void Task2()
{
    int n;   //Длина массива
    int i = 0;
    char arr[1000] = { 0 };
    cout << "Введите кол-во элементов массива: ";
    cin >> n;
    cout << "Введите " << n << " чисел для заполнения массива: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    CountSort(arr, n);
    PrintArr(arr, n);
}






void Task3()
{

    int n = 0;
    int arr[1000] = { 0 };
    int d[1000] = { 0 };
    cout << "Введите размер массива: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
       cin >> arr[i];
    }
     


      for (int i = 0; i < n; i++)
      {
         cout << arr[i] << "  ";
      }
        cout << endl;
}




int main()
{
    while (true)
    {
        setlocale(LC_ALL, "Russian");
        int input;

        cout << "1. Пузырьковая сортировка" << endl;
        cout << "2. Сортировка подсчетом" << endl;
        cout << "3. Сортировка слиянием" << endl;
        cout << "4. Выход" << endl;
        cout << "Выбор: ";
        cin >> input;
        switch (input) {
        case 1:
            Task1();
            break;
        case 2:
            Task2();
            break;
        case 3:
            Task3();
            break;
        case 4:
            cout << "Good bye!";
            return 0;
            break;
        default:
            cout << "Неверно выбрана цифра" << endl;
            break;
        }
    }
    return 0;
}







