//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

int main()
{
    int a[SIZE][SIZE]; // матриця зв’язків
    int d[SIZE]; // мінімальна відстань
    int v[SIZE]; // відвідані вершини
    int temp, minindex, min;
    int begin_index = 0;

    system("cls");

    // Ініціалізація матриці зв’язків
    for (int i = 0; i<SIZE; i++)
    {
        a[i][i] = 0;
        for (int j = i + 1; j<SIZE; j++) {
            printf("vvedte vidctani %d - %d: ", i + 1, j + 1);
            scanf("%d", &temp);
            a[i][j] = temp;
            a[j][i] = temp;
        }
    }

    // Виведення матриці зв’язків
    for (int i = 0; i<SIZE; i++)
    {
        for (int j = 0; j<SIZE; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }

    //Ініціалізація вершин і відстаней
    for (int i = 0; i<SIZE; i++)
    {
        d[i] = 10000;
        v[i] = 1;
    }
    d[begin_index] = 0;

    // Крок алгоритму
    do
    {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i<SIZE; i++)
        { // Якщо вершину ще не обійшли і вага менше min
            if ((v[i] == 1) && (d[i]<min))
            { // Переприсвоюємо значення
                min = d[i];
                minindex = i;
            }
        }
    // Додаємо знайдену мінімальну вагу
    // до поточної ваги вершини
    // і порівнюємо з поточною мінімальною вагою вершини
        if (minindex != 10000)
        {
            for (int i = 0; i<SIZE; i++)
            {
                if (a[minindex][i] > 0)
                {
                    temp = min + a[minindex][i];
                    if (temp < d[i])
                    {
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
    } while (minindex < 10000);

    // Виведення найкоротших відстаней до вершин
    printf("\n naikorotsha vidstan do vershin: \n");
    for (int i = 0; i<SIZE; i++)
        printf("%5d ", d[i]);

    // Відновлення шляху
    int ver[SIZE]; // масив відвіданих вершин
    int end = 4; // індекс кінцевої вершини = 5 - 1
    ver[0] = end + 1; // початковий елемент - кінцева вершина
    int k = 1; // індекс попередньої вершини
    int weight = d[end]; // вага кінцевої вершини

    while (end != begin_index) // поки не дійшли до початкової вершини
    {
        for (int i = 0; i<SIZE; i++) // переглядаємо всі вершини
            if (a[end][i] != 0) // якщо є зв’язок
            {
                int temp = weight - a[end][i]; // визначаємо вагу шляху з попередньої вершини
                if (temp == d[i]) // якщо вага співпала з розрахованою
                { // отже з цієї вершини і був перехід
                    weight = temp; // зберігаємо нову вагу
                    end = i; // зберігаємо попередню вершину
                    ver[k] = i + 1; // і записуємо її у масив
                    k++;
                }
            }
    }

    // Виведення шляху (початкова вершина розмістилась у кінці масиву из k елементів)
    printf("\n Vivedenny naikorotshogo shlyhu\n");

    for (int i = k - 1; i >= 0; i--)
        printf("%3d ", ver[i]);
    getchar(); getchar();
    return 0;
}
