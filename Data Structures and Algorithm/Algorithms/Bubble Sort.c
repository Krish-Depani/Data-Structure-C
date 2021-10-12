#include "stdio.h"

int main()
{
    int arr[20], i, j, n, temp;

    printf("Enter the size of array : ");
    scanf("%d", &n);
    printf("\nEnter the array elements\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++)
    {
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nSorted array is\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}