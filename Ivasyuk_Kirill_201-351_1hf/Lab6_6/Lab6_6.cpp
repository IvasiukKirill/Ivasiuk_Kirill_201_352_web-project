
#include <iostream>
#include <map>

using namespace std;

int main()
{
    
    map<string, int> m1 = map<string, int>();//то ассоциативный контейнер, который работает по принципу —[ключ — значение].
    //string этот тип данных будет относиться к значению ключа.
    //int  этот тип данных соответственно относится к значению.
    string n;
    bool key = true;
    while (key) 
    {
        cin >> n;
        if (n != "32")
            m1[n]++;
        else key = false;
    }
    
    int sum = 0;
    for (auto i : m1)
    {
        sum += i.second;
    }
    cout << "Sum:" << sum << endl;
    for (auto i : m1)
    {
        cout << i.first << ": " << (float)i.second / sum * 100 << "%" << endl;
    }
}