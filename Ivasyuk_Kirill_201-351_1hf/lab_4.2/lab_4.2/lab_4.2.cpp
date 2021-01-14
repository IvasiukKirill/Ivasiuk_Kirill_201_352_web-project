#include <iostream>
#include <string>
#include <fstream>



using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;
using std::ofstream;


string Expansion(string fullPath)
{
    return fullPath.substr(fullPath.find_last_of('.'));
}


string Name(string fullPath)
{
    return fullPath.substr(fullPath.find_last_of('\\') + 1, fullPath.find_last_of('.') - fullPath.find_last_of('\\') - 1);
}


string Location(string fullPath)
{
    return fullPath.substr(0, fullPath.find_last_of('\\'));
}

char NameDisk(string fullPath)
{
    return fullPath[0];
}

bool Rename(string fullPath, string NewName)
{
    fullPath.replace(fullPath.find_last_of('\\') + 1, string::npos, NewName);
    cout << fullPath << endl;
    return 0;
}

bool Copy(string fullPath)
{
    string path_copy = fullPath;
    ifstream file(fullPath, ifstream::in);
    if (file.is_open())
    {
        ofstream copy;
        copy.open(path_copy.replace(path_copy.find('.'), 4, "_copy.txt"), ofstream::out | ofstream::app);
        string buf;
        getline(file, buf);
        copy << buf;
        copy.close();
        return true;
    }
    else
    {
        cout << "Файл не открылся!" << '\n';
        return false;
    }
}





// E:/Лабы/Ivasyuk_Kirill_201-351_1hf/lab_4.2/file.txt
void Task1(string fullPath)
{
    getchar();
    getline(cin, fullPath);
    cout << Expansion(fullPath) << endl;
}



void Task2(string fullPath)
{
    getchar();
    getline(cin, fullPath);
    cout << Name(fullPath) << endl;
}


void Task3(string fullPath)
{
    getchar();
    getline(cin, fullPath);
    cout << Location(fullPath) << endl;
}


void Task4(string fullPath)
{
    getchar();
    getline(cin, fullPath);
    cout << NameDisk(fullPath) << endl;
}

void Task5(string fullPath, string NewName)
{
    getchar();
    getline(cin, fullPath);
    cout << "Введите новое имя файла: ";
    getline(cin, NewName);
    Rename(fullPath, NewName);
    cout << "Имя файла изменено" << endl;
}

void Task6(string fullPath)
{
    getchar();
    getline(cin, fullPath);
    cout << Copy(fullPath) << endl;
}



int main()
{

    string fullPath;
    string NewName;


    while (true)
    {
        setlocale(LC_ALL, "Russian");
        

        int input;

        cout << "1. Расширение файла" << endl;
        cout << "2. Имя файла" << endl;
        cout << "3. Расположение файла" << endl;
        cout << "4. Диск, на котором лежит файл" << endl;
        cout << "5. Переименовать файл" << endl;
        cout << "6. Создание копии файла" << endl;
        cout << "Выбор: ";
        cin >> input;
        switch (input) {
        case 1:
            Task1(fullPath);
            break;
        case 2:
            Task2(fullPath);
            break;
        case 3:
            Task3(fullPath);
            break;
        case 4:
            Task4(fullPath);
            break;
        case 5:
            Task5(fullPath, NewName);
            break;
        case 6:
            Task6(fullPath);
            break;
        case 7:
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