#!/usr/bin/python
# -*- coding: utf-8 -*-
"""
-------------------------------------------------
   File Name:447. Number of Boomerangs
   Author:jasonhaven
   date:18-10-5
-------------------------------------------------
   Change Activity:18-10-5:
-------------------------------------------------
"""

import collections


class Solution:
	def numberOfBoomerangs(self, points):
		ans = 0
		for x1, y1 in points:
			dmap = collections.defaultdict(int)
			for x2, y2 in points:
				dmap[(x1 - x2) ** 2 + (y1 - y2) ** 2] += 1
			for d in dmap:
				ans += dmap[d] * (dmap[d] - 1)
		return ans


if __name__ == '__main__':
	points = [[0, 0], [1, 0], [2, 0]]
	s = Solution()
	print(s.numberOfBoomerangs(points))
