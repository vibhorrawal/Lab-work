#author: Vibhor Rawal

para = input()
words = list()

words = para.split()
#print(words)
freq = dict()

for word in words:
	if word in freq.keys():
		freq[word] = freq[word] + 1
	else:
		freq[word] = 1

print(freq)			
