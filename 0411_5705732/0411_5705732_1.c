#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 5


typedef int element;
typedef struct
{
    element* stack[MAX];
    int top;
}stacktype;

void init_stack(stacktype* sptr)
{
    sptr->top = -1;
}

int is_empty(stacktype* sptr)
{
    return((sptr->top) == -1);
}

int is_full(stacktype* sptr)
{
    return((sptr->top) == MAX-1);
}

void push(stacktype* sptr, element item)
{
    if (is_full(sptr))
    {
        printf("Stack Overflow");
    }
   else sptr->stack[++(sptr->top)] = item;
}

element pop(stacktype* sptr)
{
    if (is_empty(sptr));    
    else return sptr->stack[sptr->top--];
}

element peek(stacktype* sptr)
{
    if (is_empty(sptr))
    {
        printf("Stack is empty\n");
    }
    else return sptr->stack[sptr->top];
}
int main()
{
    stacktype st1;
    init_stack(&st1);

    srand(time(NULL));

    int rand_num = 0;


    for (int i = 0; i < 30; i++)
    {
        rand_num = rand() % 100 + 1;
        printf("current rand_num : %d | ", rand_num);


        if (rand_num % 2 == 0)
        {
            printf("EVEN\n");
            printf("Push : %d\n", rand_num);
            push(&st1,rand_num);

            if (is_empty(&st1)) printf("Stack is empty\n\n");
            else
            {
                printf("Stack elements: ");
                for (int k = 0; k < st1.top; k++)
                {
                    printf("%d ", st1.stack[k]);
                }
                printf("%d\n\n", st1.stack[st1.top]);
            }
        }
        else
        {
            printf("Odd\n");
            printf("Pop : %d\n", rand_num);
            pop(&st1);

            if (is_empty(&st1)) printf("Stack is empty\n\n");
            else
            {
                printf("Stack elements: ");
                for (int k = 0; k < st1.top; k++)
                {
                    printf("%d ", st1.stack[k]);
                }
                printf("%d\n\n", st1.stack[st1.top]);
            }
        }
    }

    return 0;

}
