#include <stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 30

typedef int element;
typedef struct
{
    element data[MAX];
    int top;
}stacktype;

int is_empty(stacktype *s)
{
    return(s->top == -1);
}

int is_full(stacktype *s)
{
    return(s->top == MAX - 1);
}

void push(stacktype *s,element item)
{
    if (is_full(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    else s->data[++s->top] = item;
}

element pop(stacktype *s)
{
    if (is_empty(s))
    {
        return 0;
    }
    else return s->data[s->top--];
}

void init_stack(stacktype* s) {
    s->top = -1;
}

int eval(char* expr)
{
    int op1, op2;
    stacktype s;
    init_stack(&s);
    for (int i = 0; expr[i] != '\0'; i++)
    {
        printf("expression : %c\n", expr[i]);
        if (expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/' && expr[i] != ' ')
        {
            int value = expr[i] - '0';
            push(&s, value);
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            op2 = pop(&s); 
            op1 = pop(&s); 
            switch (expr[i])
            {
            case '+':
                push(&s, op1 + op2);
                break;
            case '-':
                push(&s, op1 - op2);
                break;
            case '*':
                push(&s, op1 * op2);
                break;
            case '/':
                push(&s, op1 / op2);
                break;
            }
        }
    }
    return pop(&s);
}

int main()
{
    char arr[MAX];
    int result;
    
    fgets(arr, sizeof(arr), stdin);
    int len = strlen(arr);
    arr[len-1] = '\0';
    printf("postfix Expression: %s\n", arr);
    result = eval(arr);
    printf("결과값은 : %d\n", result);

    return 0;
}