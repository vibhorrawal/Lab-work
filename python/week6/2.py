import re
file = open('x.txt','r')
lines = file.readlines()
s = input("Enter keyword: ")
i = 0
for line in lines:
	#print (line)
	obj = re.search(s,line)
	if obj:
		i = i + 1
		print (line, end = '')

print(str(i)+' results found!')	