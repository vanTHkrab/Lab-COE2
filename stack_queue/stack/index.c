#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
// A structure to represent a stack 
struct StackNode { 
    int data; 
    struct StackNode* next; 
}; 
  
struct StackNode* newNode(int data) 
{ 
    struct StackNode* stackNode =  
      (struct StackNode*) 
      malloc(sizeof(struct StackNode)); 
    stackNode->data = data; 
    stackNode->next = NULL; 
    return stackNode; 
} 
  
int isEmpty(struct StackNode* root) 
{ 
    return !root; 
} 
  
void push(struct StackNode** root, int data) 
{ 
    struct StackNode* stackNode = newNode(data); 
    stackNode->next = *root; 
    *root = stackNode; 
    printf("%d pushed to stack\n", data); 
} 
  
int pop(struct StackNode** root) 
{   
    if (isEmpty(*root)) 
        return INT_MIN; 
    struct StackNode* temp = *root; 
    *root = (*root)->next; 
    int popped = temp->data; 
    free(temp); 
    
    return popped; 
} 
  
int peek(struct StackNode* root) 
{ 
    if (isEmpty(root)) 
        return INT_MIN; 
    return root->data; 
} 
  
int main() 
{ 
    struct StackNode* root = NULL; 
    int ans, num;
    do {
        printf("\n**************************\n");
        printf("Stack: \n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Exit\n");
        scanf("%d", &ans);
        switch (ans)
        {
        case 1:
            printf("Enter the number to push: ");
            scanf("%d", &num);
            push(&root, num);
            break;
        case 2:
            printf("Popped from stack: %d\n", pop(&root));
            break;
        case 3:
            printf("Top element is %d\n", peek(root));
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    } while (1);
    return 0;
} 