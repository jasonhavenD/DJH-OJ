// 线索二叉树
// Created by jasonhaven on 18-11-18.
//

#include<bits/stdc++.h>


//线索二叉树中的数据域的存储类型,使用宏定义能实现一改全改的效果
typedef char ElemType;

//枚举类型,代表着标志域指示的指针域指向的是子结点还是前驱后继结点,能更加方便直观的看懂代码
typedef enum {
    Link, Thread
} PointerTag;

//结点的存储结构
typedef struct BiThrNode {
    ElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag ltag, rtag;
} BiThrNode, *BiThrTree;

//线索二叉树的中序递归线索化过程: 创建中序未线索化二叉树，


//前序递归创建一个未线索化的二叉树
void createBiThrTree(BiThrTree *tree) {
    char c;
    scanf("%c", &c);
    if ('#' == c) { //若输入的是空格,则不创建该结点,使得递归可以结束
        *tree = NULL;
    } else {

        *tree = ((BiThrTree) malloc(sizeof(BiThrNode)));
        //设置其数据域
        (*tree)->data = c;
        //未线索化的过程
        (*tree)->ltag = Link;
        (*tree)->rtag = Link;

        //递归生成其左子结点
        createBiThrTree(&(*tree)->lchild);
        //递归生成其右子结点
        createBiThrTree(&(*tree)->rchild);
    }
}

BiThrNode *pre = NULL;
/*定义一个全局BiThrNode* 类型的指针变量pre(顾名思义就是上一个创建出来的结点),
 * 用于在递归生成结点的时候,记录上次的结点用于让生成的结点的前驱指针指向前驱的结点,
 * 然后再通过判断,若该pre结点rchild指针没有所指向,让其指向后继的结点(就是刚刚生成的结点).
 * */



//中序遍历线索化
void inThreading(BiThrTree tree) {//线索二叉树的根结点指针变量
    if (tree) {

        inThreading(tree->lchild); //递归左孩子线索化

        //中序遍历处理内容
        if (!tree->lchild) { //如果该结点没有左孩子,设置ltag为Thread,并把lChild指向前驱结点
            tree->ltag = Thread;
            tree->lchild = pre;
        }

        if (!pre->rchild) {//处理pre结点(也就是上一个创建的结点),若其无右孩子,则令pre的rChild指向后继结点
            pre->rtag = Thread;
            pre->rchild = tree;
        }

        pre = tree;//令pre全局变量指向已经处理完毕的结点,令下个结点继续处理
        //中序遍历处理结束

        inThreading(tree->rchild);//递归右孩子线索化
    }
}



//创建头结点.
/*
 * 增设一个头结点，令其lchild指向二叉树的根结点，ltag=0、rtag=1；
 * 并将该结点作为遍历访问的第一个结点的前驱和最后一个结点的后继；
 * 最后用头指针指示该头结点。其rchild域的指针指向中序遍历时访问的最后一个结点；
 * 反之，令二叉树中序序列中的第一个结点的lchild域指针和最后一个结点rchild域的指针均指向头结点，
 * 这好比为二叉树建立了一个双向线索链表，既可以从第一个结点起顺后继进行遍历，也可以从最后一个结点起顺前驱进行遍历。
 * */
void inOrderThreading(BiThrTree *head, BiThrTree tree) {//head 作为指向头结点的结点指针变量, tree 线索二叉树的根结点指针变量
    //创建头结点
    *head = (BiThrTree) malloc(sizeof(BiThrNode));
    //设置该头结点的左右标志位分别为非线索与线索
    //递归线索化的过程能使得第一个结点的前驱正确指向该头结点.
    (*head)->ltag = Link;
    (*head)->rtag = Thread;
    if (!tree) {
        //若根结点不存在,则该二叉树为空,让该头结点指向自身.
        (*head)->lchild = *head;
    } else {
        //令头结点的左指针指向根结点
        (*head)->lchild = tree;
        pre = *head;
        //开始递归输入线索化
        inThreading(tree);
        //此时结束了最后一个结点的线索化了,下面的代码把头结点的后继指向了最后一个结点.
        //并把最后一个结点的后继也指向头结点,此时树成为了一个类似链表的循环.
        pre->rchild = *head;
        pre->rtag = Thread;
        (*head)->rchild = pre;
    }
}


