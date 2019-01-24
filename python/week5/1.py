#author Vibhor Rawal

file = open('file.txt','r')
out = open('result.txt','w')

tflag = 0
ntflag = 0
opflag = -1
cflag = 0
answer = ''
filelines = file.read()
lines = filelines.split()

for i in range(len(lines)):
	line = lines[i]
	
	if line.startswith('t1'):
		tflag = 1

	elif line.startswith('t2'):
		tflag = 2	

	elif line.startswith('t3'):
		tflag = 3	


	if 'read' in line: 
		opflag = 0
	else : 
		opflag = 1


	if 'A' in line:
		cflag = 1
	elif 'B' in line:
		cflag = 2
	
	j = i + 1
	
	for n in range(j,len(lines)) :
		newline = lines[n]

		if newline.startswith('t1'):
			ntflag = 1

		elif newline.startswith('t2'):
			ntflag = 2	

		elif newline.startswith('t3'):
			ntflag = 3	


		if 'read' in newline: 
			nopflag = 0
		else : #write
			nopflag = 1


		if 'A' in newline:
			ncflag = 1
			#print(3)
		elif 'B' in newline:
			ncflag = 2

		if not(opflag ==  0) and (nopflag == 0):
			answer = answer+(str(tflag)+str(ntflag))	

		if ()	
			
		'''if (tflag != ntflag) and (opflag != nopflag or opflag == 1):
			string1 = 10 * tflag + ntflag


		#print(tflag,ntflag,opflag,nopflag,cflag,ncflag)	
		if (tflag == ntflag) and (opflag != nopflag):
			break

		if (opflag == 1) and (nopflag == 0) and (tflag != ntflag) and (opflag != nopflag):
			break

		if (tflag != ntflag) and (cflag == ncflag) and (opflag == 0) and (nopflag == 1):
			print ('Conflict')
			exit()

		if (tflag != ntflag) and (cflag == ncflag) and (opflag == 1):
			print ('Conflict')
			exit()


line1 = filelines.split()
if 'A' in line1[0]:
	tag = 'A'
else:
    tag = 'B'
for line in line1:
	if line.startswith('t1'):
		flag = 1

	elif line.startswith('t2'):
		flag = 2	

	elif line.startswith('t3'):
		flag = 3

	if (tag in line) and('write' in line):
		out.write(' -> T'+str(flag))	
		

if tag =='A':
    tag = 'B'
else:
    tag = 'A'		
for line in line1:
	if line.startswith('t1'):
		flag = 1

	elif line.startswith('t2'):
		flag = 2	

	elif line.startswith('t3'):
		flag = 3

	if (tag in line) and('write' in line):
		out.write(' -> T'+str(flag))	
		
'''
print (answer)

