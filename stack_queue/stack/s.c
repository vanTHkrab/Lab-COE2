# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

struct StackNode {
    int data, size;
    unsigned capacity;
    struct StackNode* next;
};

int isEmpty(struct StackNode* root){
    return !root;
}

int Full(struct StackNode* root) {
    int size, capacity;
    if (isEmpty) {
        size = capacity = 0;
    }
}

struct StackNode* newnode(struct StackNode* root, int data)
{

    struct StackNode* stacknode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stacknode->data = data;
    stacknode->next = NULL;
    return stacknode;
};

void push(struct StackNode** root, int data) {
    if (Full(*root)) {
        printf("FULL/n");
        return;
        }
    struct StackNode* node = newnode(*root, data);
    node->next = *root;
    *root = node;
    printf("push: %d\n", data);
}

int peek(struct StackNode* root) {
    if(isEmpty(root)){
        printf("NULL\n");
        return INT_MIN;
    }
    return (root->data);
}

int pop(struct StackNode** root) {
        if(isEmpty(*root)){
        printf("NULL\n");
        return INT_MIN;
    }
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int main(void) {
    struct StackNode* root = capacity(1);
    printf("Peek: %d\n", peek(root));
    push(&root, 10);
    push(&root, 20);
    printf("Peek: %d\n", peek(root));
    printf("Pop: %d\n", pop(&root));
    printf("Peek: %d\n", peek(root));
}
