#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int size;
    cout << " Введите размер массива ";
    cin >> size;
    int* A = new int[size];
    int* B = new int[size];
    int* C = new int[size];
    int sum = 0;
    int G;
    while (true)
    {
        int choice;
        cout << "1.Изменение размера массива\n";
        cout << "2.Ввод массива\n";
        cout << "3.Вывод массива в консоль \n";
        cout << "4.Сортировка по сумме цифр, стоящих на четных местах\n";
        cout << "5.Отсортировать массив вначале по возрастанию последней цифры, а при совпадении последних цифр - по убыванию\n";
        cout << "6.Выход\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            size = 0;
            cout << "Введите размер массива ";
            cin >> size;
            break;
        case 2:
            for (int i = 0; i < size; i++)
            {
                cout << "Введите A[" << i << "] ";
                cin >> A[i];
                B[i] = A[i];
                C[i] = A[i];
            }
            break;

        case 3:
            for (int i = 0; i < size; i++) cout << A[i] << " ";
            cout << endl;
            break;
        case 4:
            for (int i = 0; i < size; i++)
            {
                while (B[i] > 0) 
                {
                    sum += B[i] % 10;
                    B[i] = B[i] / 10;
                }
                B[i] = sum;
                sum = 0;
            }
            for (int i = 0; i < size - 1; i++) 
            {
                for (int j = 0; j < size - i - 1; j++) 
                {
                    if (B[j] > B[j + 1]) 
                    {
                        G = B[j];
                        B[j] = B[j + 1];
                        B[j + 1] = G;
                    }
                }
            }
            for (int i = 0; i < size; i++)
            {
                if (i % 2 == 0) 
                {
                    cout << B[i] << " ";
                }
            }
            cout << endl;
            for (int i = 0; i < size; i++) B[i] = A[i];
            break;
        case 5:
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (C[j] % 10 > C[j + 1] % 10) {
                        G = C[j];
                        C[j] = C[j + 1];
                        C[j + 1] = G;
                    }
                }
            }
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (C[j] % 10 == C[j + 1] % 10) {
                        if (C[j] < C[j + 1]) {
                            G = C[j];
                            C[j] = C[j + 1];
                            C[j + 1] = G;
                        }
                    }
                }
            }
            for (int i = 0; i < size; i++) cout << C[i] << " ";
            cout << endl;
            break;
        case 6:
            delete[] A;
            delete[] B;
            delete[] C;
            return 0;
            break;
        default:
            break;
        }
    }


}
