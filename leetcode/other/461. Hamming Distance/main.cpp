#include <bits/stdc++.h>

using namespace std;

int hammingDistance(int x, int y) {
    int res = 0, exc = x ^ y;
        for (int i = 0; i < 32; ++i) {
            res += (exc >> i) & 1;
        }
        return res;
}

int main()
{

    cout<<hammingDistance(1,4);
    return 0;
}
