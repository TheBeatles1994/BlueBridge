# -*- coding:utf-8 -*-
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution:
	def FindKthToTail(self, head, k):
		# write code here
		
		rst = []
		count = 0
		while head!=None:
			rst.append(head)
			head = head.next
			count += 1
		
		if k>count:
			return None
		
		return rst[-k]
			
		
s = Solution()
lst = ListNode(4)
print s.FindKthToTail(lst,1).val
'''
while True:
	base = float(input("base:"))
	exp = int(input("exponent:"))
	print s.Power(base,exp)
'''
					
	