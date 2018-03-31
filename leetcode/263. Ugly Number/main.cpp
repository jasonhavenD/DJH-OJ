#include <bits/stdc++.h>

using namespace std;


class Solution {
public:

 bool isUgly(int num) {
    if(num<=0)
        return 0;

    int rem2 = num % 2;
    int rem3 = num % 3;
    int rem5 = num % 5;

    while(rem2 == 0 || rem3 == 0 || rem5 == 0) {
        if(rem2 == 0) {
            num = num / 2;
        } else if(rem3 == 0) {
            num = num / 3;
        } else {
            num = num / 5;
        }
        rem2 = num % 2;
        rem3 = num % 3;
        rem5 = num % 5;
    }
    return num == 1;
}

};
int main()
{

    return 0;
}
