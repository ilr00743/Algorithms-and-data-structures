#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
using namespace std;

int main()
{
    int n;
    setlocale(LC_ALL, "Russian");
    cout<<"input n = ";
    cin>>n;
    cout<<"Обчислення...";

    int t = clock();
    int freq = n - 1;
    for(int i = 2; i <= n; ++i)
        for(int j = sqrt((float)i ); j > 1; --j)
            if(i % j == 0)
            {
                --freq;
                break;
            }
    t = clock() - t;
    cout << "Кількість простих чисел менших за "<<n<< " = "<< freq<<"\n";
    cout << "Для обрахунку знадобилося "<< t << "тактів процесора або " << ((float)t) / CLOCKS_PER_SEC << " секудн.\n";

    getch();
    return 0;
}
