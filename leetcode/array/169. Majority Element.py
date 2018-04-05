from collections import defaultdict
class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans=defaultdict(int)
        for n in nums:
            ans[n]=ans[n]+1
        return sorted(ans.items(), key=lambda d: d[1],reverse=True)[0][0]
        