#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>

const N = 50;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int i, X, a[N];
    for(i = 0; i < N; i++)
    {
        a[i] = rand() % 10;
        printf("a[%d] = %d\n", i, a[i]);
    }

    printf("������� ����: ");
    scanf("%d", &X);

    i = 0;
    while(a[i] != X)
        i++;

    if(i == N)
        printf("������� �� ������.");
    else
        printf("������ �������� = %d", i);
}
