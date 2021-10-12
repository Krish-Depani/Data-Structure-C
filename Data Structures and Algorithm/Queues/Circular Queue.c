#include "stdio.h"
#include "stdlib.h"
#define MAX 10

void insert(int ele);
void delete();
void display();

int que[MAX];
int front = -1, rear = -1;

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
    if (rear == MAX-1 && front == 0){
        printf("\nQueue is Full!!\n");
        return;
    }
    else if(front == -1 && rear == -1)
        front = rear = 0;
    else if(rear == MAX-1 && front != 0)
        rear = 0;
    else
        rear += 1;
    que[rear] = ele;
}

void delete()
{
    if(front == -1 && rear == -1) {
        printf("\nQueue is empty\n");
        return;
    }
    else if(front == rear)
        front = rear = -1;
    else if(front == MAX-1)
        front = 0;
    else
        front += 1;
}

void display()
{
    int temp;

    if(front == -1 && rear == -1) {
        printf("\nQueue is empty\n");
        return;
    }
    if(front < rear){
        temp = front;
        while (temp != rear){
            printf("%d ", que[temp]);
            temp++;
        }
    }
    else{
        for(temp = front; temp < MAX; temp++)
            printf("%d ", que[temp]);
        for(temp = 0; temp <= rear; temp++)
            printf("%d ", que[temp]);
    }
}