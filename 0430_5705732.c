#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 6
typedef int element;
typedef struct { 
	element  data[MAX_QUEUE_SIZE];
	int  front, rear, size;
} QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
}

void init_queue(QueueType* q)
{
	q->front = 0,q->rear = 0,q->size=0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType* q)
{
	int i;
	printf("���� ť�� ���� = ");
	if (q->size == 0) {
		printf("ť�� ����ֽ��ϴ�.");
	}
	else {
		for (i = q->front + 1; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
			printf("%d ", q->data[i]);
		}
		printf("%d ", q->data[i]);
	}
	printf("\n");
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
		q->size++;
	}	
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		q->size--;
		return q->data[q->front];
	}
}
int main(void)
{
	QueueType queue;
	int choice, a;
	init_queue(&queue);

	while (1) {
		printf("1. ť�� ���Ҹ� ����\n");
		printf("2. ť���� ���Ҹ� ����\n");
		printf("3. ť�� ���Ҹ� ���\n");
		printf("4. ����\n");
		printf("�޴��� �����ϼ���: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("ť�� ������ ���ڸ� �Է��ϼ��� : ");
			scanf("%d", &a);
			enqueue(&queue, a);
			break;
		case 2:
			dequeue(&queue);
			break;
		case 3:
			queue_print(&queue);
			break;
		case 4:
			exit(0);
		default:
			printf("�߸��� �����Դϴ�.\n");
			return 0;
		}

	}
}
