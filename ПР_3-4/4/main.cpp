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
    int k, i, s = 0, j;

    for(i = 2; i <= n; i++)
    {
        k = 0;
        for(j = 1; j <= i; j++)
            if(i%j == 0)
                k++;
        if(k == 2)
            s++;
    }

    t = clock() - t;
    cout<<"Кількість простих чисел менших за "<<n<<" = "<< s<<"\n";
    cout<<"Для обрахунку знадобилося "<< t << " тактів процесора або "<<((float)t)/CLOCKS_PER_SEC<<" секунд.\n";
    getch();
    return 0;
}
