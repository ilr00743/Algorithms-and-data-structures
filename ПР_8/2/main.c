#include <stdio.h>
#include <stdlib.h>

void Sorting(int *arr, int size, int step)
{
	int i, j, buf;

	// Выбор шага
	for (step = size / 2; step > 0; step /= 2)
	    // Перечисление элементов, которые сортируются на определённом шаге
		for (i = step; i < size; i++)
		    // Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован
			for (j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step)
			{
				buf = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = buf;
			}
}

int main()
{
    int i, step, N = 10;
    int arr[N];

    printf("Enter step: ");
    scanf("%i", &step);

    printf(" Your array: \n");
    for(i = 0; i < N; i++)
    {
        printf("A[%i] = ", i);
        scanf("%i", &arr[i]);
    }

    Sorting(arr, N, step);

    printf("\n Sorted array: \n");
    for(i = 0; i < N; i++)
    {
        printf("A[%i] = %i\n", i, arr[i]);
    }
    return 0;
}
