#author Vibhor Rawal
from collections import Counter

file = open('file1.txt','r')
out = open('result.txt','w')
filelines = file.read()
lines = filelines.splitlines()
tlist = []
charlist = []
op = []
flow = []

for i in range(len(lines)):
	line = lines[i]
	tlist.append(str(line[0:2]))
	charlist.append(line[line.index('(')+1])
	op.append(line[line.index(':')+1])

for i in range(len(lines)):
    newline = lines[i]
    if 'read' in newline:
        operation = 1
    else:
        operation = 2
    t = newline[0:2]
    opd = newline[-2]
    j = i+1
    while j < len(lines):
        check = lines[j]
        if 'read' in check:
            nextop = 1
        else:
            nextop = 2
        nt = check[0:2]
        nextopd = check[-2]
        if (t == nt) and (operation != nextop):
            break
        if (t != nt) and (operation!= nextop) and (operation == 2) and (nextop == 1):
            break
        if (t!=nt) and (operation == 1) and (nextopd == opd) and (nextop == 2):
            print('conflict')
            exit()
        if (t!=nt) and (operation == 2) and (nextopd == opd):
            print('conflict')
            exit()
        j = j + 1

oplist = Counter(charlist)
#print (oplist)
#print(charlist)
for i in oplist:
    if oplist[i] > 2:
        flow.append(i)
    for s in flow:
        tag = str(s)
        for line in lines:
            if (tag in line) and('write' in line):
                out.write('-->'+line[0:2])
                print('-->'+line[0:2],end='')
exit()
