#include <iostream>
#include <cstdlib>
using namespace std;
    struct tnode // реалізація дерева
    {
        int field; // поле данних
        struct tnode *left; // лівий нащадок
        struct tnode *right; // правий нащадок
    };
    void treeprint(tnode *tree) // обхід дерева у симетричному порядку
    {
        if (tree != NULL){ // перевірка умови на порожність вузла
            treeprint(tree->left); // рекурсія для лівого піддерева
            cout << tree->field << " "; // відображення кореня дерева
            treeprint(tree->right); // рекурсія для правого піддерева
        }
    }
    struct tnode * addnode(int x, tnode *tree) { // додавання вузлів дерева
        if (tree == NULL)
        { // перевірка на існування дерева
            tree = new tnode;
            tree->field = x;
            tree->left = NULL;
            tree->right = NULL; // задання параметрів для нового дерева
        }
        else
            if (x < tree->field)
                tree->left = addnode(x, tree->left);
            else
                tree->right = addnode(x, tree->right); // умови додавання правих і лівих нащадків
        return(tree); // повернення дерева
    }
    void freemem(tnode *tree) // видалення піддерев
    {
        if (tree != NULL)
        { // перевірка умови на порожність вузла
            freemem(tree->left);
            freemem(tree->right);
            delete tree; // видалення піддерева
        }
    }
    int main() // головна функція
      {
        struct tnode *root = 0;
        system("chcp 1251"); // підтримка кирилиці
        system("cls"); // очищення від зайвих символів
        int a;
        for (int i = 0; i< 8; i++)
        {
            cout << "Введіть вузол " << i + 1 << ": ";
            cin >> a;
            root = addnode(a, root);
        } // введення значень у вузли
        treeprint(root);
        freemem(root); // виклик функцій сортування елементів дерева
        cin.get();
        cin.get();
        return 0;
}
