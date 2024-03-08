# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree* findMin(struct tree* node);
int delete(struct tree** root, int data);

struct tree* newnode(int data) {
    struct tree* tree = (struct tree*)malloc(sizeof(struct tree));
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

bool isEmpty(struct tree* root){
    return !root;
}

void print(struct tree* root) {
    if (root != NULL) {
        print(root->left);
        printf("%d ", root->data);
        print(root->right);
    }
}

struct tree* insert(struct tree* root, int data) {
    if (root == NULL) {
        return newnode(data);
    }
    if (root->data == data) {
        return root;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

int delete(struct tree** root, int data) {
    if (*root == NULL) {
        return 0;
    }
    if ((*root)->data == data) {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
            return 1;
        }
        if ((*root)->left == NULL) {
            struct tree* temp = *root;
            *root = (*root)->right;
            free(temp);
            return 1;
        }
        if ((*root)->right == NULL) {
            struct tree* temp = *root;
            *root = (*root)->left;
            free(temp);
            return 1;
        }
        struct tree* temp = findMin((*root)->right);
        (*root)->data = temp->data;
        delete(&(*root)->right, temp->data);
        return 1;
    }
    if (delete(&((*root)->left), data) || delete(&((*root)->right), data)) {
        return 1;
    }
    return 0;
}

struct tree* findMin(struct tree* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

int main(void) {
    struct tree* root = NULL;
    struct tree* root2 = NULL;
    root = insert(root, 25);
    // root2 = insert(root2, 5);
    insert(root, 20);
    insert(root, 36);
    insert(root, 10);
    insert(root, 22);
    insert(root, 30);
    insert(root, 40);
    insert(root, 5);
    insert(root, 12);
    insert(root, 28);
    insert(root, 38);
    insert(root, 48);
    insert(root, 1);
    insert(root, 8);
    insert(root, 15);
    insert(root, 45);
    insert(root, 50);
    // insert(root, 40);
    // print(root);
    delete(&root, 25);
    if (delete(&root, 50)) {
        printf("Success\n");
    }
    else {
        printf("Not found\n");
    }
    print(root);
}