//访问该数据的函数,这里就简单的打印出来.
void visit(ElemType data) {
    printf("%c", data);
}

//带头结点的线索二叉树，以迭代的形式去中序遍历线索二叉树.
int inOrderTraverseThr(BiThrTree T) {

    BiThrTree p = T->lchild;    //令p先指向根节点.

    //退出循环的条件是p重新指回了头结点.
    while (p != T) {

        while (p->ltag == Link)
            p = p->lchild;  //迭代令p指向左子树为空的结点.

        visit(p->data);

        //如果该结点没有右子结点,则不执行下面while语句里面的语句,即令下次循环遍历该结点的右子结点.
        //如果下一个节点就是头结点,则也不进入下面while语句的循环体中.
        //下面的语句就是利用Thread的作用直接去判断,从而调用下一个需要遍历的结点(线索化的优点就出来了).
        while (p->rtag == Thread && p->rchild != T) {
            p = p->rchild;
            visit(p->data);
        }

        //令p指向下一个结点,可以是右子结点,也可以是后继结点,取决于此时tag域的信息.
        p = p->rchild;

    }


    return 1;
}

void inOrder(BiThrNode *root) {
    if (root) {
        inOrder(root->lchild);
        printf("%c", root->data);
        inOrder(root->rchild);
    }
}

//中序线索的第一个节点
BiThrNode *FirstNode(BiThrNode *q) {
    while (q->ltag == Link)//如果有左孩子
        q = q->lchild;//沿左链往下查找
    return q;
}

//中序线索的最后一个节点
BiThrNode *LastNode(BiThrNode *q) {
    while (q->rtag == Link)
        q = q->rchild;//沿右链往下查找
    return q;
}

//中序线索的节点后继
BiThrNode *NextNode(BiThrNode *p) {
    if (p->rtag == Link) {//rtag==0
        return FirstNode(p->rchild);//从*p的右孩子开始查找，查找p的右孩子的最左下端结点
    } else {
        return p->rchild;//后继线索
    }
}

//中序线索的节点前驱
BiThrNode *PreNode(BiThrNode *p) {
    if (p->ltag == Link) {//rtag==0
        return LastNode(p->rchild);//从*p的左孩子开始查找，查找p的左孩子的最右下端结点
    } else {
        return p->lchild;//前驱线索
    }
}

//所以，可以根据first和next实现遍历
void inOrderTraverseThr2(BiThrNode *t) {
    for (BiThrNode *p = t->lchild; p != t; p = NextNode(p)) {//注意带头结点，起点和停止条件区别
        visit(p->data);
    }
}


//所以，可以根据last和pre实现遍历
void inOrderTraverseThr3(BiThrNode *t) {
    for (BiThrNode *p = LastNode(t->lchild); p != t; p = PreNode(p)) {//注意带头结点，起点和停止条件区别
        visit(p->data);
    }
}



/*

ABC##DE#G##F###
中序遍历二叉树：CBEGDFA
中序线索化遍历的结点为:CBEGDFA

 * */
/*
int main() {

    BiThrTree tree = NULL, head = NULL;

    //创建二叉树
    createBiThrTree(&tree);//ABC##DE#G##F###
    printf("中序遍历二叉树：");
    inOrder(tree);

    //线索化二叉树的过程
    inOrderThreading(&head, tree);
    printf("\n中序线索化遍历的结点为:");
    //遍历整棵线索二叉树head
    inOrderTraverseThr(head);
    return 0;
}*/
