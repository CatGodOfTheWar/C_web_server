#include <stdio.h>
#include <stdlib.h>

void ERROR(int n)
{
    if (n < 0)
    {
        perror("write");
        return;
    }
}