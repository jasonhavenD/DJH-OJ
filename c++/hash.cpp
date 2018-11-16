// 使用hash实现序列去重
// Created by jasonhaven on 18-11-16.
//

#include <bits/stdc++.h>
#include <map>

using namespace std;

int main() {
    int a[] = {1, 1, 2, 2, 3, 3, 6, 6, 5, 5, 8, 8, 7, 7, 4, 4};
    int n = sizeof(a) / sizeof(int);//16

    //创建哈希表对象
    map<int, int> hash;

    //遍历序列
    for (int i = 0; i < n; ++i) {
        //将元素作为主键加入到哈希表中
        int key = a[i];
        int val = 0;//只对元素去重，val无所谓，如果要对元素计数，则val要更新计数结果
        hash.insert(pair<int, int>(key, val));
    }

    //输出去重结果
    map<int, int>::iterator iter;
    for (iter = hash.begin(); iter != hash.end(); iter++) {
        printf("%d ", iter->first);//iter->first 表示主键key，iter->second表示值val，在不同语言不同写法，但都有类似操作
    }

    return 0;
}

