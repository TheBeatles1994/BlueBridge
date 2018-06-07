# -*- coding:utf-8 -*-
class TreeNode:
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
class Solution:
	# 返回构造的TreeNode根节点
	def reConstructBinaryTree(self, pre, tin):
		# write code here
		if(pre == [] or tin == []):
			return None
		else:
			rst = TreeNode(pre[0])
			rst.left = self.reConstructBinaryTree(pre[1:tin.index(pre[0])+1], tin[0:tin.index(pre[0])])
			rst.right = self.reConstructBinaryTree(pre[tin.index(pre[0])+1:], tin[tin.index(pre[0])+1:])
			return rst
	