# -*- coding:utf-8 -*-
class TreeNode:
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
class Solution:
	# 返回镜像树的根节点
	def isMirror(self, tree1, tree2):
		if tree1 == None and tree2 == None:
			return True
		elif tree1 == None and tree2 != None:
			return False
		elif tree1 != None and tree2 == None:
			return False
		else:
			return self.isMirror(tree1.left, tree2.right) and self.isMirror(tree1.right, tree2.left)
	
	def isSymmetrical(self, root):
		# write code here
		if root==None:
			return True
		else:
			return self.isMirror(root.left, root.right)
			
			
		
s = Solution()
tree = TreeNode(4)

p = s.isSymmetrical(tree)

print(p)

'''
while True:
	base = float(input("base:"))
	exp = int(input("exponent:"))
	print s.Power(base,exp)
'''
					
	