//
// 线性表
//
// Created by jasonhaven on 18-11-6.
//

#include <stdio.h>
#include <bits/stdc++.h>

typedef int E;

/**链表**/
typedef struct node {
    E data;//代表数据域
    struct node *next;//代表指针域，指向直接后继元素
} node, *list;

/*
 *链表初始化
 *
 * */
list initList() {
    list head = (node *) malloc(sizeof(node));
    node *p = head;
    for (int i = 0; i < 5; ++i) {
        node *tmp = (node *) malloc(sizeof(node));//创建新节点
        tmp->data = i;
        tmp->next = NULL;
        p->next = tmp;//插入到链表
        p = p->next;
    }
    return head;
}

/*
 *链表查找元素
 *
 * */
int selectList(list t, int k) {
    node *p = t->next;//带头结点
    int i = 0;
    while (p) {
        if (k == p->data)return i;
        p = p->next;
        i++;
    }
    return -1;
}

/*
 *链表中更改元素
 *
 * */
void updatelist(list t, int idx, int new_e) {
    node *p = t->next;//带头结点
    for (int i = 0; i < idx; ++i) {
        p = p->next;
    }
    p->data = new_e;
}

/*
 *链表插入元素
 *
 * */
void insertList(list t, int idx, int e) {
    node *pre = t;
    for (int i = 0; i < idx - 1; ++i) {//首先找到要插入位置的上一个结点
        pre = pre->next;
    }
    node *tmp = (node *) malloc(sizeof(node));//创建新节点
    tmp->data = e;
    tmp->next = NULL;
    tmp->next = pre->next;//插入到链表
    pre->next = tmp;
}

/*
 *链表删除元素
 * 前移的过程中被删除元素被后一个元素覆盖掉，间接实现了删除操作
 * */
void deleteList(list t, int idx) {
    node *pre = t;
    for (int i = 0; i < idx - 1; ++i) {//首先找到要插入位置的上一个结点
        pre = pre->next;
    }
    node *tmp = pre->next;
    pre->next = tmp->next;
    free(tmp);
}

void displayList(list t) {
    node *p = t->next;//带头结点
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
/*
int main() {
    list head = initList();
    displayList(head);
    int i = selectList(head, 0);
    printf("%d\n", i);
    updatelist(head, 0, 10);
    displayList(head);
    updatelist(head, 1, 11);
    displayList(head);
    insertList(head, 0, 0);
    displayList(head);
    deleteList(head,0);
    displayList(head);
    deleteList(head,0);
    displayList(head);
    return 0;
}
 */