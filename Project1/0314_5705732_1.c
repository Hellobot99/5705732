#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
�Ҽ��� �� ���ϱ�
for������ ��ü ���� �ݺ��ϰ� �ι�° for������ 1���� n���� ���ڸ� �����ͼ� ���Ѵ�.
*/
int main()
{
    clock_t start, stop; //���� �ð�, ������ �ð� ���� ����
    double duration;  // �ɸ��� �ð� ���� ����
    start = clock();


    int c = 0;

    int sum = 0;


    for (int a = 2; a < 101; a++)
    {
        for (c = 2; c < a; c++)            //c�� �� for�� �ۿ����� ���⶧���� ���� c���ٰ� int c ������ �ȵȴ�. 
        {
            if (a % c == 0) break;         //a�� c�� �������� �������� 0�̸� �Ҽ��� �ƴϹǷ� �� �̻� for���� �ݺ� �� �ʿ䰡 ����
            else continue;
        }
        //�տ����� for������ �Ҽ��� �ƴ� ���� �Ÿ����� �ѹ��� �Ÿ��� �Ҽ��� ���� �� ����. �ڱ� �ڽź��� 1���� ������ ����������ϱ⿡

        if (c == a)                        // 1�� �ڱ��ڽŹۿ� ����� �ȵȴٸ� a�� �ڱ��ڽ��� c�� ������ �� �ۿ�����.
        {
            sum = sum + a;
        }


    }
    printf("%d\n", sum);


    stop = clock();
    duration = (double)(stop - start) / CLOCKS_PER_SEC; //������ �ð����� �����ϴ� �ð��� ���� �� ���� duration�� ����
    printf("����ð��� %f�� �Դϴ�.\n", duration);      //duration�� ���



    return 0;
}
