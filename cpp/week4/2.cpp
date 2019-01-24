//user to basic
#include <iostream>
using namespace std;

class A
{
public:
	int x;

	operator int()
	{
		return x;
	}
};

int main()
{
	A obj;
	int a;
	obj.x = 5;
	a = obj;
	cout<<a;
	return 0;
}