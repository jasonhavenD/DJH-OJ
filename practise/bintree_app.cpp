#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>

using namespace std;
#define MIN -999999
#define True 1
#define False 0
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
/*BST：左子树<根<右子树
 *
节点的左子树中任意节点值小于根节点
节点的右子树中任意节点值大于根节点
左右子树都必须是二叉查找树，不允许存在重复节点。
 * */

int flag = True;
TElemType previous = MIN;

int IsBST(BTree root) {//借助中序遍历的结果判断是否存在逆序
    if (root->lc != NULL && flag == True)IsBST(root->lc);//判断左子树

    if ((previous > root->data))flag = False;
    previous = root->data;//保存中序遍历的节点，下一次比较使用

    if (root->rc != NULL && flag == True)IsBST(root->rc);//判断右子树

    return flag;
}



/*******************完全二叉树树判断******************/
/*深度为k,节点数为2^k -1的二叉树是满二叉树，完全二叉树是与满二叉树的编号所对应的，注意区别*/
/*对二叉树进行层序遍历，如果在没有遍历完就遇到了空位，则说明不是完全二叉树*/
/*有图片帮助理解*/
int IsFullTree(BTree root) {
    if (root)return True;//假设空树也是完全二叉树
    queue<BNode *> queue;
    queue.push(root);
    root = queue.front();
    while (root) {//按照层序遍历的办法入队列直到遇到第一个NULL停止
        if (root->lc != NULL)queue.push(root->lc);//左孩子
        if (root->rc != NULL)queue.push(root->rc);//右孩子
        queue.pop();
        root = queue.front();
    }
    while (!queue.empty())//如果队列中全为NULL则是完全二叉树，否则不是
    {
        if (queue.front())//如果当前队列元素不是NULL
            return false;
        queue.pop();//继续判断下一个元素是不是NULL
    }
    return True;
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