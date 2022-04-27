#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int k = 0, p, i, m;
    const long n = 100000;
    cout<<"����������...";
    int t = clock();

    bool A[n];
    for(i = 0; i <= n; i++)
        A[i] = true;
    for(i = 2; i*i <= n; ++i)
        if(A[i])
           for(m = 0; i*i+i*m <= n; m++)
            A[i*i+i*m] = false;
    for(i = 2; i <= n; i++)
        if(A[i])
            k++;

    t = clock() - t;
     cout << "ʳ������ ������� ����� ������ �� "<<n<< " = "<< k<<"\n";
    cout << "��� ��������� ����������� "<<t<< " ����� ��������� ��� " << ((float)t) / CLOCKS_PER_SEC << " ������.\n";

    return 0;
}
