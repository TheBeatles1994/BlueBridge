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


try:
	print("try")
finally:
	print("finally")