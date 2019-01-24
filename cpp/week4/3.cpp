// user defined to user defined 
//  either one
#include<iostream>
using namespace std;

class A
{
public:
	int a;
	A();

	A(int x)
	{
		a = x;
	}

	A(B &obj)
	{
		a = obj.b;

	};
	
	
};
class B
{
public:
	int b;
	B();
	//conversion function
	// operator A()
	// { A obj;
	// 	obj.a=b;
	// 	return obj;
	// }
	
};
int main()
{
	A obj1;
	B obj2;

	obj2.b = 2;
	obj1 = obj2;

	cout<<obj1.a;
}