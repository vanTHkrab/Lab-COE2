# include <stdio.h>
# include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *new = NULL;

int main(){
    new = malloc(sizeof(struct node));

    new->data = 10;
    new->next = NULL;
    
    head = new;
    head->data = 100;

    printf("Data of head node is %d\n", head->data);
    printf("Memory address that head points to is %p\n", head);
    printf("Memory address of new node is %p\n", new);
    free(head);
    free(new);

    return 0;
}
