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
		pre = None
		next = None
		while pHead!=None:
			next = pHead.next
			pHead.next = pre
			pre = pHead
			pHead = next
		
		return pre
			
		
s = Solution()
lst = ListNode(4)
print (s.ReverseList(lst).val)
'''
while True:
	base = float(input("base:"))
	exp = int(input("exponent:"))
	print s.Power(base,exp)
'''
					
	