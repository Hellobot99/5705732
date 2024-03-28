#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    int num,a,total=0;
    char quiz[800];
    int score[800];
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%s", &quiz);
        a = strlen(quiz);
       
        for (int k = 1; k < a; k++)
        {
            if (quiz[k] == 'X') { score[k] = 0; }
            else if (quiz[ k - 1] != 'O') { score[k] = 1; }
            else if (quiz[k - 1] == 'O') { score[k] = score[ k - 1] + 1; }
        }
        for (int j=0; j < a; j++)
        {
            total = total + score;
        }
        printf("%d\n", total);
        }

    return 0;
}