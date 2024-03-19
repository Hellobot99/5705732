#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�ŵ�����

double power_rec(double x, int n) {
    if (n == 0) return(1);
    else if (n % 2 == 0) return power_rec(x * x, n / 2);
    else return x * power_rec(x * x, (n - 1) / 2);
 }

double power_iter(double x,int n) {
    int a;
    double b=1.0;
    for (a = n; a > 0; a--) {
        b = b * x;
    }
    return(b);
}

int main()
{

    clock_t start_iter, end_iter, start_rec, end_rec;
    double duration_iter, duration_rec;

    start_iter = clock();
    double result_iter = power_iter(13,21);
    end_iter = clock();
    
    start_rec = clock();
    double result_rec = power_rec(13,21);
    end_rec = clock();
    
    printf("Power Iterative Result: %f\n", (float)(end_iter - start_iter) / CLOCKS_PER_SEC);
    printf("Power Recursive Result: %f\n", (float)(end_rec - start_rec) / CLOCKS_PER_SEC);
  
    return 0;
}
/*������� ���������� �ٸ� �����Ϸ������� ������ ������ visual studio ������ ������ 0�ʷθ� ���� �ٸ� �����Ϸ��� �����߽��ϴ�.

(13,21)�� ���
Power Iterative Result: 0.000003
Power Recursive Result: 0.000000

(130,210)�� ���
Power Iterative Result: 0.000005
Power Recursive Result: 0.000001

�Է°��� �������� Ŭ�� ��� ��ȯ�� �ݺ����� �ð��� ���� �ɸ��� ���� Ȯ���� �� �ִ�. ��ȯ�� �ݺ����� �ҿ�ð��� ���԰ɸ��� '����'�� �ϳ��� �ŵ������̱� �����̴�.
*/