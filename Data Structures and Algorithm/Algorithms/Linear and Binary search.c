#include "stdio.h"

void linearsearch(int arr[], int n, int ele);
void binarysearch(int arr[], int n, int ele);

int main()
{
    int arr[20], n, ele, choice;

    printf("Enter the size of array : ");
    scanf("%d", &n);
    printf("\nEnter the array elements\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the element to be searched : ");
    scanf("%d", &ele);

    printf("\n1. Linear Search\n2. Binary Search\n");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    switch(choice) {
        case 1 :
            linearsearch(arr, n, ele);
            break;
        case 2:
            binarysearch(arr, n, ele);
            break;
        default:
            printf("\nEnter proper choice!!");
    }
}

void linearsearch(int arr[], int n, int ele)
{
    for (int i = 0; i < n; i++) {
        if(arr[i] == ele){
            printf("\nElement found at %d location", i);
            break;
        }
    }
}

void binarysearch(int arr[], int n, int ele)
{
    int low, high, mid;

    low = 0;
    high = n-1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == ele)
        {
            printf("\nElement found at %d location", mid);
            return;
        }
        if(ele > arr[mid])
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    printf("\nElement is not in the array");
}