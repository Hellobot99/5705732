#include <stdio.h>
#include <string.h>

#define Max 101

typedef struct
{
    float coef;
    int expon;
} terms;

terms term[Max] = { {8, 3}, {7, 1}, {1.0}, {10, 3}, {3, 2}, {1.0} };
int avail = 6;

void poly_add(int As, int Ae, int Bs, int Be, int* Cs, int* Ce)
{
    int C = avail;
    *Cs = C;

    while ((As <= Ae) && (Bs <= Be))
    {
        if (term[As].expon > term[Bs].expon)
        {
            term[C].expon = term[As].expon;
            term[C].coef = term[As].coef;
            As++;
        }
        else if (term[As].expon == term[Bs].expon)
        {
            term[C].expon = term[Bs].expon;
            term[C].coef = term[As].coef + term[Bs].coef;
            As++;
            Bs++;
        }
        else
        {
            term[C].expon = term[Bs].expon;
            term[C].coef = term[Bs].coef;
            Bs++;
        }
        C++;
    }

    for (; Bs <= Be; Bs++)
    {
        term[C].expon = term[Bs].expon;
        term[C].coef = term[Bs].coef;
        C++;
    }
    for (; As <= Ae; As++)
    {
        term[C].expon = term[As].expon;
        term[C].coef = term[As].coef;
        C++;
    }

    *Ce = C - 1;
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
    poly_add(0, 2, 3, 5, &Cs, &Ce);
    print_poly(Cs, Ce);
    return 0;
}
