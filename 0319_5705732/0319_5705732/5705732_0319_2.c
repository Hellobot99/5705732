#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//거듭제곱

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
/*예제대로 측정했을때 다른 컴파일러에서는 측정이 되지만 visual studio 에서는 측정이 0초로만 떠서 다른 컴파일러로 측정했습니다.

(13,21)의 경우
Power Iterative Result: 0.000003
Power Recursive Result: 0.000000

(130,210)의 경우
Power Iterative Result: 0.000005
Power Recursive Result: 0.000001

입력값이 작을때와 클때 모두 순환이 반복보다 시간이 적게 걸리는 것을 확인할 수 있다. 순환이 반복보다 소요시간이 적게걸리는 '예외'중 하나인 거듭제곱이기 때문이다.
*/