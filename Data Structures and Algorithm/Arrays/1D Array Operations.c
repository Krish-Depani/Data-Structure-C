#include "stdio.h"

void insert(int [], int n);
void delete(int [], int n);

int main()
{
    int choice, arr[20], n;

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    printf("\nEnter the array elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n1. Insertion\n2. Deletion\n");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insert(arr, n);
            break;
        case 2:
            delete(arr, n);
            break;
        default:
            printf("\nEnter valid choice!!");
    }
}

void insert(int arr[], int n)
{
    int ele, loc;

    printf("\nEnter the element to be entered : ");
    scanf("%d", &ele);
    printf("\nEnter the location of element : ");
    scanf("%d", &loc);

    for (int i = n; i >= loc; i--) {
        arr[i+1] = arr[i];
    }
    arr[loc] = ele;
    n += 1;

    printf("\nArray after insertion\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void delete(int arr[], int n)
{
    int loc;

    printf("\nEnter the location of element to be deleted : ");
    scanf("%d", &loc);

    for (int i = loc; i < n; i++) {
        arr[i] = arr[i+1];
    }
    n -= 1;

    printf("\nArray after deletion\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}