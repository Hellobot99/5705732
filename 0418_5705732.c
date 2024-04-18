#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 30

typedef int element;
typedef struct
{
    element data[MAX];
    int top;
}stacktype;

int is_empty(stacktype* s)
{
    return(s->top == -1);
}

int is_full(stacktype* s)
{
    return(s->top == MAX - 1);
}

void push(stacktype* s, element item)
{
    if (is_full(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    else s->data[++s->top] = item;
}

element pop(stacktype* s)
{
    if (is_empty(s))
    {
        return 0;
    }
    else return s->data[s->top--];
}

element peek(stacktype* s)
{
    if (is_empty(s))
    {
        printf("½ºÅÃÀÌ °ø¹éÀÔ´Ï´Ù.\n");
    }
    else return s->data[s->top];
}

void init_stack(stacktype* s) {
    s->top = -1;
}

int prec(char op)
{
    switch (op)
    {
    case'+':case'-':return 1;
    case'*':case'/':return 2;
    case'(':case')': return 0;
    }
}

int eval(char* expr)
{
    int op1, op2;
    stacktype s;
    init_stack(&s);
    for (int i = 0; expr[i] != '\0'; i++)
    {

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

int eval_middle(char* expr)
{
    int len = strlen(expr), a = 0;
    char top_op, ch;
    stacktype s;
    init_stack(&s);
    char result[MAX];

    for (int i = 0; i < len; i++)
    {
        ch = expr[i];
        switch (expr[i])
        {
        case'+': case'-': case'*': case'/':
            while (!is_empty(&s) && prec(ch) <= prec((char)peek(&s)))
            {
                result[a++] = (char)pop(&s);                
            }
            push(&s, (int)ch);
            break;
        case'(':
            push(&s, (int)ch);
            break;
        case')':
            top_op = (char)pop(&s);
            while (top_op != '(')
            {
                result[a++] = top_op;                
                top_op = (char)pop(&s);
            }
            break;
        default:
            result[a++] = ch;            
            break;
        }
    }

    while (!is_empty(&s))
    {
        result[a++] = (char)pop(&s);
    }
    result[a] = '\0';
    printf("%s", result);
    return eval(result);

}


int main()
{
    char arr[MAX];
    int result, a;

    while (1)
    {
        printf("\n다음과 같은 메뉴로 동작하는 프로그램입니다.\n\n");
        printf("1. 중위식을 입력받음\n");
        printf("2. 중위식을 후위식으로 변환\n");
        printf("3. 후위식을 계산\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하세요: ");

        int choice;
        scanf("%d", &choice);
        int len;

        switch (choice)
        {
        case 1:
            printf("중위식을 입력하세요: ");
            getchar();
            fgets(arr, sizeof(arr), stdin);
            len = strlen(arr);
            arr[len - 1] = '\0';
            printf("입력된 중위식 : %s\n", arr);
            break;
        case 2:
            printf("후위식으로 변환된 식 : ");
            a = eval_middle(arr);
            printf("\n");
            break;
        case 3:
            printf("계산결과 : %d\n", a);
            break;
        case 4:
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 메뉴 선택입니다. 다시 선택하세요.\n");
            break;
        }
    }

    return 0;
}