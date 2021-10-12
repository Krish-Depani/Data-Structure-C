#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;

void insert(int ele);
void delete();
void display();

NODE *front = NULL, *rear = NULL;

int main()
{
    int choice, ele;

    while (1){
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to be entered : ");
                scanf("%d", &ele);
                insert(ele);
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

void insert(int ele)
{
    NODE *ptr = malloc(sizeof(NODE));
    ptr->data = ele;
    ptr->next = NULL;

    if(rear == NULL){
        front = rear = ptr;
        return;
    }
    rear->next = ptr;
    rear = ptr;
}

void delete()
{
    if(front == NULL){
        printf("\nQueue is empty!!\n");
        return;
    }
    else if(front->next == NULL){
        free(front);
        front = NULL;
        rear = NULL;
        return;
    }
    NODE *temp = front;
    front = front->next;
    free(temp);
}

void display()
{
    if(front == NULL){
        printf("\nQueue is empty!!\n");
        return;
    }

    NODE *ptr = NULL;
    ptr = front;

    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
