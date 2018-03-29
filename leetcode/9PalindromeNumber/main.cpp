#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(long long  x) {
        if(x<INT_MIN||x>INT_MAX)return false;
        if(x<0||(x!=0&&x%10==0))return false;

        long long  y=x;

        long long t=0;
        while(x){
            t*=10;
            t+=x%10;
            x/=10;
        }
        return y==t;
    }
};

int main()
{
    Solution s=Solution();
    int x;
    cin>>x;
    cout<<s.isPalindrome(x)<<endl;
    return 0;
}
