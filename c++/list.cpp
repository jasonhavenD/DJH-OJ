#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 1

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/*******************创建带头结点链表******************/
struct Node *Create(int n) {
    Node *head = (Node *) malloc(sizeof(Node));//(初始化)声明头结点，分配空间
    head->next = NULL;//初始化指针为空
    //创建链表
    Node *q = head;
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);//输入数据
        Node *p = (Node *) malloc(sizeof(Node));//创建新节点
        p->data = x;//更新数据
        //尾插法,得到输入顺序的链表
        p->next = q->next;//更新指针
        q->next = p;
        q = p;//尾插的关键是该指针一直指向链表尾部，如果没有这句就是头插法
    }
    return head;
};

/*******************遍历带头结点链表******************/
void tranverce(Node *head) {
    Node *p = head->next;//第一个元素是头结点之后的元素
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;//更新迭代器
    }
    printf("\n");
}

/*******************销毁链表******************/
void destory(Node *head) {
    Node *p;
    while (head != NULL) {
        p = head;
        head = head->next;//更新迭代器
        free(p);
    }
}

/*******************逆序链表******************/
Node *reverse1(Node *head) {
    Node *new_head = (Node *) malloc(sizeof(Node));//初始化新的链表头结点
    new_head->next = NULL;

    head = head->next;//从第一个元素开始
    while (head != NULL) {
        Node *t = (Node *) malloc(sizeof(Node));
        t->data = head->data;
        //头插法,得到输入逆序的链表
        t->next = new_head->next;
        new_head->next = t;
        head = head->next;//更新迭代器
    }
    return new_head;
}

/*******************逆序链表 - 就地逆置算法******************/
void reverse2(Node *head) {
    Node *p = head->next;
    head->next = NULL;
    while (p != NULL) {
        Node *q = p;
        p = p->next;//更新迭代器,顺序不能改变
        q->next = head->next;
        head->next = q;
    }
}

/*******************链表长度******************/
int length(Node *head) {
    int i = 1;
    Node *p = head->next;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    return i - 1;
}

/*******************在第i个位置后面插入节点******************/
void insert1(Node *head, int idx, int data) {//注意，在使用链表的时候，通常使用逻辑下标(从1开始),idx==[1,n]
    int len = length(head);
    if (idx < 1 || idx > len)return;
    Node *p = head;
    int i = 0;//计数器
    while (p != NULL && i < idx) {
        p = p->next;
        i++;
    }//循环结束，i==idx,i控制的是待插入元素的前一个元素
    Node *t = (Node *) malloc(sizeof(Node));
    t->data = data;
    t->next = p->next;
    p->next = t;
}

/*******************插入节点到第i个位置******************/
void insert2(Node *head, int idx, int data) {//注意，在使用链表的时候，通常使用逻辑下标(从1开始),idx==[1,n]
    int len = length(head);
    if (idx < 1 || idx > len)return;
    Node *p = head;
    int i = 0;//计数器
    while (p != NULL && i < idx - 1) {
        p = p->next;
        i++;
    }//循环结束，i==idx-1,i控制的是待插入元素的前一个元素
    Node *t = (Node *) malloc(sizeof(Node));
    t->data = data;
    t->next = p->next;
    p->next = t;
}

/*******************删除指定第i个位置的节点******************/
int remove(Node *head, int idx) {//注意，在使用链表的时候，通常使用逻辑下标(从1开始),idx==[1,n]
    int len = length(head);
    if (idx < 1 || idx > len)return -1;
    Node *p = head;
    int i = 0;//计数器
    while (p != NULL && i < idx - 1) {
        p = p->next;
        i++;
    }//循环结束，i==idx-1,i控制的是待删除元素的前一个元素
    Node *q = p;
    int ans = q->data;
    p->next = p->next->next;
    free(q);//释放空间
    return ans;

}

/*******************删除指定元素的节点******************/
void remove2(Node *head, int val) {//注意，在使用链表的时候，通常使用逻辑下标(从1开始),idx==[1,n]
    Node *pre = head;
    Node *cur = head->next;
    while (cur != NULL) {
        if (val == cur->data) {
            Node *tmp = cur;
            pre->next = cur->next;
            cur = cur->next;
            free(tmp);
        } else {
            pre = cur;
            cur = cur->next;
        }
    }
}


/*******************查找节点******************/
int search(Node *head, int val) {//注意，在使用链表的时候，通常使用逻辑下标(从1开始),idx==[1,n]
    Node *p = head;
    int i = 0;//计数器
    while (p != NULL && p->data != val) {
        p = p->next;
        i++;
    }
    return (p == NULL) ? -1 : i;
}

/*******************合并两个有序链表******************/
Node *merge(Node *h1, Node *h2) {
    if (h1 == NULL) {
        return h2;
    }
    if (h2 == NULL) {
        return h1;
    }
    Node *merged = NULL;
    if (h1->data < h2->data) {
        merged = h1;
        merged->next = merge(h1->next, h2);
    } else {
        merged = h2;
        merged->next = merge(h1, h2->next);
    }
    return merged;
}


/*******************合并两个有序链表******************/
Node *merge2(Node *h1, Node *h2) {
    Node *p = h1->next;
    Node *q = h2->next;
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            printf("%d ", p->data);
            p = p->next;
        } else {
            printf("%d ", q->data);
            q = q->next;
        }
    }
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    while (q != NULL) {
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}

//int main() {
//    Node *l = Create(4);//1 2 3 4
//    tranverce(l);

//    reverse1(l);
//    reverse2(l);
//    printf("%d", length(l));
//    insert1(l, 1, 0);//1 0 2 3 4
//    insert2(l, 1, 0);//0 1 2 3 4
//    remove(l,1);//1
//    printf("%d", search(l, 3));//3
//    printf("%d", search(l, 2));//2
//    remove2(l, 3);//1 2 4


//    Node *l1 = Create(4);//1 2 3 4
//    Node *l2 = Create(4);//3 4 5 6
//    tranverce(l1);
//    tranverce(l2);
//    Node *merged = (Node *) malloc(sizeof(Node));
//    merged->next = merge(l1->next, l2->next);
//    tranverce(merged);//1 2 3 3 4 4 5 6
//    Node *merged = merge2(l1, l2);
//    destory(l1);
//    destory(l2);
//    destory(merged);
//    return 0;
//}