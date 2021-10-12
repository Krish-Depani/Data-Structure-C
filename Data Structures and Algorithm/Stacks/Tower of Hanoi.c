#include "stdio.h"

void towerofhanoi(int n, char x, char y, char z);

int main()
{
    int n;

    printf("Enter the number of disks : ");
    scanf("%d", &n);

    towerofhanoi(n, 'A', 'B', 'C');
    return 0;
}

void towerofhanoi(int n, char x, char y, char z)
{
    if(n == 1){
        printf("\nMove disk 1 from rod %c to rod %c", x, y);
        return;
    }
    towerofhanoi(n-1, x, z, y);
    printf("\nMove disk %d from rod %c to rod %c", n, x, y);
    towerofhanoi(n-1, z, y, x);
}
