# -*- coding:utf-8 -*-
class Solution:
	def rectCover(self, number):
		# write code here
		if number==0:
			return 0
		rst = [1,2]
		if(number <= 2):
			return rst[number-1]
		else:
			index = 2
			while index <= number-1:
				rst.append(rst[-1]+rst[-2])
				index += 1
			return rst[number-1]
			
s = Solution()
while True:
	num = int(input("input num:"))
	if num!=-1:
		print(s.rectCover(num))
	else:
		break
					
	