import collections
import sys
files = open('file1.txt','r')
file = files.read()
lines = file.split('\n')
lines = [l for l in lines if l]
#print(lines)
trans = set([l[0:2] for l in lines])
trans = list(trans)
#print(trans)
z = sys.stdout
total_oplist = []
opdlist = []
for l in lines:
    if l[-2] in opdlist:
        total_oplist.append(l[-2])
    else:
        total_oplist.append(l[-2])
        opdlist.append(l[-2])
#print(opdlist)

for i in range(len(lines)):
    start = lines[i]
    if 'read' in start:
        op = 1
    else:
        op = 2
    t = start[0:2]
    opd = start[-2]
    j = i+1
    while j < len(lines):
        check = lines[j]
        if 'read' in check:
            nop = 1
        else:
            nop = 2
        nt = check[0:2]
        nopd = check[-2]
        if (t == nt) and (op != nop):
            break
        if (t != nt) and (op!= nop) and (op == 2) and (nop == 1):
            break
        if (t!=nt) and (op == 1) and (nopd == opd) and (nop == 2):
            #print(f'{t} --> reading\n{nt} --> writing\nfile --> {nopd}')
            print('conflict')
            exit()
        if (t!=nt) and (op == 2) and (nopd == opd):
            #print(f'{t} --> writing\n{nt} --> writing\nfile --> {nopd}')
            print('conflict')
            exit()
        j = j+ 1
else:
    files.close()
    print('NO conflict')
    cline = file.split('\n')
    #print(cline)
    #print(total_oplist)
    opdlist2 = collections.Counter(total_oplist)
    opdlist3 = []
    for i in opdlist2:
        if opdlist2[i] > 2:
            opdlist3.append(i)
    for s in opdlist3:
        ofile = open('ANSWERS.txt','a')
        s = str(s)
        sys.stdout = ofile
        for line in lines:
            if (s in line) and('write' in line):
                #ofile.write('T'+str(t))
                print(line[0:2],end = '-->')
        print()
    print('end')
    
sys.stdout = z
exit()