#include <cstring>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


bool palindrom(char* str, int size)
{
    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        while (str[j] == '\0')
        {
            if (str[j] == '\0')
                j--;
        }

        if (str[i] == ' ')
            i++;

        if (str[j] == ' ')
            j--;

        if (str[i] <= 90)
            str[i] += 32;

        if (str[j] <= 90)
            str[j] += 32;

        if (str[i] != str[j])
            return false;
    }
    return true;
}

int searh(char* str, int size, char* substr, int len, int* arr)
{
    int s = 0;
    for (int i = 0, j = 0; i < size; i++)
    {
        if (str[i] == '\0')
            break;
        while (substr[len] < 0 || substr[len]>126 || substr[len] == '\0')
        {
            len--;
        }
        len++;
        if (str[i] == substr[j])
            for (int j = 0; j <= len; j++)
            {
                if (substr[j] == '\0')
                {
                    arr[s] = i;
                    s++;
                }
                if (substr[j] != str[i + j])
                {
                    break;
                }

            }
    }
    return s;
}

void Salat(char* str, int size)
{
    cout << "Введите переменную: ";
    int p = 0;
    cin >> p;
    for (int i = 0; i < size; i++)
    {
        if (str[i] == '\0')
            break;
        str[i] += p;
    }
}


char* Quotes(char* str, int size, char* Array)
{
    for (int i = 0, h = 0; i <= size; i++)
    {
        if (str[i] == '\0')
            break;
        if (str[i] == '\"')
        {
            i++;
            while (str[i] != '\"' && str[i] != '\0')
            {
                Array[h] = str[i];
                i++;
                h++;
            }
            Array[h++] = ' ';
        }
    }
    return 0;
}

void Task1(char* str, int size)
{
    getchar();
    cin.getline(str, size);
    if (palindrom(str, size))
        cout << "Это палиндром" << endl;
    else
        cout << "Это не палиндром" << endl;
}

void Task2(char* str, int size, char* substr, int len, int* arr)
{
    getchar();
    cin.getline(str, size);
    cin.getline(substr, len);
    int s = searh(str, size, substr, len, arr);
    for (int i = 0; i < s; i++)
        cout << arr[i] << endl;
}

void Task3(char* str, int size)
{
    getchar();
    cin.getline(str, size);
    Salat(str, size);
    cout << str << endl;

}
void Task4(char* str, int size, char* Array)
{
    getchar();
    cin.getline(str, size);
    Quotes(str, size, Array);
    cout << Array << endl;
}

int main()
{
    const int size = 255;
    char str[size] = "";
    const int len = 255;
    char substr[len] = "";
    int arr[255] = { 0 };
    char Array[size] = "";

    while (true)
    {
        setlocale(LC_ALL, "Russian");
        int input;

        cout << "1. Проверка на палиндром" << endl;
        cout << "2. Поиск подстроки в строке" << endl;
        cout << "3. Шифр Цезаря" << endl;
        cout << "4. Текст внутри кавычек" << endl;
        cout << "5. Выход" << endl;
        cout << "Выбор: ";
        cin >> input;
        switch (input) {
        case 1:
            Task1(str, size);
            break;
        case 2:
            Task2(str, size, substr, len, arr);
            break;
        case 3:
            Task3(str, size);
            break;
        case 4:
            Task4(str, size, Array);
            break;
        case 5:
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
