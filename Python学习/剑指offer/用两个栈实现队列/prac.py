# -*- coding:utf-8 -*-
class Solution:
	def __init__(self):
		self.stack1=[]
		self.stack2=[]
	def push(self, node):
		# write code here
		while(self.stack2):
			self.stack1.append(self.stack2.pop())
		self.stack1.append(node)
	def pop(self):
		# return xx
		while(self.stack1):
			self.stack2.append(self.stack1.pop())
		return self.stack2.pop()
		
s = Solution()

s.push(4)
s.push(8)

print(s.pop())
print(s.pop())
	