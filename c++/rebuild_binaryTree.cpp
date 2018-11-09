//
// 重建二叉树
//
// Created by jasonhaven on 18-11-8.
//

#include <bits/stdc++.h>

typedef struct node {
    int val;
    struct node *lc, *rc;
} node;


void rebuildBTByPre_In(node **root, int len, int *pre, int *in) {
    /*
     * root 重构的二叉树
     * len 节点个数
     * pre 先序
     * in 中序
     * */
    if (pre == NULL || in == NULL || len < 1)return;

    //在中序遍历中找到前序遍历的头结点的左右子结点
    int index = -1;
    for (int i = 0; i < len; ++i) {
        if (pre[0] == in[i]) {
            index = i;
            break;
        }
    }
    if (index == -1) {//没有找到当前根结点在中序遍历的位置
        return;
    }

    *root = (node *) malloc(sizeof(node));//开始构建此结点

    if (!root) {//分配失败
        exit(0);
    }

    (*root)->val = in[index];
    (*root)->lc = NULL;
    (*root)->rc = NULL;

    rebuildBTByPre_In(&(*root)->lc, index, pre + 1, in);//递归重建左子树
    rebuildBTByPre_In(&(*root)->rc, len - (index + 1), pre + (index + 1), in + (index + 1));//递归重建右子树
}

void rebuildBTByPost_In(node **root, int len, int *post, int *in) {
    if (post == NULL || in == NULL || len < 1)return;

    int index = -1;
    for (int i = 0; i < len; ++i) {
        if (post[len - 1] == in[i]) {
            index = i;
            break;
        }
    }
    if (index == -1)return;

    *root = (node *) malloc(sizeof(node));//开始构建此结点

    if (!root) {//分配失败
        exit(0);
    }
    (*root)->val = in[index];
    (*root)->lc = NULL;
    (*root)->rc = NULL;

    rebuildBTByPost_In(&(*root)->lc, index, post, in);
    rebuildBTByPost_In(&(*root)->rc, len - (index + 1), post + index, in + (index + 1));//注意后序偏移为index
}

void postTransversal(node *root) {
    if (root) {
        postTransversal(root->lc);
        postTransversal(root->rc);
        printf("%d ", root->val);
    }
}

void preTransversal(node *root) {
    if (root) {
        printf("%d ", root->val);
        preTransversal(root->lc);
        preTransversal(root->rc);
    }
}

void inTransversal(node *root) {
    if (root) {
        inTransversal(root->lc);
        printf("%d ", root->val);
        inTransversal(root->rc);
    }
}

void destory(node *root) {
    if (!root)return;
    destory(root->lc);
    destory(root->rc);
    free(root);
}

/*
input:
    8
    1 2 4 7 3 5 6 8
    4 7 2 1 5 3 8 6

output:
    7 4 2 5 8 6 3 1
 * */
int main() {
    int n = 8;
    int pre[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int in[] = {4, 7, 2, 1, 5, 3, 8, 6};
    int post[] = {7, 4, 2, 5, 8, 6, 3, 1};
    node *root;
//  rebuildBTByPre_In(&root, n, pre, in);

    rebuildBTByPost_In(&root, n, post, in);

    preTransversal(root);
    printf("\n");
    inTransversal(root);
    printf("\n");
    postTransversal(root);
    return 0;
}