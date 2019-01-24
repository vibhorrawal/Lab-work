#include<iostream>
using namespace std;

class complex {

    int real,img;
    public:

     complex()
     {}

     complex(int x)
    {
        real = x;
        img = x;
    }

     complex(int x,int y)
    {
        real = x;
        img = y;
    }

    friend complex add(complex &,complex &);

    friend void display(complex);
};

complex add(complex& c1,complex& c2)
{
    complex c3;
    c3.real = c1.real+c2.real;
    c3.img = c1.img+c2.img;

    return c3;
}

void display(complex number)
{
    cout<<"Result is :"<<number.real<<" + i"<<number.img<<endl;
}

int main()
{
    int x,y;
    complex c,c1,c2;

    cout<<"\tAddition of two Complex Numbers"<<endl;
    
    cout<<"\nEnter first Number"<<endl;
    cout<<"Real part:";
    cin>>x;
    cout<<"Imaginary part:";
    cin>>y;

    if (x==y)
    {
        complex temp(x);
        c1=temp;
    }
    else
    {
        complex temp(x,y);
        c1=temp;
    }

    cout<<"Enter second Number"<<endl;
    cout<<"Real part:";
    cin>>x;
    cout<<"Imaginary part:";
    cin>>y;

    if (x==y)
    {
        complex temp(x);
        c2=temp;
    }
    else
    {
        complex temp(x,y);
        c2=temp;
    }

    c=add(c1,c2);

    display(c);

    return 0;
}