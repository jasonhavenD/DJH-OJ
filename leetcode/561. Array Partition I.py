class Solution:
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        bigrams=[(a,b) for a,b in zip(nums,nums[1:])][::2]
        return sum(a for a,b in bigrams)