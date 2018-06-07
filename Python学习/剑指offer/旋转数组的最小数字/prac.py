# -*- coding:utf-8 -*-
class Solution:
	def minNumberInRotateArray(self, rotateArray):
		# write code here
		if len(rotateArray)==0:
			return 0
		else:
			pre = -1
			for i in rotateArray:
				if(i<pre):
					return i
				else:
					pre = i
			return rotateArray[0]
					
	