# -*- coding:utf-8 -*-
class TreeNode:
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
class Solution:
	def HasSubtree(self, pRoot1, pRoot2):
		# write code here
		if pRoot1 == None and pRoot2!=None:
			return False
		elif pRoot1 != None and pRoot2 == None:
			return False
		elif pRoot1 == None and pRoot2 == None:
			return False
			
		if(pRoot1.val != pRoot2.val):
			return self.HasSubtree(pRoot1.left,pRoot2) or self.HasSubtree(pRoot1.right, pRoot2)
		else:
			rst = True
			if pRoot2.left != None:
				rst = rst and self.HasSubtree(pRoot1.left,pRoot2.left)
			if pRoot2.right != None:
				rst = rst and self.HasSubtree(pRoot1.right, pRoot2.right)
			if rst == True:
				return True
			else:
				return self.HasSubtree(pRoot1.left,pRoot2) or self.HasSubtree(pRoot1.right, pRoot2)
			
			
		
s = Solution()
tree1 = TreeNode(4)
tree2 = TreeNode(2)

p = s.HasSubtree(tree1,tree2)

print(p)

'''
while True:
	base = float(input("base:"))
	exp = int(input("exponent:"))
	print s.Power(base,exp)
'''
					
	