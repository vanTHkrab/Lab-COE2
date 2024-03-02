#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree* newnode(int data) {
    struct tree* tree = (struct tree*)malloc(sizeof(struct tree));
    if (tree == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    printf("%d\n", data);
    return tree;
}

bool isEmpty(struct tree* root) {
    return !root;
}

int peek(struct tree* root) {
    if (isEmpty(root)) {
        printf("Tree is empty.\n");
        exit(EXIT_FAILURE);
    }
    return root->data;
}

void insertNode(struct tree** root, char a, int data, int level) {
    if (level < 1) {
        printf("Invalid level.\n");
        exit(EXIT_FAILURE);
    }
    if (level == 1) {
        if (*root != NULL) {
            printf("Node already exists at level 1.\n");
            exit(EXIT_FAILURE);
        }
        *root = newnode(data);
        return;
    }

    if (*root == NULL) {
        printf("Parent node doesn't exist.\n");
        exit(EXIT_FAILURE);
    }

    struct tree* treenode = newnode(data);

    if (a == 'l' || a == 'L') {
        insertNode(&((*root)->left), 'f', data, level - 1);
    }
    else if (a == 'r' || a == 'R') {
        insertNode(&((*root)->right), 'f', data, level - 1);
    }
    else {
        printf("Invalid direction.\n");
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    struct tree* root = NULL;
    insertNode(&root, 'f', 10, 1);
    insertNode(&root, 'l', 20, 2);
    insertNode(&root, 'r', 30, 2);
    insertNode(&root, 'l', 40, 3);
    insertNode(&root, 'r', 50, 3);
    insertNode(&root, 'l', 60, 4);
    printf("%d\n", peek(root->left->left->left->data));
    return 0;
}
