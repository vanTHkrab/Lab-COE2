# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

struct node {
    int data;
    struct node* next;
};

struct stacknode {
    unsigned capacity, size;
    struct node* top;
};

struct stacknode* createstack(unsigned capacity) {
    struct stacknode *StackNode = (struct stacknode*)malloc(sizeof(struct stacknode));
    StackNode->capacity = capacity;
    StackNode->top = NULL;
    StackNode->size = 0;
    return StackNode;
};

bool Full(struct stacknode* stack) {
    return (stack->capacity == stack->size);
}

void push(struct stacknode* stack, int data) {
    if (Full(stack)) {
        printf("FULL\n");
        return;
    }
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node->data = data;
    Node->next = stack->top;
    stack->top = Node;
    stack->size++;
    printf("Push : %d\n", data);
}

int main() {
    struct stacknode* stack = createstack(4);
    push(stack, 5);
    push(stack, 15);
    push(stack, 25);
    push(stack, 35);
    push(stack, 45);
}