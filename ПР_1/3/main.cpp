/*Pointer (1)*/

#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(NULL));
    const int n = 35;
    int kol = 0;
    int *Arr = new int [n]; // �������� �������� ���'��

    for(int i = 0; i < n; i++) // ���������� � ��������� ������
    {
        *Arr = rand() % 20;
        cout<<*Arr<<" ";

        if(*(Arr++) != 0) // ��������� ���������� ��������
            kol++;
    }

    cout<<"\n���������� ���������� ���������: "<<kol<<"";

    delete Arr; // ���������� �������� ���'��
    _getch();
}
