#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;

void at_end(int ele);
void at_specific_loc(int ele, int pos);
void at_beginning(int ele);
void delete(int loc);
void search(int ele);
void display();
void reverse();

int size = 0;
NODE *first;
NODE *last;

void main()
{
    int choice, ele, choice2, loc;

    while (1){
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Reverse\n6. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to be inserted : ");
                scanf("%d", &ele);
                printf("\n1. AT End\n2. At Beginning\n3. At specific location\n");
                printf("\nEnter your choice : ");
                scanf("%d", &choice2);
                switch (choice2) {
                    case 1:
                        at_end(ele);
                        break;
                    case 2:
                        at_beginning(ele);
                        break;
                    case 3:
                        printf("\nEnter the location at which element is to be inserted : ");
                        scanf("%d", &loc);
                        at_specific_loc(ele, loc);
                        break;
                    default:
                        printf("\nEnter proper choice!!");
                }
                break;
            case 2:
                printf("\nEnter the location of the node to be deleted : ");
                scanf("%d", &loc);
                delete(loc);
                break;
            case 3:
                printf("\nEnter the element to be searched : ");
                scanf("%d", &ele);
                search(ele);
                break;
            case 4:
                display();
                break;
            case 5:
                reverse();
                break;
            case 6:
                exit(0);
            default:
                printf("\nEnter a valid choice!!");
        }
    }
}

void at_end(int ele)
{
    NODE *ptr = malloc(sizeof (NODE));
    ptr->data = ele;

    last->next = ptr;
    ptr->next = NULL;
    last = ptr;
}

void display()
{
    NODE *ptr = NULL;
    ptr = first;

    while (ptr != NULL){
        size++;
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void search(int ele)
{
    NODE *ptr = first;
    int pos = 1;

    if(first == NULL){
        printf("\nList is empty");
    }
    while (ptr != NULL){
        if(ptr->data == ele){
            printf("\nElement %d is present at %d node\n", ele, pos);
            return;
        }
        pos++;
        ptr = ptr->next;
    }
    printf("\nElement is not present in the list\n");
}

void at_specific_loc(int ele, int pos)
{
    NODE *ptr = first;
    NODE *ptr2 = malloc(sizeof (NODE));

    ptr2->data = ele;
    ptr2->next = NULL;

    while (pos--)
    {
        if(pos == 1){
            ptr2->next = ptr->next;
            ptr->next = ptr2;
        }
        else
            ptr = ptr->next;
    }
}

void at_beginning(int ele)
{
    NODE *ptr = malloc(sizeof (NODE));

    ptr->data = ele;
    ptr->next = NULL;

    if(first == NULL){
        first = last = ptr;
        last = ptr;
    }
    else{
        ptr->next = first;
        first = ptr;
    }
}

void delete(int loc)
{
    int pos = loc;
    NODE *current = first;
    NODE *previous = first;

    if(loc < 1 || loc > size){
        printf("\nEnter proper size!!\n");
        return;
    }

    if(first == NULL)
        printf("\nList is already empty");
    else if(first->next == NULL){
        free(first);
        first = NULL;
    }
    else if(loc == 1){
        first = current->next;
        free(current);
        current = NULL;
    }
    else{
        while (loc != 1){
            previous = current;
            current = current->next;
            loc--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
    printf("\n%d node is deleted", pos);
}

void reverse()
{
    NODE *temp = NULL, *temp2 = NULL;

    temp = first;
    temp2 = first->next;
    last = first;
    first->next = NULL;

    while (temp2 != NULL){
        first = temp2;
        temp2 = temp2->next;
        first->next = temp;
        temp = first;
    }
}