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

    cout<<"������� ���������� �����: ";
    cin>>n;

    cout<<"������� ���������� ��������: ";
    cin>>m;
    cout<<"\n";

    // �������� �������� ���'��
    int **Arr = new int*[n];

    for(i = 0; i < n; i++)
        Arr[i] = new int[m];

    // ���������� � ��������� ������
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            Arr[i][j] = rand()%35;
            cout<<Arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
    // ������ �������� �� ��������
    for(j = 0; j < m; j++)
    {
        sum[j] = 0;
        for(i = 0; i < n; i++)
        {
            sum[j] += Arr[i][j];
        }
    }
    cout<<"\n";

    // �������� ���� ��� ������� �������
    for(j = 0; j < m; j++)
    {
        cout<<sum[j]<<"\t";
    }

    // ���������� �������� ���'��
    for(i = 0; i < n; i++)
        delete[]Arr[i];
    delete[]Arr;
    _getch();
}
