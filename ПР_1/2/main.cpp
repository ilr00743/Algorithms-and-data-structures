/*Function (2)*/

#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

int in(int *Arr, int n, int currentNum)
{
    srand(time(NULL));
    int kol = 0;

    for(int i = 0; i < n; i++) // �������� � ��������� ������
    {
        *Arr = rand() % 20;
        cout<<*Arr<<" ";

        if(*(Arr++) == currentNum) // ���������� ������� �����
            kol++;
    }

    return kol;
}

void out(int c)
{
    cout<<"\n����� ����������� � ������ "<<c<<" ���"; // �������� ���������
    return;
}

int main()
{
    setlocale(LC_ALL,"Russian");
    int n,result,currentNum;

    cout<<"������� ���-�� ��������� �������: ";
    cin>>n;

    cout<<"\n������� �����: ";
    cin>>currentNum;

    // �������� �������� ���'��
    int *Arr = new int[n];

    result = in(Arr,n,currentNum);
    out(result);

    // ���������� �������� ���'��
    delete Arr;
    _getch();
}
