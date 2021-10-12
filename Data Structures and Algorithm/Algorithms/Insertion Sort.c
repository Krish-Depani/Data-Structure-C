#include "stdio.h"

int main()
{
    int arr[20], n, key;

    printf("Enter the array size : ");
    scanf("%d", &n);
    printf("\nEnter the array elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++) {
        key = arr[i];

        for (int j = i-1; j >= 0 && key < arr[j]; j--) {
            arr[j+1] = arr[j];
            arr[j] = key;
        }
    }

    printf("\nSorted array is\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}