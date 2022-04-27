#include <iostream>
using namespace std;

// функія бінарного пошуку
int SearchBinary (int arr[], int left, int right, int key);

int main()
{
    setlocale(LC_ALL, "rus");

    const int N = 6;
    int arr[N] = {};
    int key = 0;
    int index = 0;

    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
        cout << arr[i] << " | ";
    }

    cout << "\n\nВведите любое число: ";
    cin >> key;

    index = SearchBinary (arr, 0, N, key);

    if (index >= 0)
        cout << "Индекс: " << index << "\n\n";
    else
        cout << "Такого числа нет.\n\n";

    return 0;
}

int SearchBinary (int arr[], int left, int right, int key)
{
    int mid = 0;

    while (1)
    {
        mid = (left + right) / 2;

        if (key < arr[mid])       // якщо шукане число менше за значення в комірці
            right = mid - 1;
        else if (key > arr[mid])  // якщо шукане число менше за значення в комірці
            left = mid + 1;
        else
            return mid;           // повертає індекс комірки

        if (left > right)          // якщо границі зімкнулись
            return -1;
    }
}
