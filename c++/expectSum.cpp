// 给定一个整型数组，以及一个指定的值。打印出数组中两数之和为指定值的 所有整数对
// Created by jasonhaven on 18-11-18.
//

#include <bits/stdc++.h>

void swap(int *a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int partition(int *a, int start, int end) {
    int i = start, j = end;
    int pivot = a[start];
    while (i < j) {
        while (i < j && pivot <= a[j])j--;
        swap(a, i, j);
        while (i < j && pivot >= a[i])i++;
        swap(a, i, j);
    }
    return i;
}

void sort(int *a, int start, int end) {
    if (start < end) {
        int idx = partition(a, start, end);
        sort(a, start, idx - 1);
        sort(a, idx + 1, end);
    }
}

//排序思想 O(nlogn)
void expectSum_sort(int *a, int n, int x) {
    sort(a, 0, n - 1);
    int i, j;
    for (i = 0, j = n - 1; i < j;) {
        if (a[i] + a[j] < x)i++;
        else if (a[i] + a[j] > x)j--;
        else {
            printf("(%d,%d)\n", a[i], a[j]);
            i++;
            j--;
        }
    }
}

//还可以用hashset，x-a=b,判断b是否在hashset中

int main() {
    int a[] = {1, 1, 6, 4, 4, 3, 2, 7, 4, 9, 7, 0, 5, 8, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 10;
    expectSum_sort(a, n, x);
    /*
     *  (1,9)
        (2,8)
        (3,7)
        (4,6)
     * */

    return 0;
}