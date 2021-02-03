#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int key = 0;
    ifstream stud_answers;
    ofstream st_answers;
    string mails = "stud_answers.txt";
    stud_answers.open(mails);
    st_answers.open(mails, ofstream::app);
    set<string> answers;
    string opfile;
    while (!stud_answers.eof()) {
        opfile = "";
        getline(stud_answers, opfile);
        answers.insert(opfile);
        key++;
    }
    string name;
    cout << "Для прохождения теста введите майл: ";
    cin >> name;
    if (answers.find(name) != answers.end()) {
        cout << "Ну актер. Ну актереще!!!\n";
    }
    else {
        answers.insert(name);
        cout << "Можете приступить к тесту)\n";
        st_answers << name << endl;
        string Love;
        cout << "Любите C++? Ответ да или нет: ";
        cin >> Love;
        if (Love == "yes") cout << "Молодец)";
        else cout << "Не молодец!";
    }
    return 0;
}