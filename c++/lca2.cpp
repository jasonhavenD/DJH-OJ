//
// Created by jasonhaven on 18-11-15.
//
#include <stdio.h>

int level(int x) {
    if (x == 1)return 1;
    int ans = 2;
    while (x / 2 != 1) {
        ans++;
        x /= 2;
    }
    return ans;
}

int getLCA(int a, int b) {
    if (a == 1 || b == 1)return 1;
    if (a == b)return a;
    int h1 = level(a);
    int h2 = level(b);
    if (h1 <= h2)return getLCA(a, b / 2);
    else return getLCA(a / 2, b);
}

int main() {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 1; i <= 9; ++i) {
        printf("node %d in level %d \n", a[i], level(i));
    }
    printf("%d", getLCA(8, 9));
    return 0;
}