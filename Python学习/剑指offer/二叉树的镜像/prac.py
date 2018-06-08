# -*- coding:utf-8 -*-
class TreeNode:
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
class Solution:
	# 返回镜像树的根节点
	def Mirror(self, root):
		# write code here
		if root==None:
			return None
		else:
			root.left,root.right = root.right,root.left
			root.left = self.Mirror(root.left)
			root.right = self.Mirror(root.right)
			return root
			
			
		
s = Solution()
tree = TreeNode(4)

p = s.Mirror(tree)

print(p.val)

'''
while True:
	base = float(input("base:"))
	exp = int(input("exponent:"))
	print s.Power(base,exp)
'''
					
	