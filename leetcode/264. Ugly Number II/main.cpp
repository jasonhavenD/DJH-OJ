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
		 int nums[n+1];//�������֮ǰ�ĳ���������nums[i]��ʾ��i������
		 nums[1]=1;

		 int l2 = 1;//��ʾ��һ���ñȽϵĳ�2�ڵ�
		 int l3 = 1;//��ʾ��һ���ñȽϵĳ�3�ڵ�
		 int l5 = 1;//��ʾ��һ���ñȽϵĳ�5�ڵ�

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
