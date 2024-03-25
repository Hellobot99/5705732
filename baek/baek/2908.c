#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    char c[2], d[2];
    char a[4], b[4];
    scanf("%s %s", &a, &b);

       
    c[0] = a[2], d[0] = b[2];
    a[2] = a[0], b[2] = b[0];
    a[0] = c[0], b[0] = d[0];

    if (a[0] > b[0]) printf("%s", a);
    else if (a[0] < b[0]) printf("%s", b);
    else if (a[1] > b[1]) printf("%s", a);
    else if (a[1] < b[1]) printf("%s", b);
    else if (a[2] < b[2]) printf("%s", b);
    else printf("%s", a);
    
    return 0;
}