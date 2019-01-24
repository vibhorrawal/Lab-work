//base to user defined
#include <iostream>
using namespace std;

class A
{
public:
	int x;
	// operator overloading
	A & operator=(int y)
	{
		x = y;
	}
	//costructor
	A(){}
	A (int y){
		x = y + 1;
	}
};

int main(int argc, char const *argv[])
{
	A obj;
	obj = 5;
	cout<<obj.x;
	return 0;
}