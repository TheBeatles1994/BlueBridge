# -*- coding:utf-8 -*-
class Solution:
	def Fibonacci(self, n):
		if n==0:
			return 0
		if n <= 2:
			return 1
		num1 = 1
		num2 = 1
		while (n-2):
			num1,num2 = num2,num1+num2
			n -= 1
		return num2
		
s = Solution()

print(s.Fibonacci(3))
		
					
	