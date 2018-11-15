// 最近公共祖先
// Created by jasonhaven on 18-11-15.
//
#include <bits/stdc++.h>

typedef char T;

typedef struct node {
    T data;
    struct node *lc, *rc;
} BNode, *BTree;

BTree CreateTree() {
    char ch;
    scanf("%c", &ch);
    if (ch == '#') {
        return NULL;
    }
    BNode *p = (BNode *) malloc(sizeof(BNode));
    p->data = ch;
    p->lc = CreateTree();
    p->rc = CreateTree();
    return p;//返回根节点
}

/**********************自顶向下*****************************/
//由于对每个结点都调用了hasNode函数，而该函数类似于遍历二叉树，复杂度为O(N)，所以总的时间复杂度为O(N^2)
/*判断root为根的树是否包含结点p*/
bool hasNode(struct node *root, struct node *p) {
    if (!root) return false;
    if (root == p)
        return true;
    return hasNode(root->lc, p) || hasNode(root->rc, p);
}

/*查找二叉树中两个结点最低公共祖先结点*/
struct node *LCA1(struct node *root, struct node *p, struct node *q) {
    if (hasNode(root->lc, p) && hasNode(root->lc, q)) //p和q都在左子树中
        return LCA1(root->lc, p, q);
    if (hasNode(root->rc, p) && hasNode(root->rc, q)) //p和q都在右子树中
        return LCA1(root->rc, p, q);
    return root; //p和q一个在左子树，一个在右子树中，直接返回root
}

/**********************自底向上*****************************/
node *LCA2(node *root, node *p, node *q) {
    if (!root) return NULL;
    if (root == p || root == q) return root;
    node *L = LCA2(root->lc, p, q);
    node *R = LCA2(root->rc, p, q);
    if (L && R) return root;  // 如果p和q位于不同的子树
    return L ? L : R;  //p和q在相同的子树，或者p和q不在子树中
}

/*
 *    4
     / \
    3   7
       / \
      5   6
 * */

int main() {

    return 0;
}


