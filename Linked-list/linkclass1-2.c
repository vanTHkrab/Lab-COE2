# include <stdio.h>
# include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *node1 = NULL;
struct node *node2 = NULL;
struct node *node3 = NULL;
struct node *head = NULL;
struct node *temp = NULL;

void main(){
    node1 = malloc(sizeof(struct node));
    node2 = malloc(sizeof(struct node));
    node3 = malloc(sizeof(struct node));

    node1->data = 5;
    node1->next = NULL;

    printf("Data of node1 is %d\n", node1->data);

    head = node1;
    // head->next = NULL;

    node1->next = node2;
    node2->data = 10;

    printf("Data of node2 is %d\n", node2->data);

    node2->next = node3;
    node3->data = 15;
    node3->next = NULL;

    printf("Data of node3 is %d\n", node3->data);

    temp = head;
    printf("Data of each node is : ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;

    }
}