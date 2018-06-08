# -*- coding:utf-8 -*-
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None
		
class Solution:
	# 返回ListNode
	def ReverseList(self, pHead):
		# write code here
		if(pHead == None):
			return None
		lst = []
		while pHead!=None:
			lst.append(pHead)
			pHead = pHead.next
		for index in range(len(lst)-1,0,-1):
			lst[index].next = lst[index-1]
			
		lst[0].next = None
		
		return lst[len(lst)-1]
			
		
s = Solution()
lst = ListNode(4)
print (s.ReverseList(lst).val)
'''
while True:
	base = float(input("base:"))
	exp = int(input("exponent:"))
	print s.Power(base,exp)
'''
					
	