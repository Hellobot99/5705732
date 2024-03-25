#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    char spell[16];
    int result = 0;
    scanf("%s", &spell);

    char a2[] = "ABC" ,a3[]="DEF", a4[]="GHI",a5[]="JKL",a6[]="MNO",a7[]="PQRS",a8[]="TUV",a9[]="WXYZ";
    
    for (int i = 0; i < strlen(spell); i++) 
    {
        for (int k = 0; k < 4; k++)
        {
            if (a2[k] == spell[i]) result = result + 3;
            if (a3[k] == spell[i]) result = result + 4;
            if (a4[k] == spell[i]) result = result + 5;
            if (a5[k] == spell[i]) result = result + 6;
            if (a6[k] == spell[i]) result = result + 7;
            if (a7[k] == spell[i]) result = result + 8;
            if (a8[k] == spell[i]) result = result + 9;
            if (a9[k] == spell[i]) result = result + 10;
        }

    }

    printf("%d", result);

    return 0;
}