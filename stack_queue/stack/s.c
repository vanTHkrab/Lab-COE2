#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top;
    unsigned capacity;
    unsigned size;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

bool isFull(struct Stack* stack) {
    return stack->size == stack->capacity;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack is Full\n");
        return;
    }
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    printf("push: %d\n", data);
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Data is empty\n");
        return INT_MIN;
    }
    return stack->top->data;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Data is empty\n");
        return INT_MIN;
    }
    struct StackNode* temp = stack->top;
    stack->top = stack->top->next;
    int popped = temp->data;
    free(temp);
    stack->size--;
    return popped;
}

int main(void) {
    struct Stack* stack = createStack(3);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    printf("Top element: %d\n", peek(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Top element after pop: %d\n", peek(stack));
    return 0;
}
