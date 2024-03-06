# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

struct node{
    int data;
    struct node* next;
}*head, *temp, *new, *ptemp;

void create();
void traverse();
void insert();
void delete();

int main() {
    head = NULL;
    int ans;
    do {
        printf(": ");
        scanf("%d", &ans);
        switch (ans)
        {
        case 1:
            create();
            break;
        case 2:
            traverse();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete();
        default:
            break;
        }
    } while(1);
}

void create(){
    new = malloc(sizeof(struct node));
    printf("Data: ");
    scanf("%d", &new->data);
    new->next = NULL;
    if (head == NULL){
        head = new;
    } 
    else {
        temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
}

void traverse(){
    temp = head;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert(){
    if (head == NULL) {
        return;
    }
    new = malloc(sizeof(struct node));
    printf("Insert data: ");
    scanf("%d", &new->data);
    printf("Before data: ");
    int p;
    scanf("%d", &p);
    temp = ptemp = head;
    while (temp->data != p){
        if (temp->next == NULL) {
            return;
        }
        else {
            ptemp = temp;
            temp = temp->next;
        }
    }
    if (temp == head){
        new->next = temp;
        head = new;
    }
    else {
        ptemp->next = new;
        new->next = temp;
    }
}

void delete(){
    int d;
    printf("Delete data: ");
    scanf("%d", &d);
    temp = ptemp = head;
    while (temp->data != d)
    {
        if (temp->next == NULL)
        {
            return;
        }
        else {
            ptemp = temp;
            temp = temp->next;
        }  
    }
    if (temp == head) {
        head = head->next;
    } 
    else {
        ptemp->next = temp->next;
    }
    
}