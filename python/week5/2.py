#author Vibhor Rawal
file = open('file2.txt','r')
out = open('result.txt','w')
filelines = file.read()
lines = filelines.splitlines()
tlist = []
charlist = []
op = []
flow = []

for i in range(len(lines)):
	line = lines[i]
	#if (str(line[0:2]) not in tlist):
	tlist.append(str(line[0:2]))
	charlist.append(line[line.index('(')+1])
	op.append(line[line.index(':')+1])

for i in range(len(tlist)):
	j = i + 1
	while(j<len(tlist)):
		if(tlist[i] != tlist[j] and charlist[i] == charlist[j]):
			if(op[i] != 'r' or op[j] != 'r'):
				flow.append(tlist[i])
				flow.append(tlist[j])
		j = j + 1		
print (flow)
for i in range(len(flow)):
	j = i + 2
	while (j<len(flow)):
		if(flow[i] == flow[j]):
			print ('Conflict')
			exit()
		j = j+1	
last = 0		
for i in range(len(flow)):
	if(last != flow[i]):
		print ('-->'+str(flow[i]),end='')
	last = flow[i]
