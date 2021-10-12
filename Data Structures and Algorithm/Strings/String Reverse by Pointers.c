#include <stdio.h>

int main()
{
    char *name, *i, *cptr;
    name = "Hello";
    cptr = name;

    while (*cptr != '\0')
    {
        cptr++;
    }

    for (i = cptr-1; i >= name; i--)
    {
        printf("%c", *i);
    }
    return 0;
}