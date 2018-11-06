//
// 线性表
// Created by jasonhaven on 18-11-6.
//
#include <stdio.h>
#include <bits/stdc++.h>

/**顺序表**/
typedef struct Table {
    int *head;//动态数组
    int len;//顺序表长度
    int size;//动态数组的存储容量
} table;

/*
 * 顺序表初始化
 *
 * */
table initTable(int s) {
    table t;
    t.head = (int *) malloc(s * sizeof(int));
    if (!t.head) {//内存分配失败
        printf("初始化失败！");
        exit(0);
    }
    t.size = s;
    t.len = 0;
    return t;
}

/*
 * 顺序表查找元素
 *
 * */
int selectTable(table t, int k) {
    int i;
    for (i = 0; i < t.len; i++) {
        if (k == t.head[i])return i;
    }
    return -1;
}

/*
 * 顺序表中更改元素
 *
 * */
table updateTable(table t, int e, int new_e) {
    int idx = selectTable(t, e);
    t.head[idx] = new_e;
    return t;
}

/*
 * 顺序表插入元素
 *
 * */
table insertTable(table t, int idx, int e) {
    if (idx < 0 || idx > t.len) {
        printf("插入位置有问题！");
        return t;
    }
    if (t.len == t.size) {
        t.head = (int *) realloc(t.head, (t.size + 1) * sizeof(int));//在原来的空间保留的基础上扩容，调整已分配的内存
        if (!t.head) {//内存分配失败
            printf("调整内存失败！");
            exit(0);
        }
    }
    //插入操作，需要将从插入位置开始的后续元素，逐个后移
    int i;
    for (i = t.len - 1; i >= idx; i--) {
        t.head[i + 1] = t.head[i];
    }
    t.head[idx] = e;
    t.len++;
    return t;
}

/*
 * 顺序表删除元素
 * 前移的过程中被删除元素被后一个元素覆盖掉，间接实现了删除操作
 * */
table deleteTable(table t, int idx) {
    if (idx < 0 || idx > t.len) {
        printf("删除位置有问题！");
        return t;
    }
    int i;
    for (i = idx; i < t.len - 1; i++) {
        t.head[i] = t.head[i + 1];//覆盖
    }
    t.len--;
    return t;
}

void displayTable(table t) {
    for (int i = 0; i < t.len; i++) {
        printf("%d", t.head[i]);
    }
    printf("\n");
}
/*
int main() {
    int Size = 4;
    table t1 = initTable(Size);
    for (int i = 0; i < Size; i++) {
        t1.head[i] = i;
        t1.len++;
    }
    printf("原顺序表：\n");
    displayTable(t1);

    printf("删除元素1:\n");
    t1 = deleteTable(t1, 1);
    displayTable(t1);

    printf("在第2的位置插入元素5:\n");
    t1 = insertTable(t1, 2,5);
    displayTable(t1);

    printf("查找元素3的位置:\n");
    int add = selectTable(t1, 3);
    printf("%d\n", add);

    printf("将元素3改为6:\n");
    t1 = updateTable(t1, 3, 6);
    displayTable(t1);

    return 0;
}
*/