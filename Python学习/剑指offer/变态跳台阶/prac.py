# -*- coding:utf-8 -*-
class Solution:
	'''
	def __init__(self):
		self.count=0
	'''
	def jumpFloorII(self, number):
		# write code here
		if(number <= 2):
			return number
			
		index = 3	# 下标
		temp = 3	# 求和	
		step = [1,2]

		while(index <= number):
			step.append(temp+1)
			temp += step[index-1]
			index += 1
		
		return step[number-1]
		
		
		
s = Solution()
while True:
	num = int(input("input num:"))
	if num!=-1:
		print(s.jumpFloorII(num))
	else:
		break
		
					
	