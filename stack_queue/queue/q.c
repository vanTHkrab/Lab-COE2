# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createqueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity *sizeof(int));
    return queue;
};

int FULL(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (FULL(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("Enqueue: %d\n", item);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return INT_MIN;
    int item = queue->array[queue->rear];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int front(struct Queue* queue) {
    if (isEmpty(queue)) return INT_MIN;
    return queue->array[queue->front];
}

int rear(struct Queue* queue) {
    if (isEmpty(queue)) return INT_MIN;
    return queue->array[queue->rear];
}

int main() {
    struct Queue* queue = createqueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("Front: %d\n", front(queue));
    printf("rear: %d\n", rear(queue));
}