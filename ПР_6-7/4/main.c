#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    int i;
    int n = 3;
    int arr[n];

    for(i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nОбычный массив:");
    for(i = 0; i < n; i++){
        printf(" %d ", arr[i]);
    }

    printf("\nОбработанный массив:");

    for (i = 0; i < n + 1; i++){
        int temp = arr[i];
        arr[i] = arr[i + 2];
        arr[i + 2] = temp;

        for (i = 0; i < n; i++){
            printf(" %d ", arr[i]);
        }
    }
    return 0;
}
