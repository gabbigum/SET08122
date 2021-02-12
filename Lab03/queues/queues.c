#include <stdio.h>

#define MAX 5

struct queue;

struct queue {
    int array[MAX];
    int front;
    int rear;
};

void init(struct queue*);
void enqueue(struct queue*, int);
void dequeue(struct queue*);
void leftShiftArray(int*);

int main(int argc, char const *argv[])
{
    struct queue q;
    init(&q);
    printf("front = %d, rear = %d\n", q.front, q.rear);
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    dequeue(&q);
    enqueue(&q, 135);
    enqueue(&q, 344);
    dequeue(&q);
    enqueue(&q, 13);


    for(int i = 0; i < MAX; i++) {
        printf("%d\n", q.array[i]);
    }
    return 0;
}

void dequeue(struct queue* q) {
    if(q->front == -1) {
        printf("The queue is empty.");
        return;
    }

    q->array[q->front] = 0;
    leftShiftArray(&(q->array));
    q->rear--;
}

void leftShiftArray(int* array) {
    int firstElem = array[0];
    int index;
    for(index = 1; index < MAX; index++) {
        array[index-1] = array[index];
    }

    array[index-1] = firstElem;
}

void enqueue(struct queue* q, int item) {
    // what should be the logic
    // put element infront of the queue
    // put item to the front of the queue -> then shift the whole array to the right
    // if rear is MAX-1 the queue is full and you cant put anything until you dequeue
    if(q->rear == MAX - 1) {
        printf("The queue is full.\n");
        return;
    }

    if(q->front == -1 && q->rear == -1) {
        q->front++;
        q->rear++;
        q->array[q->front] = item;
        printf("Item added to the queue %d\n", item);
        return;
    }

    q->rear++;
    q->array[q->rear] = item;
    printf("Item added to the queue %d\n", q->array[q->rear]);
}

void init(struct queue* q) {
    q->front = -1;
    q->rear = -1;
    printf("Queue initialised.\n");
}   