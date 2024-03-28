#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

struct student {
    int age;
    char name[30];
};

int main()
{
    struct student s1;

    s1.age = 21;
    strcpy(s1.name, "asd");

    return 0;
}