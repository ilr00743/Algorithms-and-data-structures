#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// ініціалізація списку
struct listNode {
    int data;
    struct listNode *nextPtr;
};
typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

int main()
{
    LISTNODEPTR startPtr = NULL;

    int choice;
    int item;

    instructions();

    printf("? ");
    scanf ("%d", &choice);

    while(choice != 3){
        switch(choice){

        case 1:
            printf("Enter a character: ");
            scanf("\n%i", &item);
            insert(&startPtr, item);
            printList(startPtr);
        break;

        case 2:
            if(!isEmpty(startPtr)){
                printf("Enter character to be deleted: ");
                scanf("\n%i", &item);

                if(delete(&startPtr, item)){
                    printf ("%i deleted.\n", item);
                    printList(startPtr);
                }
                else printf("%i not found.\n\n", item);
            }
            else printf("List is empty.\n\n");
        break;

        default:
            printf("Invalid choice.\n\n");
            instructions();
        break;
        }
      printf("?  ");
      scanf("%i", &choice);
    }
    printf("End of run.");
    return 0;
}

void instructions(void)
{
    printf("Enter your choice:\n"
           "1 to add an element into the list\n"
           "2 to delete an element from the list\n"
           "3 to end\n");
}

void insert(LISTNODEPTR *sPtr, int value) // введення даних у список
{
    LISTNODEPTR newPtr, previousPtr, currentPtr;

    newPtr = malloc(sizeof(LISTNODE));

    if(newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        previousPtr = NULL;
        currentPtr = *sPtr;

      if(previousPtr == NULL){
                newPtr->nextPtr = *sPtr;
                *sPtr = newPtr;
          }
          else{
            previousPtr->nextPtr = *sPtr;
            newPtr->nextPtr = currentPtr;
          }
    }
    else
        printf("%i not inserted. No memory acailable.\n", value);
}

int delete(LISTNODEPTR *sPtr, int value) // видалення елементів зі списку
{
    LISTNODEPTR previousPtr, currentPtr, tempPtr;

    if(value == (*sPtr)->data){
        tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);
        return value;
    }
    else{
        previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextPtr;

        while(currentPtr != NULL && currentPtr->data != value){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if(currentPtr != NULL) {
            tempPtr = currentPtr;
            previousPtr ->nextPtr = currentPtr -> nextPtr;
            free(tempPtr);
            return value;
        }
    }
    return 0;
}

int isEmpty(LISTNODEPTR sPtr) // перевірка на заповненість списку
{
    return sPtr == NULL;
}

void printList(LISTNODEPTR currentPtr) // виведення списку
 {
     if(currentPtr == NULL)
        printf("List is empty.\n\n");
     else{
        printf("The list is: \n");

        while(currentPtr != NULL){
            printf("%i --> ", currentPtr->data);
            currentPtr = currentPtr -> nextPtr;
        }
        printf("NULL\n\n");
     }
 }
