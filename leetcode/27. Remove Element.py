class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        cnt=0
        for x in nums:
            if x != val:
                nums[cnt]=x
                cnt+=1
        return cnt
            