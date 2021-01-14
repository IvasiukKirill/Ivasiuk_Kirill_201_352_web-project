#include <iostream>
#include <set>
using namespace std;

struct Answer
{
	int id;
	string answ;
};

static bool operator<(const Answer a1, const Answer a2)
{
	return a1.id < a2.id;
}

int main()
{
	set<Answer> s1 = set<Answer>();

	Answer a1 = { 1, "sss" };
	Answer a2 = { 2, "ddd" };
	Answer a3 = { 3, "aaa" };
	Answer a4 = { 4, "fff" };
	Answer a5 = { 5, "qqq" };


	s1.insert(a1);
	s1.insert(a5);
	s1.insert(a3);
	s1.insert(a2);
	s1.insert(a4);
	s1.insert(a2);
	s1.insert(a3);

	for (auto i : s1)
	{
		cout << i.answ << endl;
	}

}