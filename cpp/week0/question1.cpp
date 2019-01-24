//Author : Vibhor Rawal
#include<iostream>
using namespace std;

class complex {

    int real,img;
    public:

     complex()
    {         }

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

complex add(complex & c1,complex & c2)
{
    complex sum;
    sum.real = c1.real+c2.real;
    sum.img = c1.img+c2.img;

    return sum;
}

void display(complex number)
{
    cout<<"Result is : "<<number.real<<" + "<<number.img<<"i"<<endl;
}


int main()
{
    int x,y;
    complex c1,c2,sum;

    cout<<"\t********Program for Addition of two Complex Numbers********"<<endl<<endl;
    
    cout<<"First Number :"<<endl;
    cout<<"Real part : ";
    cin>>x;
    cout<<"Imaginary part : ";
    cin>>y;

    if ( x == y )
    {
        complex temp(x);
        c1 = temp;
    }
    else
    {
        complex temp(x,y);
        c1 = temp;
    }

    cout<<"\nSecond Number :"<<endl;
    cout<<"Real part: ";
    cin>>x;
    cout<<"Imaginary part: ";
    cin>>y;

    if ( x == y )
    {
        complex temp(x);
        c2 = temp;
    }
    else
    {
        complex temp(x,y);
        c2 = temp;
    }

    sum = add ( c1,c2 );

    display ( sum );

    return 0;
}
