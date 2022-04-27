/*Function (2)*/

#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

int in(int *Arr, int n, int currentNum)
{
    srand(time(NULL));
    int kol = 0;

    for(int i = 0; i < n; i++) // введення і виведення масиву
    {
        *Arr = rand() % 20;
        cout<<*Arr<<" ";

        if(*(Arr++) == currentNum) // підраховуємо потрібне число
            kol++;
    }

    return kol;
}

void out(int c)
{
    cout<<"\nЧисло встречается в масиве "<<c<<" раз"; // виводимо результат
    return;
}

int main()
{
    setlocale(LC_ALL,"Russian");
    int n,result,currentNum;

    cout<<"Введите кол-во елементов массива: ";
    cin>>n;

    cout<<"\nВведите число: ";
    cin>>currentNum;

    // виділення динамічної пам'яті
    int *Arr = new int[n];

    result = in(Arr,n,currentNum);
    out(result);

    // вивільнення динамічної пам'яті
    delete Arr;
    _getch();
}
