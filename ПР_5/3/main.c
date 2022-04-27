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

    int i, X, a[N], L = 0, R = N - 1, m;

    for(i = 0; i < N; i++)
    {
        a[i]= i + 1;
    }

    printf("Введите ключ: ");
    scanf("%d", &X);

    while(L < R){
        printf("\n L = %d; R = %d; m = %d; a[m] = %d; a[r] = %d ", L, R, m, a[m], a[R]);
        m = (L + R) / 2;

        if(a[m] < X){
            L = m + 1;
        }
        else{
            R = m;
        }
    }

    printf("\n");
    printf("\n L = %d; R = %d; m = %d; a[m] = %d; a[r] = %d ", L, R, m, a[m], a[R]);

    if(a[R] = X){
        printf("\nИндекс = %d", R);
    }
    else{
        printf("\nЕлемент не найдено.");
    }

}
