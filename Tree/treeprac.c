# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* createnode(int data) {
    struct tree* node = (struct tree*)malloc(sizeof(struct tree));
    node->data = data;
    node->left = node->right = NULL;
}

struct tree* insert(struct tree* root, int data) {
    if (root == NULL) return createnode(data);
    if (root->data < data) {
        root->right = insert(root->right, data);
    }
    else if (root->data > data) {
        root->left = insert(root->left, data);
    }
    return root;
}

void print(struct tree* root) {
    if (root != NULL) {
        printf("%d ",root->data);
        print(root->left);
        print(root->right);
    }
}

void search(struct tree* root) {
    if (root != NULL) {
        if (root->data == 5) {
            printf("Find");
            return;
        }
        search(root->left);
        search(root->right);
    }
}

int main() {
    struct tree* root1 = NULL;
    struct tree* root2 = NULL;
    root1 = insert(root1, 10);
    root2 = insert(root2, 5);
    insert(root1, 20);
    insert(root1, 15);
    insert(root1, 49);
    insert(root1, 9);
    insert(root1, 5);
    insert(root1, 1);
    insert(root2, 9);
    insert(root2, 5);
    insert(root2, 1);
    insert(root1, 57);
    search(root1);
}