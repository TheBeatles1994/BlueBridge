# -*- coding:utf-8 -*-
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None
		
class Solution:
	# 返回合并后列表
	def Merge(self, pHead1, pHead2):
		# write code here
		if pHead1 == None:
			return pHead2
		if pHead2 == None:
			return pHead1
		
		if(pHead1.val <= pHead2.val):
			pHead1.next = self.Merge(pHead1.next, pHead2)
			return pHead1
		else:
			pHead2.next = self.Merge(pHead1, pHead2.next)
			return pHead2
			
			
		
s = Solution()
lst1 = ListNode(4)
lst2 = ListNode(2)

p = s.Merge(lst1,lst2)

while p!=None:
	print(p.val)
	p = p.next

'''
while True:
	base = float(input("base:"))
	exp = int(input("exponent:"))
	print s.Power(base,exp)
'''
					
	