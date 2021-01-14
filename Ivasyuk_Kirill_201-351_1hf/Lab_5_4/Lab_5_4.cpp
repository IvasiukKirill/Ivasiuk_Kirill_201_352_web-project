#include <iostream>
using namespace std;
class Position
{
protected:
	int x;
	int y;
};
class C : public virtual Position
{
protected:
	float r;
};
class S : public Position
{
protected:
	float a;
};
class CandS : public C, public S
{
public:
	CandS(int x, int y, float r, float a)
	{
		C::x = x;
		C::y = y;
		C::r = r;
		S::a = a;
		if (r == a / 2)
			cout << "Yes";
		else
			cout << "No";
	}

};
int main()
{
	CandS m1 = CandS(2, 2, 3, 6);
}