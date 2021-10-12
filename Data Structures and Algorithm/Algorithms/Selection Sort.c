#include "stdio.h"

int main()
{
    int arr[20], i, j, n, small, loc;

    printf("Enter the array size : ");
    scanf("%d", &n);
    printf("\nEnter the array elements\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        small = arr[i];
        loc = i;

        for (j = i+1; j < n; j++) {
            if(arr[j] < small)
            {
                small = arr[j];
                loc = j;
            }
        }

        arr[loc] = arr[i];
        arr[i] = small;
    }

    printf("\nSorted array is\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}