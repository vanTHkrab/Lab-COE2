# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d %d %d %d %d\n", item, queue->size, queue->rear, queue->array[queue->rear], queue->capacity);
}

void dequeue(struct Queue* queue) {
    int item = queue->array[queue->rear];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int front(struct Queue* queue) {
    if (isEmpty(queue)) return;
    return queue->array[queue->front];
}

int rear(struct Queue* queue) {
    if (isEmpty(queue)) return;
    return queue->array[queue->rear];
}

int main(void) {
    struct Queue* queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 30);
    enqueue(queue, 50);
    enqueue(queue, 70);
    enqueue(queue, 90);
    enqueue(queue, 110);
}