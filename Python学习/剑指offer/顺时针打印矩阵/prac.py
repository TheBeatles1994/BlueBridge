# -*- coding:utf-8 -*-
class Solution:
	# matrix类型为二维列表，需要返回列表
	def printMatrix(self, matrix):
		# write code here
		rst = []
		
		if matrix == []:
			return rst
		
		left = 0
		top = 0
		right = len(matrix[0])-1
		bottom = len(matrix)-1
		
		while(left<=right and top<=bottom):
			for index in range(left, right+1, 1):
				rst.append(matrix[top][index])
			for index in range(top+1, bottom+1,1):
				rst.append(matrix[index][right])
			if bottom!=top:
				for index in range(right-1, left, -1):
					rst.append(matrix[bottom][index])
			if right!=left:
				for index in range(bottom, top, -1):
					rst.append(matrix[index][left])
			
				
			left,top = left+1,top+1
			right, bottom = right-1, bottom-1
		

		return rst
		
			
			
lst = [[1,2,3],[4,5,6],[7,8,9]]
s = Solution()

p = s.printMatrix(lst)

print(p)

'''
while True:
	base = float(input("base:"))
	exp = int(input("exponent:"))
	print s.Power(base,exp)
'''
					
	