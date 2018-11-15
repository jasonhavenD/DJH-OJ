// 斐波那契数列
// Created by jasonhaven on 18-11-15.
//
#include <bits/stdc++.h>

int Recursive(int n) {
    if (n == 1 || n == 2)return 1;
    return Recursive(n - 1) + Recursive(n - 2);
}

int NoRecursive(int n) {
    int a[n];
    a[0] = a[1] = 1;
    for (int i = 2; i < n; ++i) {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n - 1];
}
/*
int main() {
    for (int i = 1; i < 10; ++i) {
        printf("%d %d\n", Recursive(i), NoRecursive(i));
    }

    return 0;
}
*/
/*
    1 1
    1 1
    2 2
    3 3
    5 5
    8 8
    13 13
    21 21
    34 34
*/