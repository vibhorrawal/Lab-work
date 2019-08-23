import numpy as np
import math
MOD = 27
bite = 2
key = np.array([])
def readKey(filename):
    keyBuffer = []
    fo = open(filename,'r')
    strf = fo.read()
    for word in strf:
        #print(word)
        if word == ' ' or word == "\n":
            continue

        keyBuffer.append((ord(word) - 65) % MOD)

    size = int(math.sqrt(len(keyBuffer)))
    print(size)
    # return
    global key
    key = np.array(keyBuffer).reshape((size,size))
    detA = np.linalg.det(key)
    if detA == 0 or detA == 2 or detA == 13:
        raise "Can not use a key with det(A) = 0 or a factor of 26!!"
        return -1
    return 0

def encrypt(readfile,writefile):
    fread = open(readfile,'r')
    fread = fread.read()
    fwrite = open(writefile,'w')
    print(key,end='\n\n')
    count = 0
    temp = []
    for word in fread:
        count = count + 1

        if word == ' ' or word == '\n':
            temp.append(26)
        else:
            temp.append((ord(word) - 65) % MOD)

        if count == bite:
            count = 0
            # print('len = ',len(temp))
            crossp = np.cross(key,np.array(temp))%MOD
            print(crossp)
            for i in crossp:
                fwrite.write(str(i)+' ')
            temp = []

def decrypt(readfile,writefile):
    fread = open(readfile,'r')
    fread = fread.read()
    fwrite = open(writefile,'w')

    keyinv = np.linalg.inv(key)
    print(keyinv)
    keyin = (keyinv * np.linalg.det(key)) % MOD
    keyin = np.rint(keyin).astype(int)
    print(keyin)

    count = 0
    temp = []
    nums = map(int, fread.split())
    for num in nums:
        print(num)
        count = count + 1

        if num == ' ' or num == '\n':
            temp.append(26)
        else:
            temp.append(num)

        if count == bite:
            count = 0
            crossp = np.cross(keyin,np.array(temp).astype(int))%MOD
            # crossp = [1,2,3,0]
            # print(crossp)
            for i in crossp:
                fwrite.write(chr(i+65))
            fwrite.write(' ')    
            temp = []


if __name__ == "__main__":
    readKey('test')
    encrypt('read','write')
    decrypt('write','dc')
