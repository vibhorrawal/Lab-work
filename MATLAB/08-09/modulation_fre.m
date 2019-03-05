clc
close all
clear all
t=(0:1/1000000:2);
subplot(3,1,1)
m=cos(2*pi*t);
plot(t,m)


subplot(3,1,2)
c=2*sin(2*pi*25*t);
plot(t,c)

subplot(3,1,3)
z=cos(2*pi*c.*t);
plot(t,z)
