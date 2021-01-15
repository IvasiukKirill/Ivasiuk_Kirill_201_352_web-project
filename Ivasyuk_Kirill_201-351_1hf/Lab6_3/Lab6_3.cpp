#include <iostream>
#include <queue>
#include <limits>
using namespace std;
bool check(int n)
{
	if (n %  2 != 0 and n % 3 !=0 and n % 5 != 0 or n % 7 == 0 or n % 11 == 0 or n % 13 == 0)
		return false;
	else
		return true;
}
int main()
{
	queue<int>q;//структура данных-очередь(LILO)
	int n;
	cin >> n;
	int i = 1;
	while (q.size() < n)
	{
		i++;
		if (check(i))
			q.push(i);
	}
	while (!q.empty())//вывод очереди
	{
		cout << q.front() << endl;
		q.pop();
	}


}