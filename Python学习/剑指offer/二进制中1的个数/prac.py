# -*- coding:utf-8 -*-
class Solution:
	def NumberOf1(self, n):
		# write code here
		return sum([n>>i & 1 for i in range(0,32)])
			
s = Solution()
while True:
	num = int(input("input num:"))
	if num!=-1:
		print(s.NumberOf1(num))
	else:
		break
					
	