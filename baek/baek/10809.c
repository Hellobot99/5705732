#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    char s[101];
    char t[] = "abcdefghijklmnopqrstuvwxyz";
    scanf("%s", &s);
    
    for (int k1 = 0; k1 < 26; k1++) {
        for (int i1 = 0; i1 < 101; i1++) {
            if (s[i1] == t[k1]) { printf("%d ", i1); break; }
            if (i1 == 100) { printf("-1 "); }
        }
    }
  
    return 0;
}