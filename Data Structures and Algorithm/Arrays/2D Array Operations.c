#include "stdio.h"

void addition(int [][3],int [][3], int rows, int cols);
void subtraction(int [][3],int [][3], int rows, int cols);
void multiplication(int [][3],int [][3], int rows, int cols);
void transpose(int [][3], int rows, int cols);

int main()
{
    int arr1[3][3], arr2[3][3], rows, cols, choice, ch;

    printf("Enter the number of rows : ");
    scanf("%d", &rows);
    printf("\nEnter the number of cols : ");
    scanf("%d", &cols);

    printf("\nEnter the elements of matrix A\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("\nEnter the elements of matrix B\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n");
    printf("\nEnter the choice : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addition(arr1, arr2, rows, cols);
            break;
        case 2:
            subtraction(arr1, arr2, rows, cols);
            break;
        case 3:
            multiplication(arr1, arr2, rows, cols);
            break;
        case 4:
            printf("\nEnter the matrix(1 for A and 2 for B) : ");
            scanf("%d", &ch);
            switch (ch) {
                case 1:
                    transpose(arr1, rows, cols);
                    break;
                case 2:
                    transpose(arr2, rows, cols);
                    break;
                default:
                    printf("\nEnter proper choice!!");
            }
            break;
        default:
            printf("\nEnter proper choice!!");
    }
}

void addition(int arr1[3][3], int arr2[3][3], int rows, int cols)
{
    int sum[3][3];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printf("\nAddition of array is\n");
    for (int i = 0; i < rows; i++) {
        printf("\t");
        for (int j = 0; j < cols; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
}

void subtraction(int arr1[3][3], int arr2[3][3], int rows, int cols)
{
    int diff[3][3];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            diff[i][j] = arr1[i][j] - arr2[i][j];
        }
    }

    printf("\nSubtraction of array is\n");
    for (int i = 0; i < rows; i++) {
        printf("\t");
        for (int j = 0; j < cols; j++) {
            printf("%d\t", diff[i][j]);
        }
        printf("\n");
    }
}

void multiplication(int arr1[3][3], int arr2[3][3], int rows, int cols)
{
    int pro[3][3];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pro[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                pro[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    printf("\nMultiplication of array is\n");
    for (int i = 0; i < rows; i++) {
        printf("\t");
        for (int j = 0; j < cols; j++) {
            printf("%d\t", pro[i][j]);
        }
        printf("\n");
    }
}

void transpose(int arr1[3][3], int rows, int cols)
{
    int trans[3][3];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trans[i][j] = arr1[j][i];
        }
    }

    printf("\nTranspose of matrix A is\n");
    for (int i = 0; i < rows; i++) {
        printf("\t");
        for (int j = 0; j < cols; j++) {
            printf("%d\t", trans[i][j]);
        }
        printf("\n");
    }
}