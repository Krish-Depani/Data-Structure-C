#include "stdio.h"
#include "string.h"

int main()
{
    char txt[100], pat[20];
    int i, j, m, n;

    printf("Enter a text : ");
    scanf("%s", txt);
    printf("\nEnter a pattern : ");
    scanf("%s", pat);

    n = strlen(txt);
    m = strlen(pat);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if(txt[i+j] != pat[j])
                break;
        }
        if(j == m)
        {
            printf("\nThe pattern found at position %d", i);
            i++;
        }
    }
}