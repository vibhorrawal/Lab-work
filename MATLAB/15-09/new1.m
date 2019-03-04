clc
clear all
close all
x=0:1/4:10;
subplot(2,1,1)
y=5*sin(x)
y=round(abs(y));
subplot(2,1,2)
c=stem(y)
b=dec2bin(y);
b=b'
for ii=1:length(c)
    if c(ii)=1


    






