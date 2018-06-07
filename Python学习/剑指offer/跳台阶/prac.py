# -*- coding:utf-8 -*-
class Solution:
	'''
	def __init__(self):
		self.count=0
	'''
	def jumpFloor(self, number):
		# write code here
		if(number <= 2):
			return number
			
		step = [1,2]
		count = number-2
		while(count):
			step.append(step[-2]+step[-1])
			count -= 1
		
		return step[number-1]
		
		
		
s = Solution()
while True:
	num = int(input("input num:"))
	if num!=-1:
		print(s.jumpFloor(num))
	else:
		break
		
					
	