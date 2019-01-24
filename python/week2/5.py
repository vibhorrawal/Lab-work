#author: Vibhor Rawal
import re
file1 = open('c.c','r')
counts = dict()
keywords = ['auto','break','case','char','const','continue','default','do','double','else','printf','scanf','enum','extern','float','for','goto','if','int','long','register','return','short','signed','sizeof','static','struct','switch','typedef','union','unsigned','void','volatile','while','asm','bool','catch','class','const_cast','delete','dynamic_cast','explicit','false','friend','inline','mutable','namespace','new','operator','private','protected','public','reinterpret_cast','static_cast','template','this','throw','true','try','typeid','typename','virtual','using','wchar_t' ]
freq = dict()
for key in keywords:
	freq[key] = 0
flag = 0

for line in file1:
	#print(line)
	words = re.split('; |, | |\n|( |) ',line)
	#print (words)
	if (words[0] == '#'):
		continue
	if (words[0] == '//'):
		continue
		
	else:
		for word in words:
			#print(word)
			#print(flag)

			if (word == "\"" and flag==0):
				flag = 1
				continue

			if (word == "/*" and flag==0):
				flag = 1
				continue

			if (flag==1):
				if (word == "\""):
					flag = 0
				elif (word == "*/"):
					flag = 0	
				continue


			if word in keywords:
				freq[word] = freq[word] + 1


print (freq)				
