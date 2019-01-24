mvi b,0
inr b
stc 
cmc

mvi a,0ffh
adi 01h
out 01h

push psw
pop h
mov a,l
ani 01h
out 00h

mvi b,0
inr b
stc 
cmc

mvi a,0ffh
inr a
nop
out 01h

push psw
pop h
mov a,l
ani 01h
out 00h


hlt