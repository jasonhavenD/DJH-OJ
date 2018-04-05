#include <bits/stdc++.h>

using namespace std;

int numJewelsInStones(string J, string S) {
    int count=0;
    bool flag;
    for(int i=0;i<S.size();i++){
        flag=false;
        for(int j=0;j<J.size();j++)if(S[i]==J[j]){flag=true;break;}
        if(flag){count++;}
    }
    return count;
}

int main()
{
    int num=4;
    char s[32];
    itoa(num,s,2);
    cout<<s;
    return 0;
}
