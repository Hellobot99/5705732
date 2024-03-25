#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

//�ϳ��� ž �ð�����

void hanoi_rec(int n, char start, char end, char middle) //n���� middle�� �̿��ؼ� start���� end�� �ű�� �Լ�
{
    if (n == 1)printf("���� 1�� %c���� %c���� �ű��.\n", start, end); //1���̸� start���� end�� �ű��.
    else {
        hanoi_rec(n - 1, start, end, middle); //1���� �ƴϸ� n-1���� end�� �̿��ؼ� start���� mid�� �ű�� �Լ�
        printf("���� %d�� %c���� %c���� �ű��\n", n, start, end); //n�� �������� �� �����ϱ� start���� c�� �ű�
        hanoi_rec(n - 1, middle, start, end); //�׸��� n-1���� start�� �̿��ؼ� middle���� end�� �ű�� �Լ�
    }
    
}

int main()
{
    hanoi_rec(3, 'A', 'B', 'C');
    return 0;
}

/*int main()
{

    clock_t start_iter, end_iter, start_rec, end_rec;
    double duration_iter, duration_rec;

    start_rec = clock();
    double result_rec = fib_rec(44);
    end_rec = clock();

    start_iter = clock();
    double result_iter = fib_iter(44);
    end_iter = clock();

    printf("Fib Recursive Result: %f\n", (float)(end_rec - start_rec) / CLOCKS_PER_SEC); //��ȯ �ð�
    printf("Fib Iterative Result: %f\n", (float)(end_iter - start_iter) / CLOCKS_PER_SEC); //�ݺ� �ð�

    return 0;
}*/