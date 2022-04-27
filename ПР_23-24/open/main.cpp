#include<bits/stdc++.h>


using namespace std;

//шаблони для використовуваних зміних
template<typename K, typename V>

//класс для ініціалізації хеш елементів
class HashNode
{
    public:
    V value;
    K key;

    //конструктор для  хеш елементів
    HashNode(K key, V value)
    {
        this->value = value;
        this->key = key;
    }
};

//шаблони для використовуваних зміних
template<typename K, typename V>


class HashMap
{
    // масив хеш елементів
    HashNode<K,V> **arr;

    int capacity;
    //розмір
    int size;
    //порожній вузол
    HashNode<K,V> *dummy;

    public:

    HashMap()
    {
        //ініціалізація розміру хеш масиву
        capacity = 20;
        size=0;
        arr = new HashNode<K,V>*[capacity];

        //ініціалізація всіх елементів масиву як порожні
        for(int i=0 ; i < capacity ; i++)
            arr[i] = NULL;

        //порожній вузол зі значеннями -1 -1
        dummy = new HashNode<K,V>(-1, -1);
    }
    // Відтворення функції для пошуку індексу ключа
    int hashCode(K key)
    {
        return key % 10;
    }

    //Функція для додавання пари ключ-значення
    void insertNode(K key, V value)
    {
        HashNode<K,V> *temp = new HashNode<K,V>(key, value);

        // використання хеш функції для пошуку індексу за вказаним ключем
        int hashIndex = hashCode(key);

        //пошук іншого вільного місця
        while(arr[hashIndex] != NULL && arr[hashIndex]->key != key
               && arr[hashIndex]->key != -1)
        {
            hashIndex++;
            hashIndex %= capacity;
        }

        // якщо новий вузол доданик, то збільшує поточний розмір
        if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = temp;
    }



    //Функція для пошуку елемента за вказаним ключем
    V get(int key)
    {
        // Звернення до хеш функції для пощуку індексу вказаного ключа
        int hashIndex = hashCode(key);
        int counter=0;
        //Пошук елементу за вказаним ключем
        while(arr[hashIndex] != NULL)
        {    int counter =0;
             if(counter++>capacity)  //запобігання нескінченого циклу
                return NULL;
            //якщо елемент знайдений то повернає його значення
            if(arr[hashIndex]->key == key)
                return arr[hashIndex]->value;
            hashIndex++;
            hashIndex %= capacity;
        }

        //Якщо не знайдено повернає порожнє значення
        return NULL;
    }

    //Повернення нинішнього розміру
    int sizeofMap()
    {
        return size;
    }

    //Повернення 0 якщо розмір порожній
    bool isEmpty()
    {
        return size == 0;
    }

    //функція для відображення збережених пар ключ-значення
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
    // ініціалізація класу в головній функції
    HashMap<int, int> *h = new HashMap<int, int>;


    // введення значень ключів та їх значень
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
