# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

struct StackNode {
    int data, size;
    unsigned capacity;
    struct StackNode* next;
};

int isEmpty(struct StackNode* root){
    return !root;
}

bool Full(struct StackNode* root) {
    if (isEmpty(root)) return NULL;
    if (root->capacity != root->size) {
        return 1;
    }
    else return 0;
}

struct StackNode* newnode(struct StackNode* root, int data)
{
    struct StackNode* stacknode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stacknode->data = data;
    stacknode->next = NULL;
    stacknode->size = root->size +1;
    stacknode->capacity = root->capacity;
    return stacknode;
};

void push(struct StackNode** root, int data) {
    if (Full(*root)) return;
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
    struct StackNode* root = createstack(root, 3);
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    push(&root, 40);
    printf("%d", peek(root));
}
