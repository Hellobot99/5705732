#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct 
{
	int age;
	char name[20];
}student;


print_stu(student* sp, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d %s\n", sp[i].age, sp[i].name);
	}
}



main(void)
{
	student *sp;
	int num;
	student s;
	
	printf("ÇÐ»ý¼ö: ");
	scanf("%d", &num);

	sp = (student *)malloc(sizeof(student) * num);
	sp[0].age = 221;
	strncpy(sp[0].name, "asd",20);
	sp[1].age = 22;
	strncpy(sp[1].name, "ddd", 20);


	print_stu(sp, 2);
	
	free(sp);
	return 0;
}