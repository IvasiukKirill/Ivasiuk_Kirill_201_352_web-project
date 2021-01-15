#include <iostream> // <Surname, Name, Age>
#include <vector>
#include <iterator>
using namespace std;

struct MyStruct
{
    string Surname;
    string Name;
    int Age;
};


void Sort(int flag, vector<MyStruct>& arr, int first, int last)
{
    if (flag == 1)//Surname
    {
        vector<MyStruct> mid{ {"0","0",0} };
        vector<MyStruct> count{ {"0","0",0} };
        int f = first, l = last;
        mid[0].Surname = arr[(f + l) / 2].Surname; //вычисление опорного элемента
        do
        {
            while (arr[f].Surname < mid[0].Surname) f++;
            while (arr[l].Surname > mid[0].Surname) l--;
            if (f <= l) //перестановка элементов
            {
                count[0] = arr[f];
                arr[f] = arr[l];
                arr[l] = count[0];
                f++;
                l--;
            }
        } while (f < l);
        if (first < l) Sort(1, arr, first, l);
        if (f < last) Sort(1, arr, f, last);
    }
    if (flag == 2)//Name
    {
        vector<MyStruct> mid{ {"0","0",0} };
        vector<MyStruct> count{ {"0","0",0} };
        int f = first, l = last;
        mid[0].Name = arr[(f + l) / 2].Name; //вычисление опорного элемента
        do
        {
            while (arr[f].Name < mid[0].Name) f++;
            while (arr[l].Name > mid[0].Name) l--;
            if (f <= l) //перестановка элементов
            {
                count[0] = arr[f];
                arr[f] = arr[l];
                arr[l] = count[0];
                f++;
                l--;
            }
        } while (f < l);
        if (first < l) Sort(2, arr, first, l);
        if (f < last) Sort(2, arr, f, last);
    }
    if (flag == 3)//Age
    {
        vector<MyStruct> mid{ {"0","0",0} };
        vector<MyStruct> count{ {"0","0",0} };
        int f = first, l = last;
        mid[0].Age = arr[(f + l) / 2].Age; //вычисление опорного элемента
        do
        {
            while (arr[f].Age < mid[0].Age) f++;
            while (arr[l].Age > mid[0].Age) l--;
            if (f <= l) //перестановка элементов
            {
                count[0] = arr[f];
                arr[f] = arr[l];
                arr[l] = count[0];
                f++;
                l--;
            }
        } while (f < l);
        if (first < l) Sort(3, arr, first, l);
        if (f < last) Sort(3, arr, f, last);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    vector<MyStruct> arr{ {"Пушкин    ", "Александр  ", 67},{"Иванько   ", "Иван     ", 11},{"Леоньтев  ", "Петя     ", 15},{"Толстой   ", "Лев      ", 5},{"Ивасюк  ", "Кирилл   ",18} };
    int flag;
    cout << "1-Surname, 2-Name, 3-Age" << endl << "Введите номер: ";
    cin >> flag;
    Sort(flag, arr, 0, 4);
    for (auto e : arr)
        cout << e.Surname << " " << e.Name << " " << e.Age << " " << endl;

}






