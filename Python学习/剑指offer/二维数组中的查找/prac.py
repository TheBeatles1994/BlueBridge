# -*- coding:utf-8 -*-
class Solution:
	# array 二维列表
	def Findd(self, target, array):
		# write code here
		pLen=len(array)
		flag = "false"
		for i in range(pLen):
			if target in array[i]:
				flag = "true";
				break
		return flag
		class Solution:
    # array 二维列表
	def Find(self, target, array):
		# write code here
		n=len(array)
		flag='false'
		for i in range(n):
			if target in array[i]:
				flag='true';
				break
		return flag
while True:
	try:
		pC = Solution()
		# 特别注意python3中的input和python2中的input不一样！python3中返回string，python2中返回list
		input = list(eval(input()))
		num1=input[0]
		num2=input[1]
		print(pC.Find(num1, num2))
	except:
		break
	