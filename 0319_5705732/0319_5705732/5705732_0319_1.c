#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//���丮�� 

int factorial_rec(int n) {
    if (n <= 1) return(1);
    else return(n * factorial_rec(n - 1));

}

int factorial_iter(int n) {
    int a, b = 1;
    for (a = n; a > 0; a--) {
        b = b * a;
    }
    return(b);
}

int main(int argc, char* argv[])
{

    clock_t start_iter, end_iter, start_rec, end_rec;
    double duration_iter, duration_rec;

    start_iter = clock();
    long result_iter = factorial_iter(20);
    end_iter = clock();

    start_rec = clock();
    long result_rec = factorial_rec(20);
    end_rec = clock();
   
    printf("Factorial Iterative Result: %f\n", (float)(end_iter - start_iter) / CLOCKS_PER_SEC);
    printf("Factorial Recursive Result: %f\n", (float)(end_rec - start_rec) / CLOCKS_PER_SEC);


    return 0;
}

/* ������� ���������� �ٸ� �����Ϸ������� ������ ������ visual studio ������ ������ 0�ʷθ� ���� �ٸ� �����Ϸ��� �����߽��ϴ�.
(�Է°��� 20���� �Է��� ���)
Factorial Iterative Result: 0.000002
Factorial Recursive Result: 0.000001

(�Է°��� 2200���� �Է��� ���)
Factorial Iterative Result: 0.000007
Factorial Recursive Result: 0.000049

�Է°��� ���� �ʱ⿡�� �ݺ��� ��ȯ���� �� �����ɷ�����, �Է°��� �ø��� �ø����� �ݺ����� ��ȯ�� �� �����ɸ��°��� ������ �� �־���
*/