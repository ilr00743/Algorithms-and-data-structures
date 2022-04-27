#include<bits/stdc++.h>


using namespace std;

//������� ��� ���������������� �����
template<typename K, typename V>

//����� ��� ����������� ��� ��������
class HashNode
{
    public:
    V value;
    K key;

    //����������� ���  ��� ��������
    HashNode(K key, V value)
    {
        this->value = value;
        this->key = key;
    }
};

//������� ��� ���������������� �����
template<typename K, typename V>


class HashMap
{
    // ����� ��� ��������
    HashNode<K,V> **arr;

    int capacity;
    //�����
    int size;
    //������� �����
    HashNode<K,V> *dummy;

    public:

    HashMap()
    {
        //����������� ������ ��� ������
        capacity = 20;
        size=0;
        arr = new HashNode<K,V>*[capacity];

        //����������� ��� �������� ������ �� ������
        for(int i=0 ; i < capacity ; i++)
            arr[i] = NULL;

        //������� ����� � ���������� -1 -1
        dummy = new HashNode<K,V>(-1, -1);
    }
    // ³��������� ������� ��� ������ ������� �����
    int hashCode(K key)
    {
        return key % 10;
    }

    //������� ��� ��������� ���� ����-��������
    void insertNode(K key, V value)
    {
        HashNode<K,V> *temp = new HashNode<K,V>(key, value);

        // ������������ ��� ������� ��� ������ ������� �� �������� ������
        int hashIndex = hashCode(key);

        //����� ������ ������� ����
        while(arr[hashIndex] != NULL && arr[hashIndex]->key != key
               && arr[hashIndex]->key != -1)
        {
            hashIndex++;
            hashIndex %= capacity;
        }

        // ���� ����� ����� �������, �� ������ �������� �����
        if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = temp;
    }



    //������� ��� ������ �������� �� �������� ������
    V get(int key)
    {
        // ��������� �� ��� ������� ��� ������ ������� ��������� �����
        int hashIndex = hashCode(key);
        int counter=0;
        //����� �������� �� �������� ������
        while(arr[hashIndex] != NULL)
        {    int counter =0;
             if(counter++>capacity)  //���������� ����������� �����
                return NULL;
            //���� ������� ��������� �� ������� ���� ��������
            if(arr[hashIndex]->key == key)
                return arr[hashIndex]->value;
            hashIndex++;
            hashIndex %= capacity;
        }

        //���� �� �������� ������� ������ ��������
        return NULL;
    }

    //���������� ��������� ������
    int sizeofMap()
    {
        return size;
    }

    //���������� 0 ���� ����� �������
    bool isEmpty()
    {
        return size == 0;
    }

    //������� ��� ����������� ���������� ��� ����-��������
    void display()
    {
        for(int i=0 ; i<capacity ; i++)
        {
            if(arr[i] != NULL && arr[i]->key != -1)
                cout << "key = " << arr[i]->key
                     <<"  value = "<< arr[i]->value << endl;
        }
    }
};

int main()
{
    // ����������� ����� � ������� �������
    HashMap<int, int> *h = new HashMap<int, int>;


    // �������� ������� ������ �� �� �������
    h->insertNode(4,1);
    h->insertNode(1,2);
    h->insertNode(2,1);
    h->display();

    cout << h->sizeofMap() <<endl;

    cout << h->sizeofMap() <<endl;
 //   cout << h->isEmpty() << endl;
    cout << h->hashCode(2) << endl;
    cout << h->get(2);

    return 0;
}
