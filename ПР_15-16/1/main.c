#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 100

struct tnode{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

// Функція додавання вузла до дерева
struct tnode *addtree(struct tnode *p, char *w){
    int cond;

    if(p == NULL){
        p = (struct tnode *)malloc(sizeof(struct tnode));
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if(cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

void freemem(tnode *tree){
    if(tree != NULL){
        freemem(tree->left);
        freemem(tree->right);
        free(tree);
    }
}

void treeprint(struct tnode *p){
    if(p != NULL){
        treeprint(p->left);
        printf("%d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

int main(){
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    printf("Enter the string. Exit condition - character input '0' \n");

    do{
        scanf("%s", word);
        if(isalpha(word[0]))
            root = addtree(root, word);
    }while(word[0] != '0');

    treeprint(root);
    freemem(root);
    getchar();
    getchar();
    return 0;
}
