# -*- coding:utf-8 -*-
class Solution:
	def Power(self, base, exponent):
		# write code here
		return base**exponent
		
s = Solution()
while True:
	base = float(input("base:"))
	exp = int(input("exponent:"))
	print s.Power(base,exp)
	
					
	