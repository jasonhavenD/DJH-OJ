// 二叉树
//
// Created by jasonhaven on 18-11-7.
//
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <stack>

using namespace std;

#define True 1
typedef char T;

typedef struct node {
    T data;
    struct node *lc, *rc;
} BNode, *BTree;

void Visit(BTree node) {
    if (node != NULL) {
        printf("%c ", node->data);
    }
}

void levelTranverse(BTree root) {
    queue<BNode *> Q;
    if (!root)return;
    Q.push(root);
    while (!Q.empty()) {
        BNode *node = Q.front();
        Q.pop();
        Visit(node);//出队列的同时，将孩子入队
        if (node->lc)Q.push(node->lc);
        if (node->rc)Q.push(node->rc);
    }
}

void preOrder(BTree root) {
    stack<BNode *> sk;
    while (root || !sk.empty()) {
        if (root) {
            Visit(root);//访问
            sk.push(root);
            root = root->lc;
        } else {
            root = sk.top();
            sk.pop();
            root = root->rc;
        }
    }
}

void preOrder2(BTree root) {
    stack<BNode *> sk;
    sk.push(root);
    while (!sk.empty()) {
        root = sk.top();
        sk.pop();
        Visit(root);//访问
        //孩子入栈顺序
        if (root->rc)sk.push(root->rc);
        if (root->lc)sk.push(root->lc);
    }
}

void preOrder3(BTree root) {
    stack<BNode *> sk;
    while (root || !sk.empty()) {
        while (root) {
            Visit(root);
            sk.push(root);
            root = root->lc;
        }
        if (!sk.empty()) {
            root = sk.top();
            sk.pop();
            root = root->rc;
        }
    }
}

void inOrder(BTree root) {
    stack<BNode *> sk;
    while (root || !sk.empty()) {
        if (root) {
            sk.push(root);
            root = root->lc;
        } else {
            root = sk.top();
            Visit(root);//访问
            sk.pop();
            root = root->rc;
        }
    }
}

void inOrder2(BTree root) {
    stack<BNode *> sk;
    while (root || !sk.empty()) {
        while (root) {
            sk.push(root);
            root = root->lc;
        }
        if (!sk.empty()) {
            root = sk.top();
            sk.pop();
            Visit(root);
            root = root->rc;
        }
    }
}

//两个栈，第一个先序入栈，第二个出栈访问
void postOrder(BTree root) {
    stack<BNode *> sk, output;
    sk.push(root);
    while (!sk.empty()) {
        root = sk.top();
        sk.pop();
        output.push(root);
        if (root->lc)sk.push(root->lc);//注意顺序和先序遍历的区别
        if (root->rc)sk.push(root->rc);
    }
    while (!output.empty()) {
        root = output.top();
        Visit(root);
        output.pop();
    }
}


void postOrder2(BTree root) {
    stack<BNode *> sk;
    BNode *lastVisit = root;
    while (root || !sk.empty()) {
        while (root) {
            sk.push(root);
            root = root->lc;
        }
        root = sk.top();
        if (root->rc == NULL || root->rc == lastVisit) {
            Visit(root);
            sk.pop();
            lastVisit = root;
            root = NULL;
        } else {
            root = root->rc;
        }
    }
}


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

int main() {
    BTree root = CreateTree();//ABC##DE#G##F###
    printf("层序遍历\n");
    levelTranverse(root);//A B C D E F G
    printf("\n先序遍历\n");
    preOrder(root);//A B C D E G F
    printf("\n先序遍历2\n");
    preOrder2(root);//A B C D E G F
    printf("\n先序遍历3\n");
    preOrder3(root);//A B C D E G F
    printf("\n中序遍历\n");
    inOrder(root);//C B E G D F A
    printf("\n中序遍历2\n");
    inOrder2(root);//C B E G D F A
    printf("\n后序遍历\n");
    postOrder(root);//C G E F D B A
    printf("\n后序遍历2\n");
    postOrder2(root);//C G E F D B A
    return 0;
}

