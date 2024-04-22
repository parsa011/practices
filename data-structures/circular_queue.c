#include <stdio.h>
#include <stdlib.h>

struct circular_queue
{
	int *data;
	int size;
	int in_queue;
	int rear;
	int front;
	int total_enqueue;
	int total_dequeue;
};

#define NEXT_INDEX(cq, index) (index + 1) % cq->size

void cq_init(struct circular_queue* queue, int size)
{
	queue->data = (int *) malloc(sizeof(int) * size);
	queue->size = size;
	queue->front = -1;
	queue->in_queue = queue->rear = queue->total_enqueue = queue->total_dequeue = 0;
}

void cq_enqueue(struct circular_queue *queue, int val)
{
	int next_rear = NEXT_INDEX(queue, queue->rear);
	if (next_rear == queue->front) {
		printf("Queue Is Full\n");
	} else {
		queue->data[queue->rear] = val;
		queue->rear = next_rear;
		queue->total_enqueue++;
		queue->in_queue++;
	}
}

void cq_dequeue(struct circular_queue *queue, int *var)
{
	if (queue->front == queue->rear || queue->front == -1) {
		printf("Queue Is Empty\n");
		var = NULL;
	} else {
		queue->front = NEXT_INDEX(queue, queue->front);
		*var = queue->data[queue->front];
		queue->total_dequeue++;
		queue->in_queue--;
	}
}

void cq_print(struct circular_queue *queue)
{
	for (int i = 0; i < queue->size; i++) {
		printf("%d\t", queue->data[i]);
	}
	printf("\n");
}

int main()
{
	struct circular_queue my_queue;
	cq_init(&my_queue, 10);

	int deq = 0;
		cq_dequeue(&my_queue, &deq);


	cq_print(&my_queue);
	return 0;
}
