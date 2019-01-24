import re
pattern = '.*dogs?' 
s = 'This is a dog'

#flag = 're.I'
# just checking for first word
q = re.match(pattern,s,flags = 0) 
print (q)
# in complete string
q = re.search(pattern,s)
# re.I,M,X,U
print (q.group())
