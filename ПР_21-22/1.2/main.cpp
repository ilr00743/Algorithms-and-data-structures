#include <iostream>
#include <stack> // ����

using namespace std;

int main()
{
    stack<int> Stack;
    int mas[7][7] = {
        { 0, 1, 1, 0, 0, 0, 1 }, // ������� ���������
        { 1, 0, 1, 1, 0, 0, 0 },
        { 1, 1, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 1, 0, 1 },
        { 1, 0, 0, 0, 0, 1, 0 } };
    int nodes[7]; // ������� �����
    for (int i = 0; i < 7; i++) // ������� ��� ������� ����� 0
        nodes[i] = 0;
    Stack.push(0); // �������� � ������� ������ �������

    while (!Stack.empty())
    { // ���� ���� �� ����
        int node = Stack.top(); // ��������� �������
        Stack.pop();
        if (nodes[node] == 2) continue;
        nodes[node] = 2; // �������� �� ��� ����������
        for (int j = 6; j >= 0; j--){ // ��������� ��� ��� ��� ������� �������
            if (mas[node][j] == 1 && nodes[j] != 2){ // ���� ������� ������� � �� ����������
                Stack.push(j); // ��������� �� � c���
                nodes[j] = 1; // �������� ������� ��� ������������
            }
        }
        cout << node + 1 << endl; // ������� ����� �������
    }
    cin.get();
    return 0;
}
