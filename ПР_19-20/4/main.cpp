#include <iostream>
#include <conio.h>
using namespace std;
unsigned long fibonacci(unsigned long);

int main()
{
    unsigned long entered_number;
    cout << "Enter number from the Fibonacci series: ";
    cin >> entered_number;

    for(int counter = 1; counter <= entered_number; counter++)
        cout <<counter << " = "<< fibonacci(counter) << endl;
    system("pause");
    return 0;
}

unsigned long fibonacci(unsigned long entered_number)
{
    if(entered_number == 1 || entered_number == 2)  return (entered_number - 1);

    return fibonacci(entered_number - 1) + fibonacci(entered_number - 2);
}
