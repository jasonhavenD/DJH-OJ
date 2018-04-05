#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    cin>>num;
    unsigned mask = ~0;
    while (num & mask) mask <<= 1;
    cout<<(~mask&~num);
}
