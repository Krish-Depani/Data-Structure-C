#include "stdio.h"
#include "stdlib.h"
#define MAX 10

void ip_res_que();
void op_res_que();
void insertright(int ele);
void insertleft(int ele);
void delright();
void delleft();
void display();

int que[MAX], left = -1, right = -1;

int main()
{
    int choice;

    while (1) {
        printf("\n1. Input restricted queue\n2. Output restricted queue\n3. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ip_res_que();
                break;
            case 2:
                op_res_que();
                break;
            case 3:
                exit(0);
            default:
                printf("\nEnter proper choice!!\n");
        }
    }
}

void ip_res_que()
{
    int choice, ele;

    while (1) {
        printf("\n1. Insert right\n2. Delete right\n3. Delete Left\n4. Display\n 5. Back\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element : ");
                scanf("%d", &ele);
                insertright(ele);
                break;
            case 2:
                delright();
                break;
            case 3:
                delleft();
                break;
            case 4:
                display();
                break;
            case 5:
                return;
            default:
                printf("\nEnter proper choice!!\n");
        }
    }
}

void op_res_que()
{
    int choice, ele;

    while (1) {
        printf("\n1. Insert right\n2. Insert left\n3. Delete right\n4. Display\n 5. Back\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element : ");
                scanf("%d", &ele);
                insertright(ele);
                break;
            case 2:
                printf("\nEnter the element : ");
                scanf("%d", &ele);
                insertleft(ele);
                break;
            case 3:
                delright();
                break;
            case 4:
                display();
                break;
            case 5:
                return;
            default:
                printf("\nEnter proper choice!!\n");
        }
    }
}

void insertright(int ele)
{
    if (left == 0 && right == MAX-1 || left == right+1){
        printf("\nQueue Overflow\n");
        return;
    }
    if (left == -1){
        left = right = 0;
    }
    else{
        if(right == MAX-1)
            right = 0;
        else
            right += 1;
    }
    que[right] = ele;
}

void insertleft(int ele)
{
    if (left == 0 && right == MAX-1 || left == right+1){
        printf("\nQueue Overflow\n");
        return;
    }
    if (left == -1){
        left = right = 0;
    }
    else{
        if(left == 0)
            left = MAX-1;
        else
            left -= 1;
    }
    que[left] = ele;
}

void delright()
{
    if (left == -1){
        printf("\nQueue Underflow\n");
        return;
    }
    if(left == right)
        left = right = -1;
    else{
        if(right == 0)
            right = MAX-1;
        else
            right -= 1;
    }
}

void delleft()
{
    if (left == -1){
        printf("\nQueue Underflow\n");
        return;
    }
    if(left == right)
        left = right = -1;
    else{
        if(left == MAX-1)
            left = 0;
        else
            left += 1;
    }
}

void display()
{
    if (left == -1){
        printf("\nQueue Underflow\n");
        return;
    }
    int temp1 = left, temp2 = right;

    if(left <= right){
        while (temp1 <= temp2){
            printf("%d ", que[temp1]);
            temp1++;
        }
    }
    else{
        while (temp1 <= MAX-1){
            printf("%d ", que[temp1]);
            temp1++;
        }
        temp1 = 0;
        while (temp1 <= temp2){
            printf("%d ", que[temp1]);
            temp1++;
        }
    }
    printf("\n");
}