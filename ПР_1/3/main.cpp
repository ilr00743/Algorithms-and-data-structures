/*Pointer (1)*/

#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(NULL));
    const int n = 35;
    int kol = 0;
    int *Arr = new int [n]; // виділення динамічної пам'яті

    for(int i = 0; i < n; i++) // заповнення і виведення масиву
    {
        *Arr = rand() % 20;
        cout<<*Arr<<" ";

        if(*(Arr++) != 0) // підрахунок ненульових елементів
            kol++;
    }

    cout<<"\nКоличество ненулевыых елементов: "<<kol<<"";

    delete Arr; // вивільнення дтнамічної пам'яті
    _getch();
}
