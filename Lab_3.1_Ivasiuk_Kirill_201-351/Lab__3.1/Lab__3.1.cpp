#include <iostream>
using namespace std;

const size_t length = 1000; 
/* объявление глобальной переменной,
Тип size_t применяется для счетчиков циклов, индексации массивов,
хранения размеров, адресной арифметики
*/

void BoubleSort(int *arr, const size_t length) 
{
    for (int i = 0; i < length; i++) 
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) 
            {
                int buff = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = buff;
            }
        }
    }
}

template < typename T > 
/* шаблон типа
Ключевое слово typename говорит о том, 
что в шаблоне будет использоваться встроенный
тип данных, такой как: int, double, float, char и т. д.
*/

void PrintArray(T *arr, const size_t n)
{
    for (int i = length - n; i < length; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void CountSort(char* arr, const size_t length)
{
    const int k = 26;
    int counter[k] = { 0 };
    for (int i = 0; i < length; i++)
    {
        counter[int(arr[i] - 'a')]++;
    }
    int pos = 0;
    int j = 0;
    while (j <= k) {
        if (counter[j] > 0)
        {
            arr[pos] = char(int('a') + j);
            pos++;
            counter[j]--;
        }
        else 
        {
            j++;
        }
    }
}

void Merge(int *arr,  int left,  int mid,  int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int up[length / 2], down[length - length / 2];

    for (int i = 0; i < size1; i++) 
    {
        up[i] = arr[left + i];
    }
    for (int i = 0; i < size2; i++) 
    {
        down[i] = arr[mid + i + 1];
    }

    int i = 0,j = 0,k = left;

    while (i < size1 && j < size2) 
    {
        if (up[i] <= down[j]) 
        {
            arr[k] = up[i];
            i++;
        }
        else 
        {
            arr[k] = down[j];
            j++;
        }
        k++;
    }

    while (i < size1)
    {
        arr[k] = up[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        arr[k] = down[j];
        j++;
        k++;
    }
}

void MergeSort(int *arr, const int left, const int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid); // cортировка первой части
        MergeSort(arr, mid + 1, right); //второй

        Merge(arr, left, mid, right);// слияние частей
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    while (true) 
    {
        int number;
        cout << "Выберите команду:\n"
            << "1.Сортировка пузырьком\n"
            << "2.Сортировка подсчетом\n"
            << "3.Сортировка слиянием\n"
            << "4.Выход\n";
        cin >> number;


        if (number == 1)
        {
            int n = 0;
            cout << "Размер массива: ";
            cin >> n;

            int arr[length] = { 0 };
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }

            BoubleSort(arr, length);
            PrintArray(arr, n);
        }

        if (number == 2) {
            int n = 0;
            cout << "Размер массива: ";
            cin >> n;

            char arr[length] = { ' ' };
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }

            CountSort(arr, length);
            PrintArray(arr, n);
        }

        if (number == 3)
        {
            int n = 0;
            cout << "Размер массива: ";
            cin >> n;

            int arr[length] = { 0 };
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }

            MergeSort(arr, 0, length - 1);
            PrintArray(arr, n);
        }

        if (number == 4)
        {
            return 0;
        }
    }
}