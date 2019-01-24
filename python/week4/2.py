file = open('comm.txt','r')
t = 0
op = 0
fileline = file.read()
lines = fileline.split('\n')

for i in range(len(lines)):
    line = lines[i]
    if line.startswith('T1'):
        t = 1
    if line.startswith('T2'):
        t = 2
    if line.startswith('T3'):
        t = 3
    if 'read' in line:
        op = 1
    else:
        op = 2
    if 'A' in line:
        opd = 1
    elif 'B' in line:
        opd = 2
    j = i + 1
    while j < len(lines):
        nline = lines[j]
        
        if nline.startswith('T1'):
            nt = 1
        if nline.startswith('T2'):
            nt = 2
        if nline.startswith('T3'):
            nt = 3
        if 'read' in nline:
            nop = 1
        else:
            nop = 2
        if 'A' in nline:
            nopd = 1
        elif 'B' in nline:
            nopd = 2
        #print({t},{nt},{op},{nop},{nopd})
        if (t == nt) and (op != nop):
            break
        if (t != nt) and (op!= nop) and (op == 2) and (nop == 1):
            break
        if (t!=nt) and (op == 1) and (nopd == opd) and (nop == 2):
            print({t},{nt},{op},{nop},{nopd})
            print('conflict')
            exit()
        if (t!=nt) and (op == 2) and (nopd == opd):
            print({t},{nt},{op},{nop},{nopd})
            print('conflict')
            exit()
        j = j+1
else:
    file.close()
    print('NO conflict')
    cline = fileline.split('\n')
    print(cline)
    if 'A' in cline[0]:
        s = 'A'
    else:
        s = 'B'
    for line in cline:
        if line.startswith('T1'):
            t = 1
        if line.startswith('T2'):
            t = 2
        if line.startswith('T3'):
            t = 3
        ofile = open('answer.txt','w')
        if (s in line) and('write' in line):
            ofile.write('T'+str(t))
            print('T'+str(t))
    if s =='A':
        s = 'B'
    else:
        s = 'A'
    for line in cline:
        if line.startswith('T1'):
            t = 1
        if line.startswith('T2'):
            t = 2
        if line.startswith('T3'):
            t = 3
        ofile = open('answer.txt','w')
        if (s in line) and('write' in line):
            ofile.write('T'+str(t))
            print('T'+str(t))