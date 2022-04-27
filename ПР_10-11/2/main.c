#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct person //оголошуємо структуру (список)
{
    char fio[30];
    char gender[30];
    float pay;
    int age;
    struct person *next;
};

struct person input()
{
    struct person p;
    printf("\nFIO->");
    fflush(stdin);
    scanf("%s",p.fio);

    printf("\nGender->");
    fflush(stdin);
    scanf("%s",p.gender);

    printf("\nPay->");
    fflush(stdin);
    scanf("%f",&p.pay);

    printf("\nAge->");
    fflush(stdin);
    scanf("%i",&p.age);

    return p;
} //введення кожного елементу структури у список

int show(struct person *head)
{
    int count=0;

    if(head)
        while(1)
        {
            printf("\n%s %s %.2f %i", head->fio,head->gender,head->pay,head->age);
            count++;

            if(head->next == NULL) break;

            head = head->next;
        }

    printf("\nAll = %i",count);

    return count;
} // функція для виведення елементів у консоль

void search(struct person *head, char *st)
{
    if(head==NULL) return;

    struct person *next = head;

    do
    {
        char *find = strstr(next->fio, st);
        if(find != NULL)
            printf ("\n%s",next->fio);
        if(next->next == NULL) break;

        next = next->next;
    } while(1);
} // функція для пошуку елементу за порядковим номером

void copy1(struct person *to, struct person *from)
{
    strcpy(to->fio, from->fio);
    strcpy(to->gender, from->gender);

    to->pay = from->pay;
    to->pay = from->pay;
} // функція для копіювання елементів списку для подольшого використання у сортвуванні та додаванні нових елементів

struct person *add1(struct person *head, struct  person *st)
{

    person *current = new person;
    copy1(current, st);

    if(head==NULL)
        current->next = NULL;
    else{
        current->next = head;
        head = current;
    }

    return current;
}// функція для додавання елементів у початок списку

person *add2(person *head, person *st)
{
    person *last = NULL;

    if(head != NULL) {
        last = head;

        while(last->next != NULL)
            last = last->next;
    }

    person *current = new person;
    copy1 (current,st);
    current->next = NULL;

    if (last) last->next = current;

    return current;
} // функція для додавання елементів у кінець списку

person *deleteElement(person *head0, int n)
{
    person *head = head0;

    if(head == NULL) return NULL;

    if(n == 1)
    {
        person *ptr = head->next;
        delete head;
        return ptr;
    }

    person *prev = NULL, *start = head;

    int i = 1;

    while(i < n)
    {
        prev = head;
        head = head->next;
        if (head==NULL) return start;
        i++;
    }

    person *ptr = head->next;
    delete head;
    prev->next = ptr;

    return start;
} // функція видалення елементу за вказаними данними

person *sort(person *ph)
{
    person *q, *p, *pr, *out=NULL;
    while(ph != NULL)
    {
        q = ph; ph = ph->next;
        for(p = out, pr = NULL; p != NULL && strcmp(q->fio, p->fio) > 0; pr = p, p = p->next);

        if(pr == NULL){
            q->next = out;
            out = q;
        }
        else{
            q->next = p;
            pr->next = q;
        }
    }

    return out;
}  // функція для сортування елементів списку за імям
void instructions(void)
{
        printf ("\n 1. Show list\
            \n 2. Add in top \
            \n 3. Add in bottom \
            \n 4. Delete \
            \n 5. Sort \
            \n 0. Exit ");
}

int main()
{
    setlocale(LC_ALL, "rus");

    person *head = NULL;// ініціалізація структури у головну функцію
    while (1)
        {
            instructions();

            fflush (stdin);

            int c;
            scanf ("%i",&c);

            person p;
            person *cur;

            int n, all;
            switch (c)
                    {
                    case 1:
                            show(head); // виклик функції для перегляду елементів масиву
                            break;
                    case 2:
                            p = input();
                            head = add1(head,&p); //виклик функції для заповнення елементів списку даними в початок списку
                            break;
                    case 3:
                            p = input();
                            cur = add2(head,&p); //виклик функції для заповнення елементів списку даними в кінець списку
                            if (head == NULL)
                                head = cur;
                            break;
                    case 4:
                            all = show(head);
                            while(1)
                            {
                                    printf("\nInput number (1-%d): ", all);
                                    fflush(stdin);
                                    scanf("%i",&n);
                                    if(n >= 1 && n <= all) break;
                            }
                            head = deleteElement (head, n);
                            break;   // пошук елементів списку за його порядковим номером
                    case 5:
                            head = sort(head);
                            break; // виклик фунції для сортування елементів за імям
                    case 0:
                            exit(0);
                            break; // вихід із програми
            }
    }
    return 0;
}
