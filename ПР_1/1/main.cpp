/*Function (1)*/

#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

int Arr(int **a, int n)
{
    int sum = 0;
    srand(time(NULL));

    // ��������� ������ ���������� ������� � ���� ��������� �� �����
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 10;
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i = 0; i < n; i++)
        sum += a[i][i]; // ��������� ����� ������� �������
    return sum;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL,"Russian");
    int n,i,result;

    cout<<"������� ���������� �����: ";
    cin>>n;

    // �������� �������� ���'��
    int **a = new int*[n];
    for(i = 0; i < n; i++)
        a[i] = new int[n];

    result=Arr(a,n);
    cout<<"����� = "<<result;

    // ���������� �������� ���'��
    for(i = 0; i < n; i++)
        delete[]a[i];
    delete[]a;
    _getch();
}
