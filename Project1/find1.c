#include <stdio.h>
/*
소수의 합 구하기
for문으로 전체 숫자 반복하고 두번째 for문으로 1부터 n까지 숫자를 가져와서 비교한다.
*/
int main()
{    
    int c = 0;
    
    int sum = 0;
    

    for (int a = 2; a < 101; a++) 
    {
        for (c = 2; c < a; c++)            //c는 이 for문 밖에서도 쓰기때문에 여기 c에다가 int c 넣으면 안된다. 
        {                                 
            if (a % c == 0) break;         //a가 c로 나눴을때 나머지가 0이면 소수가 아니므로 그 이상 for문을 반복 할 필요가 없다
            else continue;
        }
                                           //앞에서의 for문에서 소수가 아닌 수를 거르지만 한번만 거르면 소수만 구할 수 없다. 자기 자신보다 1작은 수까지 나누어봐야하기에

        if (c == a)                        // 1과 자기자신밖에 약분이 안된다면 a는 자기자신인 c와 같아질 수 밖에없다.
        {                      
            sum = sum + a;
        }


    }
        printf("%d", sum);
    
    
        
    
    return 0;
}
