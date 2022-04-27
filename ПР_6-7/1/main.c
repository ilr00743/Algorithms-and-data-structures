#include <stdio.h>
#include <conio.h>
#include <locale.h>

void Sorting(int *num, int size);

int main()
{
    setlocale(LC_ALL, "rus");

    int N = 10;
    int A[N], i;

    printf("������� �����: \n");

    for(i = 0; i < N; i++)
    {
        printf("A[%i] = ", i);
        scanf("%i", &A[i]);
    }

    Sorting(A, N);

    return 0;
}

void Sorting(int *num, int size) // ������� ����������
{

    int min, buf; // ���� ���������� ������ � ����������� ����������
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        // ����� ���������� ��������
        for (int j = i + 1; j < size; j++)
        {
            if (num[j] < num[min]) // ���� ������� ����� ����������,
            min = j;
        }

        buf = num[i];      // ������� ������ �-�� � ��������� �������
        num[i] = num[min];
        num[min] = buf;
    }

    for(int i = 0; i < size; i++)
    {
        printf("%i ", num[i]);
    }
}
