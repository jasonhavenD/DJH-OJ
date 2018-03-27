#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rst;
        int buffer[nums.size()];
        memcpy(buffer, &nums[0], nums.size()*sizeof(int));
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(buffer[i]+buffer[j]==target){
                    rst.push_back(i);
                    rst.push_back(j);
                }
            }
        }

        return rst;
    }
};

int main()
{
    Solution s=Solution();
    vector<int> v;
    v.push_back(2);
    v.push_back(7);
    v.push_back(11);
    v.push_back(15);
    v=s.twoSum(v,9);
    vector<int>::iterator it=v.begin();
    while(it!=v.end()){
        cout<<*it++<<endl;
    }
    return 0;
}
