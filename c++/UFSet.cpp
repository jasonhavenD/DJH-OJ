// 并查集
// Created by jasonhaven on 18-12-2.
// https://www.cnblogs.com/hapjin/p/5478352.html
#include <bits/stdc++.h>

const int N = 20;
int S[N];

void Initial(int n) {
    for (int i = 0; i < n; ++i) {
        S[i] = -1;
    }
}

void Print(int n) {
    printf("index | parent\n");
    for (int i = 0; i < n; ++i) {
        printf("%d | %d\n", i, S[i]);
    }
}

void Union(int root1, int root2) {
    //将两个不相交的子集合合并成一个大集合
    S[root1]+=S[root2] ;//可有可无，类似于记录当前子集合的元素个数
    S[root2] = root1;//将root1作为root2的新树根
}

int Find(int x) {
    //查找元素x所在的集合
    if (S[x] < 0)//直到找到集合的根
        return x;
    else
        return Find(S[x]);//递归继续找
}

void CountSet(int n) {
    for (int i = 0; i < n; ++i) {
        if (S[i] < 0) {
            printf("当前子集合：%d ,有：", i);
            for (int j = 0; j < n; ++j) {
                if (S[j] == i) {
                    printf("%d ", j);
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int n = 10;
    Initial(n);
    Print(n);
    Union(0, 6);
    Union(0, 7);
    Union(0, 8);
    Union(1, 4);
    Union(1, 9);
    Union(2, 3);
    Union(2, 5);
    Print(n);
    CountSet(n);
    Union(0, 1);
    Print(n);
    CountSet(n);
    return -1;
}

/*
index | parent
0 | -1
1 | -1
2 | -1
3 | -1
4 | -1
5 | -1
6 | -1
7 | -1
8 | -1
9 | -1
index | parent
0 | -4
1 | -3
2 | -3
3 | 2
4 | 1
5 | 2
6 | 0
7 | 0
8 | 0
9 | 1
当前子集合：0 ,有：6 7 8
当前子集合：1 ,有：4 9
当前子集合：2 ,有：3 5
index | parent
0 | -7
1 | 0
2 | -3
3 | 2
4 | 1
5 | 2
6 | 0
7 | 0
8 | 0
9 | 1
当前子集合：0 ,有：1 6 7 8
当前子集合：2 ,有：3 5
 * */

