# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

struct treenode {
    int data;
    struct treenode* left;
    struct treenode* right;
};

struct treenode* createnode(int data) {
    struct treenode* node = (struct treenode*)malloc(sizeof(struct treenode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
};

struct treenode* insert(struct treenode* root, int data) {
    if (root == NULL) return createnode(data);
    if (root->data == data) return root;
    if (root->data < data) {
        root->right = insert(root->right, data);
    }
    else if (root->data > data) {
        root->left = insert(root->left, data);
    }
    return root;
};

int print(struct treenode* root) {
    if (root != NULL) {
        print(root->left);
        printf("%d ", root->data);
        print(root->right);
    }
}

struct treenode* findMin(struct treenode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

int delete(struct treenode** root, int data) {
    if ((*root) == NULL) return 0;
    if ((*root)->data == data) {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root == NULL;
            return 1;
        }
        if ((*root)->left == NULL) {
            struct treenode* temp = * root;
            (*root) = (*root)->right;
            free(temp);
            return 1;
        }
        if ((*root)->right == NULL) {
            struct treenode* temp = * root;
            (*root) = (*root)->left;
            free(temp);
            return 1;
        }
        struct treenode* temp = findMin((*root));
        (*root)->data = temp->data;
        delete(&(*root)->right, temp->data);
        return 1;
    }
    if (delete(&(*root)->left, data) || delete(&(*root)->right, data)) {
        return 1;
    }

    return 0;
}

int main() {
    struct treenode* root = NULL;
    root = insert(root, 75);
    insert(root, 43);
    insert(root, 89);
    insert(root, 11);
    insert(root, 67);
    insert(root, 79);
    insert(root, 97);
    insert(root, 10);
    insert(root, 13);
    insert(root, 64);
    insert(root, 68);
    insert(root, 78);
    insert(root, 99);
    print(root);
    printf("\n");
    delete(&root, 10);
    print(root);
}