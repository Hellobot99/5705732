#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//팩토리얼 

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

/* 예제대로 측정했을때 다른 컴파일러에서는 측정이 되지만 visual studio 에서는 측정이 0초로만 떠서 다른 컴파일러로 측정했습니다.
(입력값을 20으로 입력한 경우)
Factorial Iterative Result: 0.000002
Factorial Recursive Result: 0.000001

(입력값을 2200으로 입력한 경우)
Factorial Iterative Result: 0.000007
Factorial Recursive Result: 0.000049

입력값이 작은 초기에는 반복이 순환보다 더 오래걸렸지만, 입력값을 늘리면 늘릴수록 반복보다 순환이 더 오래걸리는것을 측정할 수 있었다
*/