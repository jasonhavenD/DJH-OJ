#include <bits/stdc++.h>

using namespace std;

vector<int> numberOfLines(vector<int>& widths, string S) {
    vector<int> rst;
    int lines=0;
    int r=0;
    int total=0;
    for(int i=0;i<S.length();i++){
        if(total+widths[S[i]-'a']<=100)
            total+=widths[S[i]-'a'];
        else{
            lines++;
            total=widths[S[i]-'a'];
        }
    }
    r=total%100;
    if(r)lines++;
    rst.push_back(lines);
    rst.push_back(r);
    return rst;
}

int main()
{

    return 0;
}
