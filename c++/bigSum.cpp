// 大整数求和
// Created by jasonhaven on 18-11-21.
//
#include <bits/stdc++.h>

void sumOfTwo(int a[], int n, int b[], int m) {
    int N = m > n ? m + 1 : n + 1;//数组长度等于较大整数位数+1
    int ans[N];//结果数组
    for (int i = 0; i < N; ++i) {
        ans[i] = 0;
    }
    int sum;
    for (int i = 0; i < N - 1; ++i) {
        if (i < m && i < n)
            sum = a[i] + b[i];
        else if (i < n)sum = a[i];
        else sum = b[i];
        ans[i] += (sum) % 10;//求和
        ans[i + 1] = (sum) / 10;//进位
    }

    int i;
    for (i = (a[N - 1] != 0) ? N - 2 : N - 1; i >= 0; i--) {//逆序输出
        printf("%d", ans[i]);
    }
}


int main() {
    //1.把两个大整数用数组逆序存储
    int a[] = {1, 2, 3, 5, 2, 1, 4, 6, 3, 4, 5};
    int b[] = {1, 2, 3, 6, 1, 6, 3, 7, 2};

    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);

    for (int i = n1 - 1; i >= 0; i--) {
        printf("%d", a[i]);
    }
    printf("\n");
    for (int i = n2 - 1; i >= 0; i--) {
        printf("%d", b[i]);
    }
    printf("\n");
    sumOfTwo(a, n1, b, n2);
    return 0;
}

