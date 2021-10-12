#include "stdio.h"
#include "ctype.h"
#include "math.h"

void push(int x);
int pop();

int stk[30];
int top = -1;

void push(int x)
{
    stk[++top] = x;
}

int pop()
{
    return stk[top--];
}

void main()
{
    char exp[30], *e;
    int n1, n2, n3, num;

    printf("\nEnter the expression : ");
    scanf("%s", exp);
    e = exp;

    while (*e != '\0')
    {
        if(isdigit(*e)){
            num = *e - '0';
            push(num);
        }
        else{
            n1 = pop();
            n2 = pop();

            switch (*e) {
                case '+':
                    n3 = n2 + n1;
                    break;
                case '-':
                    n3 = n2 - n1;
                    break;
                case '*':
                    n3 = n2 * n1;
                    break;
                case '/':
                    n3 = n2 / n1;
                    break;
                case '^':
                    n3 = pow(n1, n2);
                    break;
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe evaluation of %s expression is %d", exp, pop());
}