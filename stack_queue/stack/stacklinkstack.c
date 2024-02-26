# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

struct StackNode {
    int data, numstacknode;
    struct StackNode *next, *stacknode;
};

struct StackNode* Newnode(struct StackNode* root, int data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
};

int isEmpty(struct StackNode* root) {
    return !root;
}

int push(struct StackNode** root, int data ) {
    struct StackNode* stackNode = Newnode(*root, data);
    stackNode->next = *root;
    *root = stackNode;
    printf("Push %d in node\n", data);
}

int pop(struct StackNode** root) {
    if (isEmpty(*root)) return INT_MIN;
    struct StackNode* temp = *root; 
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(struct StackNode* root) {
    if (isEmpty(root)) return INT_MIN;
    return root->data;
}

int main() {
    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;

    push(&stack1, 1);

    push(&stack2, 3);

    printf("peek stack1: %d\n", peek(stack1));
    printf("peek stack2: %d\n", peek(stack2));

    return 0;
}