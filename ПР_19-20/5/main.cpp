#include <iostream>
#include <conio.h>
using namespace std;
using namespace std;

int main()
{
	int a, b, k, n = 0;
	a = 0;
	b = 1;
	cout << "Enter number from Fibonacci series: ";
	cin >> k;
	while (k <= 0)
	{
		cout << "ERROR! Enter the number greater than zero: ";
		cin >> k;
	}
	while (k != 1)
	{
	    n++;
		a = a + b;
		b = a - b;
		k = k - 1;
		cout << n << " = "<< a << endl;
	}
	return 0;
}
