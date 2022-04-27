/*Pointer (3)*/

#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n;
    int kol = 0;
    int *Arr = new int[n];
    float sum = 0.0;
    float avg = 0;

    cout<<"Количество учеников: ";
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        *Arr = 150 + rand() % 50;
        cout<<*Arr<<" ";
        sum += *Arr;
    }

    avg = sum / n;

    for (int i = 0; i < n; i++)
    {
        if (*Arr > avg)
        {
            kol++;
        }
    }
    cout<<"\n";
    cout << "Средний рост: " << avg << " см\n";
    cout << "У " << kol << " человек рост превышает средний";

    delete Arr;
    _getch();
}

