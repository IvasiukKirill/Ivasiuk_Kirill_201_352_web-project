#include <iostream>
#include <queue>
#include <limits>
using namespace std;
bool check(int n)
{
	if (n % 2 == 0 or n % 3 == 0 or n % 5 == 0)
		return true;
	else
		return false;
}
int main()
{
	queue<int>q;
	int n;
	cin >> n;
	int length = INT_MAX;
	int i = 1;
	while (q.size() < n)
	{
		i++;
		if (check(i))
			q.push(i);
	}
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}


}