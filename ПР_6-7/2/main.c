#include <stdio.h>
#include <conio.h>
#include <locale.h>

void Sorting(int *num, int size);

int main()
{
    setlocale(LC_ALL, "rus");

    int A[10], i;

    for (i = 0; i < 10; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &A[i]);
    }
    Sorting(A, 10);  // виклик функції сортування

    getch();
}

void Sorting(int *num, int size)
{
    int temp, i, j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = (size - 1); j > i; j--)
        {
            if (num[j - 1] > num[j]) // якщо елемент менший за попередній
            {
                temp = num[j - 1]; // міняємо місцями
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }

    for (i = 0; i < 10; i++)
        printf("%d ", num[i]);

}
