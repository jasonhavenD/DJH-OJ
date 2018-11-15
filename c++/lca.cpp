//
// Created by jasonhaven on 18-11-15.
//
#include <bits/stdc++.h>

int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int depth(int i) {
    int depth = 0;
    i = (i - 1) / 2;
    while (i != 0) {
        depth += 1;
        i = (i - 1) / 2;
    }
    return depth;
}


int lca(int i, int j) {
    int depth1 = depth(i);
    int depth2 = depth(j);

    //将深度更深的节点上升，直到两者相同高度
    while (depth1 < depth2) {
        depth2 -= 1;
        j = (j - 1) / 2;
    }
    while (depth2 < depth1) {
        depth1 -= 1;
        i = (i - 1) / 2;
    }
    //达到同一深度之后，判断是否相同，相同则找到祖先，否则同时上升，一边上什一边判断

    while (a[i] != a[j]) {
        i = (i - 1) / 2;
        j = (j - 1) / 2;
    }
    return i;
}

int main() {
    int x = lca(3, 4);//1
    printf("%d\n", x);
    x = lca(5, 6);//2
    printf("%d\n", x);
    return 0;
}
