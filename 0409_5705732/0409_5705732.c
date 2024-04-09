#include <stdio.h>
#include <string.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 5

typedef int element;
element stack[MAX];
int top=-1;

int is_empty()
{
    return(top == -1);
}

int is_full()
{
    return(top == MAX-1);
}

void push(element item)
{
    if (is_full())
    {
        printf("Stack Overflow\n");
        return;
    }
    else stack[++top] = item;
}

element pop()
{
    if (is_empty())
    {
        //printf("Stack is empty\n");
        //exit(1);
    }
    else return stack[top--];
}

element peek()
{
    if (is_empty())
    {
        printf("스택이 공백입니다.\n");
    }
    else return stack[top];
}

int main()
{
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
            push(rand_num);

            if (is_empty()) printf("Stack is empty\n\n");
            else
            {
                printf("Stack elements: ");
                for (int k = 0; k < top; k++)
                {
                    printf("%d ", stack[k]);
                }
                printf("%d\n\n", stack[top]);
            }
        }
        else
        {
            printf("Odd\n");
            printf("Pop : %d\n", rand_num);
            pop();
            
            if (is_empty()) printf("Stack is empty\n\n");
            else
            {
                printf("Stack elements: ");
                for (int k = 0; k < top; k++)
                {
                    printf("%d ", stack[k]);
                }
                printf("%d\n\n", stack[top]);
            }
        }
    }

    return 0;
}

