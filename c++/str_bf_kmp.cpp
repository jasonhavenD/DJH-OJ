// 字符串匹配
//
// Created by jasonhaven on 18-11-6.
// http://data.biancheng.net/view/13.html
//
#include <stdio.h>
#include <bits/stdc++.h>

int brute_force_match(char *S, char *T) {
    //最坏的情况下的时间复杂度为O(n*m)
    int i = 0, j = 0;
    while (i < strlen(S) && j < strlen(T)) {
        if (S[i] == T[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == strlen(T))return i - strlen(T) + 1;
    return -1;
}

void Next(char *T, int *next) {
    //计算模板字符串的next数组[1,n]
    //注意：在此程序中，next 数组使用的下标初始值为 1 ，next[0] 没有用到。
    //串的存储是从数组的下标 0 开始的，所以程序中为 T[i-1] 和 T[j-1]。
    //每个模式串的第一个字符对应的值为 0 ，第二个字符对应的值为 1
    int i = 1;//迭代模板字符
    next[1] = 0;
    int j = 0;
    while (i < strlen(T)) {
        if (j == 0 || T[i - 1] == T[j - 1]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }

}

int KMP(char *S, char *T) {
    //计算next数组
    int next[strlen(T) + 1];
    Next(T, next);
    int i = 1, j = 1;//从1开始
    while (i <= strlen(S) && j <= strlen(T)) {
        if (j == 0 || S[i - 1] == T[j - 1]) {//两种情况下，指向当前测试的两个指针下标i和j都向后移
            //j==0:代表模式串的第一个字符就和指针i指向的字符不相等
            //S[i-1]==T[j-1],对应位置字符相等
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j > strlen(T))return i - strlen(T);
    return -1;
}

void Print(int *a, int n) {
    for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int idx = brute_force_match("ababcabcacbab", "abcac");//6
    printf("%d\n", idx);
    int n = strlen("abcac");
    int next[n + 1];
    Next("abcac", next);
    Print(next, n);//0 1 1 1 2
    idx = KMP("ababcabcacbab", "abcac");//6
    printf("%d\n", idx);
    return 0;
}
