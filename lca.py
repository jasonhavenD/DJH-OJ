#!/usr/bin/python
# -*- coding: utf-8 -*-
"""
-------------------------------------------------
   File Name:lca
   Author:jasonhaven
   date:18-11-15
-------------------------------------------------
   Change Activity:18-11-15:
-------------------------------------------------
"""


def depth(node):
	'''求节点的高度'''
	depth = 0
	while node.parent != None:
		depth += 1
		node = node.parent
	return depth


def common_parent(root, node1, node2):
	'''查找二叉树任意两个节点的最近公共祖先'''
	depth1 = depth(node1)
	depth2 = depth(node2)

	# 将深度更深的节点上升，直到两者相同高度
	while depth1 < depth2:
		depth2 -= 1
		node2 = node2.parent
	while depth1 > depth2:
		depth1 -= 1
		node1 = node1.parent

	# 达到同一深度之后，判断是否相同，相同则找到祖先，否则同时上升，一边上什一边判断
	while node1 and node2 and node1 != node2:
		node1 = node1.parent
		node2 = node2.parent

	if node1 == node2:
		return node1
	else:
		return None
