/*	���� "���׽� ���� ���α׷�(2)" ������ ����ü �迭�� ����Ͽ� ���׽��� ���α׷��� ǥ���Ͽ���

�ΰ��� ���׽��� ���ϴ� �Լ��� �ۼ��Ͽ���.



�̹� ������ ���׽� 2���� �Է� �ް� �Է� ���� 2���� ���׽��� ���ϴ� ���α׷��� �ۼ��Ѵ�.

2���� ���׽��� ������ ���� �Է� �޴´�.

------------------------------------------------------------------ -

���׽��� �� ���� ���� �Է��Ͻÿ� ? 4

������ ���� ���ʷ� ����� ������ �Է��Ͻÿ� ?

[���, ����] 4.0 3

[���, ����] 3.0 2

[���, ����] 2.0 1

[���, ����] 1.0 0

�Էµ� ���׽��� ������ �����ϴ� : 4x ^ 3 + 3x ^ 2 + 2x + 1

---------------------------------------------------------------------- -



�Է� ���� ���� �� ��ŭ ���� �Ҵ����� �� ���׽��� �����ϱ� ���� ����ü �迭�� ������ �Ѵ�.

2���� ���׽��� ���ϴ� �Լ��� �����Ͽ� ��ü ���α׷��� ����ü �����͸� ����Ͽ��� �Ѵ�.

����ü �迭�� �ε����� ������� �ʴ´�.*/

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