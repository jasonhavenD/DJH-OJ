#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>

using namespace std;

#define True 1
#define False 0
#define TElemType char

typedef struct node {
    TElemType data;
    struct node *lc, *rc;
} BNode, *BTree;

/*******************节点个数******************/
int countNumber(BTree root) {
    if (root == NULL)return 0;//递归停止条件
    return 1 + countNumber(root->lc) + countNumber(root->rc);//当前节点+递归节点
}

/*******************叶子节点个数******************/
int countleaf(BTree root) {
    if (root == NULL)return 0;//递归停止条件
    if (root->lc == NULL && root->rc == NULL)return 1;//递归停止条件
    return countleaf(root->lc) + countleaf(root->rc);
}


/*******************二叉树深度******************/
int depth(BTree root) {
    if (root == NULL)return 0;//递归停止条件
    int left = depth(root->lc);
    int right = depth(root->rc);
    int subDepth = (left > right) ? left : right;
    return 1 + subDepth;//当前深度+递归深度

}

/*******************二叉树第k层节点个数******************/
int kthNumber(BTree root, int k) {
    if (root == NULL || k <= 0)return 0;//递归停止条件
    if (k == 1)return 1;//递归停止条件
    return kthNumber(root->lc, k - 1) + kthNumber(root->rc, k - 1);//递归k次，得到第k层的节点总数之和
}


/*******************平衡二叉树判断******************/
int abs(int a) {
    return a > 0 ? a : -a;
}

int IsBalance(BTree root) {
    if (root == NULL)return True;//递归停止条件
    int diff = abs(depth(root->lc) - depth(root->rc));
    if (diff > 1)return False;//判断当前节点的两个子树的高度之差是否满足平衡条件，递归停止条件
    return True && IsBalance(root->lc) && IsBalance(root->rc);//递归判断全部子树
}


/*******************二叉树是否对称******************/
int IsSyncTree(BTree root) {
    if (root == NULL)return True;
    if (root->lc->data == root->rc->data)return False;
    return True && IsSyncTree(root->lc) && IsSyncTree(root->rc);
}

/*******************二叉树是否一样******************/
int compareTree(BTree root1, BTree root2) {
    if (root1 == NULL && root2 == NULL)return True;
    if (root1 == NULL || root2 == NULL)return False;
    return True && compareTree(root1->lc, root2->lc) && compareTree(root1->rc, root2->rc);
}

/*******************二叉树的镜像******************/
BTree mirrorTree(BTree root) {
    if (root == NULL)return NULL;//递归停止条件
    BTree l = mirrorTree(root->lc);
    BTree r = mirrorTree(root->rc);
    //交换左右子树
    root->lc = r;
    root->rc = l;
    return root;
}


/*******************二叉排序树判断******************/
/*BST：左子树<根<右子树*/
int IsBST(BTree root) {

}



/*******************完全二叉树树判断******************/
/*BST：左子树<根<右子树*/
int IsFullTree(BTree root) {

}


/*******************中序+先序还原二叉树******************/
int ReBuildBTree1(BTree root) {

}

/*******************中序+后序还原二叉树******************/
int ReBuildBTree2(BTree root) {

}


/*******************最远节点的距离******************/
int max(int a, int b, int c) {
    int t = a > b ? a : b;
    return t > c ? t : c;
}

/*递归计算以根节点为轴，左右子树最大深度之和就等于最远距离*/
int MaxDistance(BTree root) {

}


/*******************最近公共祖先******************/
int NearestCommonFather(BTree root) {

}