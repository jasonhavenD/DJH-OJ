class Solution:
    def removeDuplicates(self, nums):
        i=0
        for x in nums[:-1]:
            if x == nums[i+1]:
                #nums[i:]=nums[i+1:]
                nums.remove(x)
                i-=1
            i+=1
        return len(nums)
        