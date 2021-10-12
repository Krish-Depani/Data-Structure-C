#include "stdio.h"
#include "ctype.h"

void push(char x);
int pop();
int priority(char x);

char stk[20];
int top = -1;

void push(char x)
{
    stk[++top] = x;
}

int pop()
{
    if(top == -1)
        return -1;
    else
        return stk[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    else if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    return 0;
}

void main()
{
    char exp[30], *e, x;

    printf("\nEnter the expression : ");
    scanf("%s", exp);
    printf("\n");
    e = exp;

    while (*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ", *e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')'){
            while ((x = pop()) != '(')
                printf("%c ", x);
        }
        else{
            while (priority(stk[top]) >= priority(*e))
                printf("%c ", pop());
            push(*e);
        }
        e++;
    }

    while (top != -1){
        printf("%c ", pop());
    }
}