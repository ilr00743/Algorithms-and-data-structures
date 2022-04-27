#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N = 10;
int count;

int main()
{
    srand(time(NULL));

    int array[N], i, j;
    clock_t start = clock();

    printf("Not-sorted array: ");
    for(i = 0; i < N; i++)
    {
        array[i]= rand() % 20;
        printf("%4d", array[i]);
    }

    printf("\n");

    Sorting(array, 0, N-1);

    printf("\n");
    printf("Sorted array: ");
    for(i = 0; i < N; i++)
    {
        printf("%4d", array[i]);
    }

    clock_t stop = clock();

    double work_time = (double)(stop - start)  /  CLOCKS_PER_SEC;
    printf("\n");
    printf("\nTime elapsed in ms: %f sec", work_time);
    printf("\nAmount of comparison: %d", count);
    getch();
}

void Sorting(int *arr, int left, int right )
{
    int x, i, j, buf;

    if (left >= right) return;

    i = left;
    j = right;
    x = arr[(left + right)/2];

    while (i <= j) {
        while (arr[i] < x)
        {
            i++;
            count++;
        }
            while (arr[j] > x)
            {
                j --;
                count++;
            }
        if (i <= j) {
            buf = arr[i];
            arr[i] = arr[j];
            arr[j] = buf;
            i++;
            j--;
        }
        count++;
    }
    if(left < j) Sorting (arr, left, j );
    if(i < right) Sorting (arr, i, right);
}
