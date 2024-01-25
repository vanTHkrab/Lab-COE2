# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <bool.h>

struct node{
    int key, num;
    struct node* next;
}

struct node* head = NULL;
struct node* current = NULL;

bool isEmpty(){
    return head == NULL;
}

int insertFirst(int key, int num){
    struct node* link =(struct node*) malloc(sizeof(struct node));
    link->key = key;
    link->num = num;
    link->next = head;
    head = link;
}

int deleteFirst(){
    struct node* temp
}

int main(){

}