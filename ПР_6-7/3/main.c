#include <stdio.h>
#include <conio.h>
#include <locale.h>

void Sorting(int *arr, int count);

int main() {

    setlocale(LC_ALL, "rus");
    int Arr[10];

    for (int i = 0; i < 10; i++) {
        printf("A[%i] = ", i);
        scanf("%i", &Arr[i]);
    }

    Sorting(Arr, 10);

    return 0;
}

void Sorting(int *arr, int count)
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
            if (arr[i] > arr[i + 1]) // €кщо наступний елемент менший за поточний, то м≥н€Їмо њх м≥сц€ми
            {
                int t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
                flag = 1;
            }
        }

        right--; // зрушуЇмо праву границю на попередн≥й елемент

        for (int i = right; i>left; i--)  //
        {
            if (arr[i - 1]>arr[i])
            {
                int t = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = t;
                flag = 1;
            }
        }
        left++;
    }

    for (int i = 0; i < 10; i++)
        printf("%i ", arr[i]);

}
