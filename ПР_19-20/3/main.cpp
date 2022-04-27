#include <iostream>
#include<conio.h>

using namespace std;

unsigned long int factorial(unsigned long int);

int i = 1;

unsigned long int result = 1;

int main()
{
	int n;
	cout << "Enter n!"<< endl;
	cin >> n;
	factorial(n);

	system("pause");
	return 0;
}

unsigned long int factorial(unsigned long int f) {

	if (f == 1 || f == 0) {
		return 1;
	}
	for (int i = 1; i != f; i++) {
		result = result + result * i;
	}
	cout << f << "!" << " = " << result << endl;;
}
