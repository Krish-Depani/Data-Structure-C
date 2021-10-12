#include "stdio.h"
#include "stdlib.h"

#define MAX 20

void push();
void pop();
void display();

int stk[MAX], top = -1;

int main()
{
    int choice;

    while (1){

        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid Choice");
        }
    }
}

void push()
{
    int item;

    if(top > MAX)
    {
        printf("\nStack overflow. Cannot add element\n");
    }
    else
    {
        top += 1;
        printf("\nEnter the element to be entered : ");
        scanf("%d", &item);
        stk[top] = item;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("\nCannot delete element stack is empty\n");
    }
    else
    {
        top -= 1;
    }
}

void display()
{
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stk[i]);
    }
}