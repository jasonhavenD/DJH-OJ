class Solution:
    def moveZeroes(self, nums):
        for i in range(len(nums)):
            if nums[i]==0:
                nums.remove(nums[i])
                nums.append(0)
