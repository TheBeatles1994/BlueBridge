# -*- coding:utf-8 -*-
class Solution:
	'''
	def __init__(self):
		self.count=0
	'''
	def jumpFloor(self, number):
		# write code here
		if(number == 0):
			return 1
			
		if(number < 0):
			return 0
			
		count = 0
		
		count += self.jumpFloor(number-2)
		count += self.jumpFloor(number-1)
			
		return count
		
		
s = Solution()

print(s.jumpFloor(4))
		
					
	