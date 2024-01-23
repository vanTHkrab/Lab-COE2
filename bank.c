#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct account {
    char id[10], name[30], lastname[30];
    int num;
    struct account* next;
} account;

typedef struct credit {
    char id[10], credit[10], type[10];
    int balance, limit;
    struct credit* creditnext;
} credit;

account* newAccount(account* a) {
    account* newnode = (account*)malloc(sizeof(account));
    printf("id: ");
    scanf("%s", newnode->id);
    printf("name: ");
    scanf("%s", newnode->name);
    printf("lastname: ");
    scanf("%s", newnode->lastname);
    newnode->num = 0;
    newnode->next = a;
    return newnode;
}

credit* creatcredit(credit* c, account* a) {
    credit* newnode;
    char id[10];
    printf("id: ");
    scanf("%s", id);
    while (a != NULL) {
        if (strcmp(a->id, id) == 0) {
            printf("How many credits do you want to create?\n");
            int n;
            scanf("%d", &n);
            if (n > 10) {
                printf("You can't create more than 10 credits\n");
            } else {
                for (int i = 0; i < n; i++) {
                    int t = 0;
                    printf("Type the credit (1. Saving 2. Current)\n");
                    scanf("%d", &t);
                    newnode = (credit*)malloc(sizeof(credit));
                    printf("id: %s\n", a->id);
                    strcpy(newnode->id, a->id);
                    printf("credit: %s\n", (t == 1) ? "Saving" : "Current");
                    strcpy(newnode->type, (t == 1) ? "Saving" : "Current");
                    printf("Credit ID: %d\n", a->num + 1);
                    scanf("%d", &newnode->balance);
                    if (t == 2) {
                        printf("Limit: ");
                        scanf("%d", &newnode->limit);
                    }
                    a->num++;
                    newnode->creditnext = c;
                    c = newnode;
                }
                return c;
            }
        }
        a = a->next;
    }
    return c;  // Return original credit list if account not found
}

void depositandwithdraw(credit* c, account* a) {
    char id[10];
    printf("id: ");
    scanf("%s", id);
    while (a != NULL) {
        if (strcmp(a->id, id) == 0) {
            char creditId[10];
            printf("credit: ");
            scanf("%s", creditId);
            while (c != NULL) {
                if (strcmp(c->credit, creditId) == 0) {
                    int n;
                    printf("How much do you want to deposit?\n");
                    scanf("%d", &n);
                    c->balance += n;
                    printf("Your balance is %d\n", c->balance);
                    return;
                }
                c = c->creditnext;
            }
            printf("Credit not found\n");
            return;
        }
        a = a->next;
    }
    printf("Account not found\n");
}

void displayall(account* a, credit* c) {
    while (a != NULL) {
        printf("id: %s\n", a->id);
        printf("name: %s\n", a->name);
        printf("lastname: %s\n", a->lastname);
        printf("credit: %d\n", a->num);
        while (c != NULL) {
            if (strcmp(c->id, a->id) == 0) {
                printf("credit: %s\n", c->credit);
                printf("type: %s\n", c->type);
                printf("balance: %d\n", c->balance);
                if (strcmp(c->type, "Current") == 0) {
                    printf("limit: %d\n", c->limit);
                }
            }
            c = c->creditnext;
        }
        a = a->next;
    }
}

int main() {
    account* a = NULL;
    credit* c = NULL;
    int n;
    while (1) {
        printf("1. Create account\n");
        printf("2. Create credit\n");
        printf("3. Deposit and withdraw\n");
        printf("4. Display all\n");
        printf("5. Exit\n");
        scanf("%d", &n);
        if (n == 1) {
            a = newAccount(a);
        } else if (n == 2) {
            c = creatcredit(c, a);
        } else if (n == 3) {
            depositandwithdraw(c, a);
        } else if (n == 4) {
            displayall(a, c);
        } else if (n == 5) {
            break;
        } else {
            printf("Input 1, 2, 3, 4, 5\n");
        }
    }

    // Free allocated memory
    while (a != NULL) {
        account* temp = a;
        a = a->next;
        free(temp);
    }

    while (c != NULL) {
        credit* temp = c;
        c = c->creditnext;
        free(temp);
    }

    return 0;
}