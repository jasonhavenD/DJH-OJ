#include <bits/stdc++.h>

using namespace std;

bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i*i <= num; ++i) {
            if (num%i == 0) return false;
        }
        return true;
    }
int countPrimes(int n)
{
    int count=0;
    int flag;
    if(n<2)return 0;
    for(int x=2; x<n; x++)
    {
        if(isPrime(x))count++;
    }
    return count;
}
int main()
{
    cout<<countPrimes(10);
    return 0;
}
