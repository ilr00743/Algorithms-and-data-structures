/*Pointer (2)*/

#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(NULL));
    int n;
    int i, j;

    cout<<"Введите количество строк: ";
    cin>>n;

    // виділення динамічної пам'яті
    int **A = new int*[n];

    for(i = 0; i < n; i++)
        A[i] = new int[n];

    // заповнення і виведення масиву
    cout<<"\n Старый массив:\n";
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            A[i][j] = rand() % 20;

            cout<<A[i][j]<<"\t";
        }
        cout<<"\n";
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(A[i][j] % 2 != 0) // якщо елемент непарний, то змінюється на нуль
                A[i][j] = 0;
        }
    }

    cout<<"\n";
    cout<<"\n Новый массив:\n";
    for(i = 0; i < n; i++) //виводимо новий масив
    {
        for(j = 0; j < n; j++)
        {
            cout<<A[i][j]<<"\t";
        }
        cout<<"\n";
    }

    // вивільнення дтнамічної пам'яті
    for(i = 0; i < n; i++)
        delete[]A[i];
    delete[]A;
    _getch();
}
