#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;

NODE *tail = NULL;

void insert(int ele, int pos);
void atbeginning(int ele);
void delete(int pos);
void atspecificpos(int ele, int pos);
void search(int ele);
void display();
void reverse();
int len();

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
    if (pos == 1){
        atbeginning(ele);
        return;
    }
    else{
        atspecificpos(ele, pos);
        return;
    }
}

void atbeginning(int ele)
{
    NODE *ptr;
    ptr = malloc(sizeof(NODE));
    ptr->data = ele;

    if (tail == NULL){
        ptr->next = ptr;
        tail = ptr;
    }
    else{
        ptr->next = tail->next;
        tail->next = ptr;
    }
}

void atspecificpos(int ele, int pos)
{
    NODE *ptr, *temp;
    int length = len();
    ptr = malloc(sizeof(NODE));
    ptr->data = ele;
    temp = tail->next;

    if (pos > length+1 || pos < 1) {
        printf("\nImproper position\n");
        return;
    }
    else{
        while (pos--) {
            if (pos == 1) {
                ptr->next = temp->next;
                temp->next = ptr;
                if (temp == tail) {
                    tail = tail->next;
                }
                break;
            }
            temp = temp->next;
        }
    }
}

void display()
{
    NODE *temp;
    temp = tail->next;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
}

int len()
{
    NODE *temp;
    int pos = 0;
    temp = tail->next;

    if (tail == NULL)
        return pos;

    do {
        pos += 1;
        temp = temp->next;
    } while (temp != tail->next);

    return pos;
}

void delete(int pos)
{
    int loc = pos, length = len();

    if (pos > length+1 || pos < 1) {
        printf("\nImproper position\n");
        return;
    }
    if (tail == NULL) {
        printf("\nList is empty\n");
        return;
    }
    else if(tail->next == tail){
        free(tail);
        tail = NULL;
        goto xy;
    }
    else {
        NODE *curr;
        curr = tail->next;

        if(pos == 1){
            tail->next = curr->next;
            free(curr);
            goto xy;
        }
        else{
            NODE *prev;

            while (pos != 1){
                prev = curr;
                curr = curr->next;
                pos--;
            }
            prev->next = curr->next;
            if(curr == tail)
                tail = prev;
            free(curr);
            goto xy;
        }
    }
    xy : printf("\nNode %d is deleted\n", loc);
}

void search(int ele)
{
    int count = 1;
    NODE *temp;
    temp = tail->next;

    do {
        if(temp->data == ele){
            printf("\nElement %d found at node %d\n", ele, count);
            return;
        }
        count++;
        temp = temp->next;
    } while (temp != tail->next);

    printf("\nElement not found!!\n");
}