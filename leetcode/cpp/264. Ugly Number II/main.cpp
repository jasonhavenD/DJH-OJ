#include <iostream>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

int getMin(int a,int b,int c){
    int min=a;
    if(b<min){
        min=b;
    }
    if(c<min){
        min=c;
    }
    return min;
}

int nthUglyNumber(int n) {
    if(n == 1){
			 return 1;
		 }
		 int nums[n+1];//用数组存之前的丑数，其中nums[i]表示第i个丑数
		 nums[1]=1;

		 int l2 = 1;//表示下一个该比较的乘2节点
		 int l3 = 1;//表示下一个该比较的乘3节点
		 int l5 = 1;//表示下一个该比较的乘5节点

		 for(int i = 2 ; i<=n; i++){

			 int a = nums[l2] * 2;
			 int b = nums[l3] * 3;
			 int c = nums[l5] * 5;
			 int min = getMin(a,b,c);
			 nums[i]=min;
			 if(a == min){
				 l2++;
			 }
			 if(b == min){
				 l3++;
			 }
			 if(c == min){
				 l5++;
			 }
		 }
		 return nums[n];
}

int main()
{
    return 0;
}
