frequencyTable = ['E','T','A','O','I','N','S','R','H','D','L']

def decypher(fname):
    with open(fname,'r') as file:
        text = file.read()

    freq = {}
    for letter in text:
        # print(word)
        if letter == ' ' or letter == '\n':
            continue

        if letter not in freq:
            freq[letter] = 1
        else:
            freq[letter] = freq[letter] + 1


    # print(freq)

    # print(chr(65))
    max = -1
    for v in freq:
        if(max < freq[v]):
            max = freq[v]
            e = v

    print("Max frequency letter is", e)
    # this is e

    key = ord(v) - ord('E')
    # key = (key + 26) % 26
    print('Key is', key)

    print('Plaintext is')
    for l in text:
        c = ord(l) - key
        while c < 65:
            c = c + 26
        while c > 90:
            c = c - 26

        print(chr(c),end='')
    print('\n\n')


def decypherTopTen(fname):
    with open(fname,'r') as file:
        text = file.read()

    freq = {}
    for letter in text:
        # print(word)
        if letter == ' ' or letter == '\n':
            continue

        if letter not in freq:
            freq[letter] = 1
        else:
            freq[letter] = freq[letter] + 1


    # print(freq)

    # print(chr(65))
    for i in range(10):
        print("Result #%d" %(i+1))
        max = -1
        for v in freq:
            if(max < freq[v]):
                max = freq[v]
                e = v

        print("Max frequency letter is", e)
        # this is e

        key = ord(v) - ord(frequencyTable[i])
        # key = (key + 26) % 26
        print('Key is', key)

        print('Plaintext is')
        for l in text:
            c = ord(l) - key
            while c < 65:
                c = c + 26
            while c > 90:
                c = c - 26

            print(chr(c),end='')
        print('\n\n')
        freq[e] = 0


# decypherTopTen("enc")
fname = input('Enter filename to perform attack on: ')
c = input('Do you want top 10 results?(y/n): ')
if c == 'y':
    decypherTopTen(fname)
else:
    decypher(fname)
