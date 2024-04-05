/*	앞의 "다항식 곱셈 프로그램(2)" 문제는 구조체 배열을 사용하여 다항식을 프로그램에 표현하였고

두개의 다항식을 곱하는 함수를 작성하였다.



이번 문제는 다항식 2개를 입력 받고 입력 받은 2개의 다항식을 곱하는 프로그램을 작성한다.

2개의 다항식은 다음과 같이 입력 받는다.

------------------------------------------------------------------ -

다항식의 총 항의 수를 입력하시오 ? 4

고차항 부터 차례로 계수와 지수를 입력하시오 ?

[계수, 차수] 4.0 3

[계수, 차수] 3.0 2

[계수, 차수] 2.0 1

[계수, 차수] 1.0 0

입력된 다항식은 다음과 같습니다 : 4x ^ 3 + 3x ^ 2 + 2x + 1

---------------------------------------------------------------------- -



입력 받은 항의 수 만큼 동적 할당으로 이 다항식을 저장하기 위한 구조체 배열을 만들어야 한다.

2개의 다항식을 곱하는 함수를 포함하여 전체 프로그램은 구조체 포인터를 사용하여야 한다.

구제체 배열의 인덱스를 사용하지 않는다.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    float coef;
    int expon;
} terms;

terms term[Max] = { {4, 3}, {3, 2}, {2, 1}, {1 ,0},
                    {3, 2}, {2, 1}, {8, 0} };
int avail = 7;

void poly_mul(int As, int Ae, int Bs, int Be, int* Cs, int* Ce)
{
    int j;
    int C = avail;
    *Cs = C; 

    for (int i = As; i < Ae + 1; i++)
    {
        for (int k = Bs; k < Be + 1; k++)
        {

            for (j = avail; j < C; j++)
            {
                if (term[i].expon + term[k].expon == term[j].expon)
                {
                    term[j].coef += term[i].coef * term[k].coef; break;
                }

            }

            if (j == C)
            {
                term[C].expon = term[i].expon + term[k].expon;
                term[C].coef = term[i].coef * term[k].coef;
                C++;
                *Ce = C - 1;
            }
            if (C == avail)
            {
                term[C].expon = term[i].expon + term[k].expon;
                term[C].coef = term[i].coef * term[k].coef;
                C++;
                *Ce = C - 1;
            }


        }
    }


}

void print_poly(int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        printf("%3.0fx^%d ", term[i].coef, term[i].expon);
        if (i != e)
            printf("+ ");
    }
    printf("\n");
}

int main()
{
    int Cs, Ce;
    poly_mul(0, 3, 4, 6, &Cs, &Ce);
    print_poly(Cs, Ce);
    return 0;
}