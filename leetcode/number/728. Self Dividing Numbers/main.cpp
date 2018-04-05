#include <bits/stdc++.h>

using namespace std;

bool isSelfDividingNumber(int x){
    int temp=x;
    int r;
    while(temp){
        r=temp%10;
        if(r==0)return false;
        if(x%r!=0)return false;
        temp/=10;
    }
    return true;
}

vector<int> selfDividingNumbers(int left, int right) {
    vector<int> vec;
    for(int i=left;i<=right;i++){
        if(isSelfDividingNumber(i))vec.push_back(i);
    }
    return vec;
}

int main()
{
    vector<int> rec=selfDividingNumbers(1,22);
    vector<int>::iterator iter=rec.begin();
    while(iter!=rec.end()){
        cout<<*iter<<' ';
        iter++;
    }
    return 0;
}
