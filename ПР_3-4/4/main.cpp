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
    cout<<"����������...";

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
    cout<<"ʳ������ ������� ����� ������ �� "<<n<<" = "<< s<<"\n";
    cout<<"��� ��������� ����������� "<< t << " ����� ��������� ��� "<<((float)t)/CLOCKS_PER_SEC<<" ������.\n";
    getch();
    return 0;
}
