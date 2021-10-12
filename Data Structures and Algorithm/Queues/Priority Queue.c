#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    int prio;
    struct node *next;
};
typedef struct node NODE;

NODE *head = NULL;

void insert(int ele, int prio);
void delete();
void display();

int main()
{
    int choice, ele, prio;

    while (1){
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to be entered : ");
                scanf("%d", &ele);
                printf("\nEnter the priority : ");
                scanf("%d", &prio);
                insert(ele, prio);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nEnter proper choice!!\n");
        }
    }
}

void insert(int ele, int prio)
{
    NODE *ptr = malloc(sizeof(NODE)), *temp = head;
    ptr->data = ele;
    ptr->prio = prio;
    ptr->next = NULL;

    if(head == NULL || prio < head->prio){
        ptr->next = head;
        head = ptr;
    }
    else{
        while (temp->next != NULL && temp->next->prio <= prio){
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void display()
{
    NODE *temp = head;

    while (temp != NULL){
        printf("\nElement = %d, Priority = %d\n", temp->data, temp->prio);
        temp = temp->next;
    }
}

void delete()
{
    NODE *temp = head;

    if(head == NULL){
        printf("\nQueue Underflow\n");
        return;
    }
    head = head->next;
    free(temp);
}
