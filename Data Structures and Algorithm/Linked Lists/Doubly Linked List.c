#include "stdio.h"
#include "stdlib.h"

struct node{
    struct node *prev;
    int data;
    struct node *next;
};
typedef struct node NODE;

NODE *head = NULL;

void insert(int ele, int pos);
void atbeginning(int ele);
void delete(int pos);
void atspecificpos(int ele, int pos);
void search(int ele);
void display();
void reverse();

void main()
{
    int choice, ele, pos;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Reverse\n6. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to be inserted : ");
                scanf("%d", &ele);
                printf("\nEnter the position of the element : ");
                scanf("%d", &pos);
                insert(ele, pos);
                break;
            case 2:
                printf("\nEnter the position of node to be deleted : ");
                scanf("%d", &pos);
                delete(pos);
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
                printf("\nEnter proper choice!!\n");
        }
    }
}

void insert(int ele, int pos)
{
    if(pos == 1){
        atbeginning(ele);
    }
    else
    {
        atspecificpos(ele, pos);
    }
}

void atbeginning(int ele)
{
    NODE *ptr = NULL;
    ptr = malloc(sizeof(NODE));
    ptr->prev = NULL;
    ptr->data = ele;
    ptr->next = NULL;

    if(head == NULL){
        head = ptr;
    }
    else
    {
        head->prev = ptr;
        ptr->next = head;
        head = ptr;
    }
}

void atspecificpos(int ele, int pos)
{
    NODE *temp = NULL, *temp2 = NULL, *ptr = NULL;
    ptr = malloc(sizeof(NODE));
    ptr->prev = NULL;
    ptr->data = ele;
    ptr->next = NULL;
    temp = head;

    while (pos--){
        if(pos == 1){
            if(temp->next == NULL){
                temp->next = ptr;
                ptr->prev = temp;
            }
            else{
                temp2 = temp->next;
                temp->next = ptr;
                temp2->prev = ptr;
                ptr->prev = temp;
                ptr->next = temp2;
            }
        }
        temp = temp->next;
    }
}

void display()
{
    NODE *temp = NULL;
    temp = head;

    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void search(int ele)
{
    NODE *temp = NULL;
    int pos = 1;
    temp = head;

    while (temp != NULL){
        if(temp->data == ele){
            printf("\n%d element found at %d node\n", ele, pos);
            break;
        }
        pos++;
        temp = temp->next;
    }
}

void delete(int pos)
{
    int loc = pos;
    NODE *current = NULL;
    current = head;

    if(head == NULL){
        printf("\nList is already empty\n");
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else if(pos == 1){
        current = head;
        head = head->next;
        head->prev = NULL;
        free(current);
        current = NULL;
    }
    else{
        while (pos != 1){
            current = current->next;
            pos--;
        }
        if(current->next == NULL){
            current->prev->next = NULL;
            free(current);
            current = NULL;
        }
        else {
            current->next->prev = current->prev;
            current->prev->next = current->next;
            free(current);
            current = NULL;
        }
    }
    printf("\nNode %d is deleted\n", loc);
}

void reverse()
{
    NODE *temp = NULL;

    temp = head->next;
    head->next = NULL;

    while (temp != NULL){
        head->prev = temp;
        temp->prev = temp->next;
        temp->next = head;
        head = head->prev;
        temp = temp->prev;
    }
}