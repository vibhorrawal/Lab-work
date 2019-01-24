//author: Vibhor Rawal
#include<iostream>
using namespace std;

class test2;

class test1
{
    int marks1;
    public:
        
        void set(int);
        void display();
        friend void swap(test1 &,test2 &);
};

class test2
{
    int marks2;
    public:

        void set(int);
        void display();
        friend void swap(test1 &,test2 &);

};

void test1::set(int n)
{
    marks1 = n;
}

void test2::set(int n)
{
    marks2 = n;
}

void test1::display()
{
    cout<<"marks1 = "<<marks1<<"\n";
}

void test2::display()
{
    cout<<"marks2 = "<<marks2<<"\n";
}

void swap(test1 &x,test2 &y)
{
    int temp;
    temp = x.marks1;
    x.marks1 = y.marks2;
    y.marks2 = temp;
}

int main()
{
    int n1,n2;
    cout<<"Enter first value: ";
    cin>>n1;
    cout<<"Enter second value: ";
    cin>>n2;

    test1 s1;
    test2 s2;
    s1.set(n1);
    s2.set(n2);

    cout<<"Before Swapping:\n";
    s1.display();
    s2.display();

    swap(s1, s2);

    cout<<"After Swapping:\n";
    s1.display();
    s2.display();

    return 0;
}