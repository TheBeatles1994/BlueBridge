# -*- coding:utf-8 -*-
class Solution:
	# s 源字符串
	def replaceSpace(self, s):
		# write code here
		return s.replace(" ", "%20")

while True:
	try:
		pC = Solution()
		# 特别注意python3中的input和python2中的input不一样！python3中返回string，python2中返回list
		input = input()
		print(pC.replaceSpace(input))
	except:
		break
	