#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL,"Russian");
    int n,m,i,j;
    int sum[m];

    cout<<"¬ведите количество строк: ";
    cin>>n;

    cout<<"¬ведите количество столбцов: ";
    cin>>m;
    cout<<"\n";

    // вид≥ленн€ динам≥чноњ пам'€т≥
    int **Arr = new int*[n];

    for(i = 0; i < n; i++)
        Arr[i] = new int[m];

    // заповненн€ ≥ виведенн€ масиву
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            Arr[i][j] = rand()%35;
            cout<<Arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
    // додаЇмо елементи по стовпц€м
    for(j = 0; j < m; j++)
    {
        sum[j] = 0;
        for(i = 0; i < n; i++)
        {
            sum[j] += Arr[i][j];
        }
    }
    cout<<"\n";

    // виводимо суму дл€ кожного стовпц€
    for(j = 0; j < m; j++)
    {
        cout<<sum[j]<<"\t";
    }

    // вив≥льненн€ динам≥чноњ пам'€т≥
    for(i = 0; i < n; i++)
        delete[]Arr[i];
    delete[]Arr;
    _getch();
}
