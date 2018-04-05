#include <bits/stdc++.h>

using namespace std;

int main()
{
    string moves;
    cin>>moves;
    int up=0,down=0,left=0,right=0;
    for(int i=0;i<moves.length();i++){
        if(moves[i]=='U'){
            up++;
        }
        if(moves[i]=='D'){
            down++;
        }
        if(moves[i]=='L'){
            left++;
        }
        if(moves[i]=='R'){
            right++;
        }
    }
    if(up==down&&left==right)cout<<true;
    else cout<<false;
    return 0;
}
