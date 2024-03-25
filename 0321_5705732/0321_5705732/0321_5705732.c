#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

//하노이 탑 시간측정

void hanoi_rec(int n, char start, char end, char middle) //n번을 middle을 이용해서 start에서 end로 옮기는 함수
{
    if (n == 1)printf("원판 1을 %c에서 %c으로 옮긴다.\n", start, end); //1번이면 start에서 end로 옮긴다.
    else {
        hanoi_rec(n - 1, start, end, middle); //1번이 아니면 n-1번을 end를 이용해서 start에서 mid로 옮기는 함수
        printf("원판 %d을 %c에서 %c으로 옮긴다\n", n, start, end); //n번 위에꺼를 다 뺐으니까 start에서 c로 옮김
        hanoi_rec(n - 1, middle, start, end); //그리고 n-1번을 start를 이용해서 middle에서 end로 옮기는 함수
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

    printf("Fib Recursive Result: %f\n", (float)(end_rec - start_rec) / CLOCKS_PER_SEC); //순환 시간
    printf("Fib Iterative Result: %f\n", (float)(end_iter - start_iter) / CLOCKS_PER_SEC); //반복 시간

    return 0;
}*/