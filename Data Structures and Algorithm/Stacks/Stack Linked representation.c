#include "stdio.h"
#include "stdlib.h"

void push();
void pop();
void display();

struct stack{
    int element;
    struct stack *next;
} *top;

void main()
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
    struct stack *ptr;
    int ele;

    printf("\nEnter the element to be entered : ");
    scanf("%d", &ele);

    ptr = (struct stack*) malloc(sizeof (struct stack));

    ptr->element = ele;
    ptr->next = top;
    top = ptr;
}

void pop()
{
    if(top == NULL)
    {
        printf("\nStack is empty");
    }
    else
    {
        top = top->next;
    }
}

void display()
{
    struct stack *ptr;

    ptr = top;

    printf("\nElements of stack are\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->element);
        ptr = ptr->next;
    }
}