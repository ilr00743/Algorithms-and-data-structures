#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct numbers {
    int num;
    struct numbers *next;
};

struct numbers vvod()
{
    struct numbers n;
    printf("\nEnter a number: "); fflush(stdin); scanf("%i", n.num);
    return n;
}

int show(struct numbers *head)
{
    int count = 0;
    if(head)
    {
        while(1)
        {
            printf("\n%i", head->num);
            count++;
            if(head->next == NULL) break;
            head = head -> next;
        }
    }
    printf("\nCount = %i", count);
    return count;
}

void search(struct numbers *head, int *st)
{
    if(head == NULL) return;
    struct numbers *next = head;

    do{
        int *find = strstr(next -> num, st);
        if(find != NULL) printf("\n%i", next -> num);
        if(next -> next == NULL) break;
        next = next -> next;
    }while(1);
}

void copy1(struct numbers *to, struct numbers *from)
{
    strcpy(to -> num, from -> num);
    to -> num = from -> num;
}

struct numbers *add1(struct numbers *head, struct numbers *st)
{
    struct numbers *current = new numbers;
    copy1(current, st);
    if(head == NULL) current -> next = NULL;
    else{
        current->next = head;
        head = current;
    }
    return current;
}

struct numbers add2(struct numbers *head, struct numbers *st)
{
    struct numbers *last = NULL;

    if(head != NULL){
        last = head;
        while(last->next != NULL) last = last->next;
    }
    numbers *current = new numbers;
    copy1(current, st);
    current->next = NULL;
    if(last) last->next = current;
    return current;
}

numbers *delete1(numbers *head0, int n)
{
    person *head = head0;
    if(head == NULL) return NULL;
    if(n == 1)
    {
        numbers *ptr = head->next;
        delete head;
        return ptr;
    }
    numbers *prev = NULL, *start = head; int = 1;

    while(i < n)
    {
        prev = head;
        head = head -> next;
        if(head == NULL) return start;
        i++
    }
    numbers *ptr = head->next;
    delete head;

    prev->next = prt;
    return start;
}

numbers *sort(numbers *ph)
{
    numbers *q, *p, *pr, *out = NULL;

    while(ph != NULL)
    {
        q = ph; ph = ph->next;

        for(p = out, pr = NULL; p != NULL && strcmp(q->num, p->num) > 0; pr = p, p = p->next);
        if(pr == NULL)
        {
            q->next = out;
            out = q;
        }
        else{
            q->next = p;
            pr->next = q;
        }
    }
    return out;
}

int main()
{
    numbers *head = NULL;

    while(1)
    {
        printf("\n 1. Show all \
                \n 2. Add in head \
                \n 3. Add in tail \
                \n 4. Delete by number \
                \n 5. Sort by name \
                \n 0. Exit");
        fflush(stdin);

        char choice;
        scanf("%c", &choice);

        numbers num;
        numbers *cur;

        int n, all;

        switch(c)
        {
            case '1': show(head);
            break;

            case '2': num = vvod(); head = add1(head, &num);
            break;

            case '3': num = vvod();
                    cur = add2(head, &num);
                    if(head == NULL) head = cur;
            break;

            case '4':
                all = show(head);

                while(1)
                {
                    printf("Enter the number (1 - %i): ", all);
                    if(n >= 1 && n <= all) break;
                }
                head = delete1(head, n);
            break;

            case '5': head = sort(head);
            break;

            case '0': exit(0); break;

        }
    }
    return 0;
}
