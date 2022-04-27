#include <iostream>
#include <queue> // �����

using namespace std;
int main()
{
    queue<int> Queue;
    int mas[7][7] = {
        { 0, 1, 1, 0, 0, 0, 1 }, // �������� ��������
        { 1, 0, 1, 1, 0, 0, 0 },
        { 1, 1, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 1, 0, 1 },
        { 1, 0, 0, 0, 0, 1, 0 } };
    int nodes[7]; // ������� �����
    for (int i = 0; i < 7; i++)
        nodes[i] = 0; // �� ������� ��� 0
    Queue.push(0); // �������� � ����� ����� �������
    while (!Queue.empty())
    { // ���� ����� �� �������
        int node = Queue.front(); // ������ �������
        Queue.pop();
        nodes[node] = 2; // �������� �� �� �������

        for (int j = 0; j < 7; j++)
        { // ���������� ��� �� �� ����� �������
            if (mas[node][j] == 1 && nodes[j] == 0)
            { // ���� ������� ������ � �� ��������
                Queue.push(j); // ������ �� � �����
                nodes[j] = 1; // ������� ������� �� ��������
            }
        }
        cout << node + 1 << endl; // �������� ����� �������
    }

    cin.get();
    return 0;
}
