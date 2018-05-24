setence1 = "hello"
setence2 = "world!"
'''
print学习
'''
#打印整个句子
print(setence1,setence2)
#使用separated参数，默认是' '
print(setence1,setence2,sep=' ')
print(setence1,setence2,sep='')
#使用end参数，注意一下两者的区别
print(setence1,setence2,sep='#', end='~')	
print(setence1,setence2,sep='#', end='\n')	
#file参数
"""
#http://effbot.org/zone/python-with-statement.htm
#Understanding Python's "with" statement
with open('test.txt','w') as f:
	print("Mr","S",sep=' ',end=r'\n',file=f)
"""

'''
while学习
'''

"""
while True:
	try:
		x = int(input("please enter a number:"),8)	#表明为8进制
		print("number is",x)	#若执行失败，不会执行这一句
		break
	except ValueError:
		print("invalid number!try again")
"""

'''
mylist = [x*x for x in range(3)]
for i in mylist:
	print(i,end=" ")
print()
mystr = "sunzhiheng"
for i in mystr:
	print(i, end=" ")
'''

'''
list yield generator学习
'''
# 1
def myfunc():
	mylist = range(3)
	for i in mylist:
		yield i*i
		
mygenerator = myfunc()
print (mygenerator)

for i in mygenerator:
	print(i)
	
print (mygenerator)
for i in mygenerator:
	print(i)
	
# 2
'''
#Generator:

# Here you create the method of the node object that will return the generator
def _get_child_candidates(self, distance, min_dist, max_dist):

    # Here is the code that will be called each time you use the generator object:

    # If there is still a child of the node object on its left
    # AND if distance is ok, return the next child
    if self._leftchild and distance - max_dist < self._median:
        yield self._leftchild

    # If there is still a child of the node object on its right
    # AND if distance is ok, return the next child
    if self._rightchild and distance + max_dist >= self._median:
        yield self._rightchild

    # If the function arrives here, the generator will be considered empty
    # there is no more than two values: the left and the right children
	
#Caller:

# Create an empty list and a list with the current object reference
result, candidates = list(), [self]

# Loop on candidates (they contain only one element at the beginning)
while candidates:

    # Get the last candidate and remove it from the list
    node = candidates.pop()

    # Get the distance between obj and the candidate
    distance = node._get_dist(obj)

    # If distance is ok, then you can fill the result
    if distance <= max_dist and distance >= min_dist:
        result.extend(node._values)

    # Add the children of the candidate in the candidates list
    # so the loop will keep running until it will have looked
    # at all the children of the children of the children, etc. of the candidate
    candidates.extend(node._get_child_candidates(distance, min_dist, max_dist))

return result
'''

try:
	print("try")
finally:
	print("finally")