#include <stdio.h>
#include <conio.h>
#include <locale.h>

void StraightSorting(int *arr, int size) // ������� ����������
{

    int min, buf; // ���� ���������� ������ � ����������� ����������
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        // ����� ���������� ��������
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[min]) // ���� ������� ����� ����������,
            min = j;
        }

        buf = arr[i];      // ������� ������ �-�� � ��������� �������
        arr[i] = arr[min];
        arr[min] = buf;
    }

    printf("�������������� ������:\n");

    for(int i = 0; i < size; i++)
    {
        printf("%i ", arr[i]);
    }
}

void BubbleSorting(int *arr, int size)
{
    int temp, i, j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = (size - 1); j > i; j--)
        {
            if (arr[j - 1] < arr[j]) // ���� ������� ������ �� ���������
            {
                temp = arr[j - 1]; // ������ ������
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("�������������� ������:\n");

    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
}

void ShakeSorting(int *arr, int count)
{
    int left = 0, right = count - 1; //
    int flag = 1;

    // ���� ��� ��������� �� ����������� � ������
    // � ���� � ����� � ����������
    while ((left < right) && flag > 0)
    {
        flag = 0;

        for (int i = left; i < right; i++)  //��� ���� �������
        {
            if (arr[i] < arr[i + 1]) // ���� ��������� ������� ������ �� ��������, �� ������ �� ������
            {
                int t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
                flag = 1;
            }
        }

        right--; // ������� ����� ������� �� ��������� �������

        for (int i = right; i > left; i--)  //
        {
            if (arr[i - 1] < arr[i])
            {
                int t = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = t;
                flag = 1;
            }
        }
        left++;
    }

    printf("�������������� ������:\n");

    for (int i = 0; i < 10; i++)
        printf("%i ", arr[i]);

}

int main()
{
    setlocale(LC_ALL, "rus");

    const int N = 10;
    int choice, i, A[N];

    printf("�������� ������ ����������\n"
           "1 - ���������� ������ �������\n"
           "2 - ���������� ������� \"��������\"\n"
           "3 - ��������� ����������.\n");
    scanf("%i", &choice);
    system("cls");
    switch(choice)
    {
    case 1:
        printf("������� �����: \n");

        for(i = 0; i < N; i++)
        {
            printf("A[%i] = ", i);
            scanf("%i", &A[i]);
        }

        StraightSorting(A, N);
        break;

    case 2:
        printf("������� �����: \n");

        for(i = 0; i < N; i++)
        {
            printf("A[%i] = ", i);
            scanf("%i", &A[i]);
        }

        BubbleSorting(A, N);
        break;

    case 3:
        printf("������� �����: \n");

        for(i = 0; i < N; i++)
        {
            printf("A[%i] = ", i);
            scanf("%i", &A[i]);
        }

        ShakeSorting(A, N);
        break;

    default:
        printf("����� ������� ����((");
    }
}
