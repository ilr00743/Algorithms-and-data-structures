#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>

const N = 6;

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

    printf("Введите ключ: ");
    scanf("%d", &X);

    a[N] = X;
    i = 0;

    while(a[i] != X){
        printf("i = %d a[i] = %d\n", i, a[i]);
        i++;
    }

    if(i == N)
        printf("Елемент не найден.");
    else
        printf("Индекс = %d", i);
}
