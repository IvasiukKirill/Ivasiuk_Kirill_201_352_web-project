#include <iostream>


using std::cout;
using std::cin;
using std::endl;
int fact(int n)
{
	int resultn=1;
	for (int i = 1;i <= n;i++) 
	{
		resultn = resultn * i;
	}
	return resultn;
}
int main()

{
	setlocale(LC_ALL, "Russian");
	int choice = 0; // в этой переменной будет храниться выбор пользователя
	while (true) // непрерывный цикл
	{
		std::cout << "Что вы хотите выполнить? \n" << "1. задание 1\n" << "2. задание 2\n" << "3. задание 3\n" << "4. выход\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int с;
			cin >> с;

			for (int i = 0;i <= с;i++)
			{
				for (int g = 0;g <= i;g++)
				{
					cout << g;
				}
				cout << endl;
			}
			/*вызов функции для решения задания 1*/;

			break; // если его не ставить, то после вызова task1(), начнет выполнятся task2()
		}
		case 2:
		{
			int j, l;
			cin >> l;
			for (int k = 0;k <= l;k++)
			{
				cout << fact(l) / (fact(l - k) * fact(k)) << endl;
			}
			/*вызов функции для решения задания 1*/;

			break;
		}
		case 3:
		{
			int t = -1, summ = 0, x = 0;

			while (x != 999999999)
			{


				summ = summ + x;
				t++;
				cin >> x;



			}
			cout << double(summ) / t<< endl;


			break;
		}
		case 4: 
		{

			
			return 0;
		}

		default:
		{
			return 0;
		}
		}
	}

}