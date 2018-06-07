# -*- coding:utf-8 -*-
class Reverse:
	def __init__(self, list):
		self.list = list
		self.index = len(list)
	def __iter__(self):
		return self
	def __next__(self):
		if self.index == 0:
			raise StopIteration
		else:
			self.index -= 1
			return self.list[self.index]
			
lst = [1,2,2,3,4]
r = Reverse(lst)
for i in r:
	print(i)
					
	