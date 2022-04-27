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

    cout<<"������� ���������� �����: ";
    cin>>n;

    // �������� �������� ���'��
    int **A = new int*[n];

    for(i = 0; i < n; i++)
        A[i] = new int[n];

    // ���������� � ��������� ������
    cout<<"\n ������ ������:\n";
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
            if(A[i][j] % 2 != 0) // ���� ������� ��������, �� ��������� �� ����
                A[i][j] = 0;
        }
    }

    cout<<"\n";
    cout<<"\n ����� ������:\n";
    for(i = 0; i < n; i++) //�������� ����� �����
    {
        for(j = 0; j < n; j++)
        {
            cout<<A[i][j]<<"\t";
        }
        cout<<"\n";
    }

    // ���������� �������� ���'��
    for(i = 0; i < n; i++)
        delete[]A[i];
    delete[]A;
    _getch();
}
