// 二叉排序树
// Created by jasonhaven on 18-12-2.
//


#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};


struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        struct node *newNode = (node *) malloc(sizeof(struct node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inorder(struct node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


void create(struct node *root, int a[], int n) {
    for (int i = 1; i < n; ++i) {
        insert(root, a[i]);
    }
}

struct node *search(struct node *root, int key) {
    if (root == NULL)return NULL;
    if (key == root->data)return root;
    if (key < root->data)return search(root->left, key);
    else return search(root->right, key);
}


int main() {
    struct node *root = NULL;
    int a[] = {4, 3, 2, 6, 9, 8, 1, 0, 5, 7};
    root = insert(root, a[0]);
    create(root, a, sizeof(a) / sizeof(int));
    inorder(root);
    struct node *p = search(root, 5);
    printf("\n%d\n", p->data);
}