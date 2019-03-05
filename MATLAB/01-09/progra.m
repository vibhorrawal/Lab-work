clc
clear all
close all
a=round(255*rand(3,3))
ans=a;
if (a(1,1)>a(2,2));
    a(1,1)=1;
else
    a(1,1)=0;
end
if (a(1,2)>a(2,2));
    a(1,2)=1;
else
    a(1,2)=0;
end
if (a(1,3)>a(2,2));
    a(1,3)=1;
else
    a(1,3)=0;
end
if (a(2,1)>a(2,2));
    a(2,1)=1;
else
    a(2,1)=0;
end
if (a(2,3)>a(2,2));
    a(2,3)=1;
else
    a(2,3)=0;
end
if (a(3,1)>a(2,2));
    a(3,1)=1;
else
    a(3,1)=0;
end
if (a(3,2)>a(2,2));
    a(3,2)=1;
else
    a(3,2)=0;
end
if (a(3,3)>a(2,2));
    a(3,3)=1;
else
    a(3,3)=0;
end
a
c=a(2,3)+ 2*a(1,3) + 4*a(1,2) + 8*a(1,1) + 16*a(2,1) + 32*a(3,1) + 64*a(3,2) + 128*a(3,3);
ans(2,2)=c;
ans
