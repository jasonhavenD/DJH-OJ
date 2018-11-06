#!/usr/bin/python
# -*- coding: utf-8 -*-
"""
-------------------------------------------------
   File Name:628. Maximum Product of Three Numbers
   Author:jasonhaven
   date:18-10-5
-------------------------------------------------
   Change Activity:18-10-5:
-------------------------------------------------
"""


class Solution:
	def maximumProduct(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""
		nums=sorted(nums)
		if (nums[-1] < 0):
			return nums[-1] * nums[-2] * nums[-3]
		a = nums[-1] * nums[-2] * nums[-3]
		b = nums[-1] * nums[0] * nums[1]
		return a if (a > b) else b


if __name__ == '__main__':
	s = Solution()
	a = [-4, -3, -2, -1, 60]
	b = [9, 1, 5, 6, 7, 2]
	print(s.maximumProduct(a))
