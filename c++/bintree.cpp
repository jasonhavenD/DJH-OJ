#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>

using namespace std;

#define True 1
#define TElemType char

typedef struct node {
    TElemType data;
    struct node *lc, *rc;
} BNode, *BTree;

void Visit(BTree node) {
    if (node != NULL) {
        printf("%d ", node->data);
    }
}


/*******************层序遍历******************/
/*
 * 借助queue实现，明显的层级顺序遍历
 *
 *  先将树的根节点入队，
    如果队列不空，则进入循环
    {
     将队首元素出队，并输出它；
     如果该队首元素有左孩子，则将其左孩子入队；
     如果该队首元素有右孩子，则将其右孩子入队
    }
 *
 * */
void LevelTransverse(BTree root) {
    queue<BNode *> queue;
    if (root == NULL)return;
    queue.push(root);
    while (!queue.empty()) {
        root = queue.front();
        Visit(root);
        queue.pop();
        if (root->lc != NULL)queue.push(root->lc);//左孩子
        if (root->rc != NULL)queue.push(root->rc);//右孩子
    }
}


/*******************递归遍历******************/
void PreOrderTree(BTree root) {
    if (root) {
        Visit(root);
        PreOrderTree(root->lc);
        PreOrderTree(root->rc);
    }
}// PreOrderTree
void PostOrderTree(BTree root) {
    if (root) {
        PostOrderTree(root->lc);
        PostOrderTree(root->rc);
        Visit(root);
    }
}// PostOrderTree
void InOrderTree(BTree root) {
    if (root) {
        InOrderTree(root->lc);
        Visit(root);
        InOrderTree(root->rc);
    }
}// InOrderTree

/*******************非递归遍历******************/
/*先序非递归有两种算法,第1种*/
void PreorderTraverse1(BTree root) {//先序访问
    if (root == NULL)
        return;
    stack<BTree> sk;
    sk.push(root);
    while (!sk.empty()) {
        root = sk.top();
        Visit(root);//访问根节点
        sk.pop();
        if (root->rc != NULL)sk.push(root->rc);//右子树
        if (root->lc != NULL)sk.push(root->lc);//左子树
    }
}

/*先序非递归有两种算法,第2种*/
void PreorderTraverse2(BTree root) {//先序访问
    stack<BTree> sk;
    while (root != NULL || !sk.empty()) {//遍历每个节点
        if (root != NULL) {
            Visit(root);//先序访问
            sk.push(root);//做孩子依次入栈
            root = root->lc;
        } else {//如果当前节点是NULL说明当前处于最左节点的位置
            root = sk.top();//获取栈顶节点,父节点
            sk.pop();
            root = root->rc;//回溯到栈顶节点，父节点的右节点
        }
    }
}

/*注意，
 * 先序2和中序非递归的代码区别不大，只是访问根节点的时机不同；
 * 先序在第一次遇到根节点访问；
 * 中序在左孩子都入栈之后，回溯的时候访问根节点
 * */
void InorderTraverse(BTree root) {//中序访问
    stack<BTree> sk;
    while (root != NULL || !sk.empty()) {//遍历每个节点
        if (root != NULL) {
            sk.push(root);//做孩子依次入栈
            root = root->lc;
        } else {//如果当前节点是NULL说明当前处于最左节点的位置
            root = sk.top();//获取栈顶节点,父节点
            Visit(root);//中序访问
            sk.pop();
            root = root->rc;//回溯到栈顶节点，父节点的右节点
        }
    }
}

/* 该方法类似于先序遍历的第一种非递归实现，注意细节不同
 *
 * 1.Push根结点到第一个栈s中。
 * 2.从第一个栈s中Pop出一个结点，并将其Push到第二个栈output中。
 * 3.然后Push结点的左孩子和右孩子到第一个栈s中。
 * 4.重复过程2和3直到栈s为空。
 * 5.完成后，所有结点已经Push到栈output中，且按照后序遍历的顺序存放，直接全部Pop出来即是二叉树后序遍历结果。
 * */
void PostorderTraverse(BTree root) {//后序遍历
    if (root == NULL)return;
    stack<BTree> sk, output;//使用两个栈更加简单
    sk.push(root);
    while (!sk.empty()) {
        root = sk.top();
        output.push(root);//Visit(root);//访问根节点
        sk.pop();
        if (root->lc)sk.push(root->lc);//左子树
        if (root->rc)sk.push(root->rc);//右子树
    }
    //上述执行完毕，结果按照  “根左右” 的顺序入栈到 output
    //循环出栈 output 即可实现 后序遍历
    while (!output.empty()) {
        root = sk.top();
        Visit(root);
        sk.pop();
    }
}


/*******************创建二叉树******************/
int pos = 0;//控制输入字符的下标
char str[100]; //读取的字符串
BNode *CreateNode() {//创建一个节点
    BNode *ret = (BNode *) malloc(sizeof(BNode));
    ret->lc = NULL;
    ret->rc = NULL;
    return ret;
}

/*一次性输入字符串，根据字符串递归创建*/
BNode *BuildTree(int len) {//输入字符串的长度
    if (pos >= len) return NULL;

    if (str[pos] == '#') {
        pos++;
        return NULL;
    }

    BNode *p = CreateNode();
    p->data = str[pos++];
    p->lc = BuildTree(len);
    p->rc = BuildTree(len);

    return p;
}

/*边输入边递归创建*/
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


/*******************释放二叉树******************/
void Destory(BTree root) {
    if (root) {
        Destory(root->lc);
        Destory(root->rc);
        free(root);
        root = NULL;
    }
}