import fnmatch
import os

# 文件重命名：将所有file1开头的文件去掉1
'''
for file in os.listdir('.'):
	if fnmatch.fnmatch(file, '*.txt'):
		os.rename(file, file.replace('file1','file'))
'''

# 多文件合并

# 大文件合并
'''
with open("merge.txt", 'w') as fileMerge:
	for file in os.listdir('.'):
		if fnmatch.fnmatch(file, '*.txt'):
			with open(file) as infile:
				for line in infile:
					fileMerge.write(line)
'''			
# 小文件合并
with open("merge.txt",'w+') as mergeFile:
	for f in os.listdir('.'):
		if fnmatch.fnmatch(f, '*.txt'):
			with open(f) as infile:
				mergeFile.write(infile.read())
			