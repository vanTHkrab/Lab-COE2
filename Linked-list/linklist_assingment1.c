#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void create_node();
void traverse();
void delete_node();
void delete_node_test();
struct node {
    int DATA;
    struct node *LINK;
};

struct node *HEAD = NULL;
struct node *NEW = NULL;
struct node *temp = NULL;

void main() {
    int ans;
    char ch;
    int data;
    do {
        fflush(stdin);
        printf("\n**************************\n");
        printf("Singly Linked List: \n");
        printf("1.Creating node\n2.Traversing the list\n3.Deleting node(has bug)\n4.Deleting node(test)\n5.Exit\n");
        printf("\n**************************\n");
        printf("Enter your choice: ");
        scanf("%d",&ans);
        switch(ans)
            {
            case 1:
                create_node();
                break;
            case 2:
                traverse();
                break;
            case 3:
                delete_node();
                break;
            case 4:
                delete_node_test();
                break;
            case 5:
                exit(0);
                break;
            default: printf("\nEnter correct choice");
        }
        // printf("\nContinue [y/n] : ");
        // scanf(" %c",&ch);
    // } while (ch == 'y' || ch == 'Y');
    } while (1);
    printf("Exit from the program");
}

void create_node() {
    bool success = false;
    NEW = malloc(sizeof(struct node));
    printf("\n --------- Insertion -----------\n");
    printf("Enter new data: ");
    scanf("%d", &NEW->DATA);

    NEW->LINK = NULL;
    // printf("Test0\n");

    if (HEAD == NULL) {
        HEAD = NEW;
        success = true;
    }

    else {
        temp = HEAD;
        while (temp->LINK != NULL) {
            temp = temp->LINK;
        }
        temp->LINK = NEW;
        success = true;
    }
    // printf("Test1\n");
    if (success) 
        printf("Insertion is completed\n");
    else 
        printf("Insertion is not completed\n");
}

void traverse() { //Printing data in linked list
    if (HEAD == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = malloc(sizeof(struct node));
    temp = HEAD;
    while (temp != NULL) {
        printf("%d ", temp->DATA);
        temp = temp->LINK;
    }
}

void delete_node() {
    int data;
    struct node *ptemp = NULL;
    bool success = false;
    printf("\n --------- Deletion -----------\n");
    printf("Enter data to delete: ");
    scanf("%d", &data);

    ptemp = malloc(sizeof(struct node));
    temp = malloc(sizeof(struct node));
    //Finding the node that we would like to delete (pointed by temp)
    temp = HEAD;
    ptemp = temp;
    while (temp != NULL) {
        if (temp->DATA != data) {
            ptemp = temp;
            temp = temp->LINK;
        }
        else break;
    }
    //Delete the node by linking skip the temp node and free node)
    if (temp->LINK == NULL) {
        ptemp->LINK = NULL;
        success = true;
    } 
    else {
        ptemp->LINK = temp->LINK;
        success = true;
        free(temp);
    }

    if (success)
        printf("Deletion is completed\n");
    else
        printf("Deletion is not completed\n");
}

void delete_node_test() {
    int data;
    struct node *current = HEAD;
    struct node *previous = NULL;
    bool success = false;
    printf("\n --------- Deletion -----------\n");
    printf("Enter data to delete: ");
    scanf("%d", &data);

    if (HEAD == NULL) {
        printf("List is empty\n");
        return;
    }

    while (current->DATA != data) {
        if (current->LINK == NULL) {
            printf("Data not found\n");
            return;
        }
        else {
            previous = current;
            current = current->LINK;
        }
    }
    if (current == HEAD) {
        HEAD = HEAD->LINK;
        success = true;
    }
    else {
        previous->LINK = current->LINK;
        success = true;
    }
    if (success)
        printf("Deletion is completed\n");
    else
        printf("Deletion is not completed\n");
}
