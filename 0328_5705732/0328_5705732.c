#include <stdio.h>
#define MAX_DEGREE 101

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} Polynomial;

Polynomial poly_mul(Polynomial a, Polynomial b) {
    Polynomial c;
    c.degree = a.degree + b.degree;

    // ���׽� c�� ����� 0���� �ʱ�ȭ
    for (int i = 0; i <= c.degree; i++) {
        c.coef[i] = 0.0;
    }

    // ���׽��� ���� ����
    for (int i = 0; i <= a.degree; i++) {
        for (int j = 0; j <= b.degree; j++) {
            c.coef[i + j] += a.coef[i] * b.coef[j];
        }
    }

    return c;
}

void print_poly(Polynomial p) {

    for (int i = 0; i < p.degree; i++) {
        if (p.coef[i] != 0.0) {
            printf("%3.1fx^%d + ", p.coef[i], p.degree - i);
        }
    }
    printf("%3.1f\n", p.coef[p.degree]);
}

int main() {
    Polynomial a = { 6, {7.0, 0.0, 0.0, 5.0, 9.0, 0.0, 1.0} };
    Polynomial b = { 3, {5.0, 2.0, 1.0, 10.0} };
    Polynomial c;

    c = poly_mul(a, b);
    print_poly(c);

    return 0;
}