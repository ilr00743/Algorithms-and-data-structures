/*Pointer (4)*/

#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL,"Russian");
    int n,m,i,ki,kj,max;

    cout<<"Введите количество строк: ";
    cin>>n;

    cout<<"Введите количество столбцов: ";
    cin>>m;

    // виділення динамічної пам'яті
    int **Arr = new int*[n];

    for(i = 0; i < n; i++)
        Arr[i] = new int[m];

    // заповнення і виведення масиву
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            Arr[i][j] = rand()%35;
            cout<<Arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    max = Arr[0][0]; // вважатимемо максимальним перший елемент

    // визначаємо максимальний елемент та його індекси
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++){
            if (Arr[i][j] > max)
            {
                max = Arr[i][j];
                ki = i;
                kj = j;
            }
        }
    }
    //виведення результату
    cout<<"\nMAX = "<<max<<"["<<ki<<"]["<<kj<<"]";

    // вивільнення динамічної пам'яті
    for(i = 0; i < n; i++)
        delete[]Arr[i];
    delete[]Arr;
    _getch();
}
