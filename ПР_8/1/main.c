#include <stdio.h>
#include <conio.h>

void Sorting(int *arr, int N)
{
    int i, j, x;

    for(i = 0; i < N; i++)
    {
        x = arr[i];
        j = i - 1;
        while(j >= 0 && x < arr[j] )
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

int main()
{
    int i, N = 10;
    int arr[N];

    printf(" Your array: \n");
    for(i = 0; i < N; i++)
    {
        printf("A[%i] = ", i);
        scanf("%i", &arr[i]);
    }

    Sorting(arr, N);

    printf("\n Sorted array: \n");
    for(i = 0; i < N; i++)
    {
        printf("A[%i] = %i\n", i, arr[i]);
    }
    return 0;
}

