#include <stdio.h>
#include <conio.h>
#include <locale.h>

void StraightSorting(int *arr, int size) // функц≥€ сортуванн€
{

    int min, buf; // зм≥нн≥ м≥н≥мального пошуку ≥ тимчасового збереженн€
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        // пошук м≥н≥мального елементу
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[min]) // €кщо елемент менше м≥н≥мального,
            min = j;
        }

        buf = arr[i];      // зм≥нюЇмо м≥сц€ми ≥-ий ≥ м≥н≥мальний елемент
        arr[i] = arr[min];
        arr[min] = buf;
    }

    printf("ќтсортированый массив:\n");

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
            if (arr[j - 1] < arr[j]) // €кщо елемент менший за попередн≥й
            {
                temp = arr[j - 1]; // м≥н€Їмо м≥сц€ми
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("ќтсортированый массив:\n");

    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
}

void ShakeSorting(int *arr, int count)
{
    int left = 0, right = count - 1; //
    int flag = 1;

    // доки л≥ва граниниц€ не зустр≥нетьс€ з правою
    // ≥ доки в масив≥ Ї перем≥щенн€
    while ((left < right) && flag > 0)
    {
        flag = 0;

        for (int i = left; i < right; i++)  //рух зл≥ва направо
        {
            if (arr[i] < arr[i + 1]) // €кщо наступний елемент менший за поточний, то м≥н€Їмо њх м≥сц€ми
            {
                int t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
                flag = 1;
            }
        }

        right--; // зрушуЇмо праву границю на попередн≥й елемент

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

    printf("ќтсортированый массив:\n");

    for (int i = 0; i < 10; i++)
        printf("%i ", arr[i]);

}

int main()
{
    setlocale(LC_ALL, "rus");

    const int N = 10;
    int choice, i, A[N];

    printf("¬ыберите способ сортировки\n"
           "1 - —ортировка пр€мым выбором\n"
           "2 - —ортировка методом \"пузырька\"\n"
           "3 - Ўейкерна€ сортировка.\n");
    scanf("%i", &choice);
    system("cls");
    switch(choice)
    {
    case 1:
        printf("¬ведите числа: \n");

        for(i = 0; i < N; i++)
        {
            printf("A[%i] = ", i);
            scanf("%i", &A[i]);
        }

        StraightSorting(A, N);
        break;

    case 2:
        printf("¬ведите числа: \n");

        for(i = 0; i < N; i++)
        {
            printf("A[%i] = ", i);
            scanf("%i", &A[i]);
        }

        BubbleSorting(A, N);
        break;

    case 3:
        printf("¬ведите числа: \n");

        for(i = 0; i < N; i++)
        {
            printf("A[%i] = ", i);
            scanf("%i", &A[i]);
        }

        ShakeSorting(A, N);
        break;

    default:
        printf("“акой функции нету((");
    }
}
