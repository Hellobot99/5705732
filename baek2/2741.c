#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    int a;
    scanf("%d",&a);
    for (int i = 1; i < a+1; i++)
    {
        printf("%d\n", i);
    }

    return 0;
}