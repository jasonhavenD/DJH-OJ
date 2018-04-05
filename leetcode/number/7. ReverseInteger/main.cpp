#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int reverse(int x) {
        long long rst=0;
        if(x<INT_MIN||x>INT_MAX)return 0;
        //cout<<INT_MAX<<endl<<INT_MIN<<endl;
        if(x>0){
            while(x){
                rst*=10;
                rst+=x%10;
                x=x/10;
                if(rst<INT_MIN||rst>INT_MAX)return 0;
            }
        }else{
            x=-x;
            while(x){
                rst*=10;
                rst+=x%10;
                x=x/10;
                if(rst<INT_MIN||rst>INT_MAX)return 0;
            }
            rst=-rst;
        }
        return rst;
    }
};

int main(){
    Solution s=Solution();
    int x;
    while(cin>>x){
        cout<<s.reverse(x)<<endl;
    }
    return 0;
}
