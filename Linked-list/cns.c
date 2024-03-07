#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void create_node();
void traverse();
void insert_node();
void delete_node();

struct node{
    int DATA;
    struct node *LINK;
}*HEAD, *NEW, *temp, *ptemp;

void main(){
    HEAD = NULL;
    int ans;
    char ch;
    do{
        printf("\n***********|n");
        printf("Singly Linked list: \n");
        printf("1.Creating node\n2.Traversing the list\n3.Insert node\n4.Deleting node\n5.exit ");
        printf("\n***********|n");
        printf("Enter your choice : ");
        scanf("%d", &ans);
        switch (ans)
        {
        case 1:
            create_node():
            break;
        case 2:
            traverse():
            break;
        case 3:
            insert_node():
            break;
        case 4:
            delete_node():
            break;
        case 5:
            exit(0);
        default: printf("\nEnter correct choice: ");
        }
    } while (1);
        printf("Exit from the program");
}

void create_node() {
    bool success = false;
    NEW = malloc(sizeof(struct node));
    printf("\n*****Insertion*****\n");
    printf("Enter new data: ");
    scanf("%d", &NEW->DATA);

    NEW->LINK = NULL;

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
    temp = HEAD;
    while (temp != NULL) {
        printf("%d ", temp->DATA);
        temp = temp->LINK;
    }
}

void insert(){
    int p;
    if (HEAD == NULL) {
        return;
    }
    temp = ptemp = HEAD;
    NEW = malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &NEW->DATA);
    printf("Position: ");
    scanf("%d", &p);
    for (int i = 1; i < p; i++){
        if (temp->LINK == NULL) {
            free(NEW);
            return;
        }
        else{
        ptemp = temp;
        temp = temp->LINK;
        }
    }
        if (temp == HEAD) {
        NEW->LINK = temp;
        HEAD = NEW;
    }
    else {
        ptemp->LINK = NEW;
        NEW->LINK = temp;
    }
}

