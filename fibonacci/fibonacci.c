#include <stdio.h>
#include <string.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

//피보나치 수열 순환,반복 시간측정

int fib_rec(int n) //순환
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return (fib_rec(n - 1) + fib_rec(n - 2));
}

int fib_iter(int n) //반복
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    int p1 = 0, p2 = 1, result = 0;

    for (int i = 2; i <= n; i++)
    {
        result = p1 + p2;
        p1 = p2;
        p2 = result;
    }
    return result;
}

int main()
{

    clock_t start_iter, end_iter, start_rec, end_rec;
    double duration_iter, duration_rec;

    start_rec = clock();
    double result_rec = fib_rec(44);
    end_rec = clock();

    start_iter = clock();
    double result_iter = fib_iter(44);
    end_iter = clock();

    printf("Fib Recursive Result: %f\n", (float)(end_rec - start_rec) / CLOCKS_PER_SEC); //순환 시간
    printf("Fib Iterative Result: %f\n", (float)(end_iter - start_iter) / CLOCKS_PER_SEC); //반복 시간

    return 0;
}