#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
	float f = 4321.123456;
	char x = '\n';
	//cout.width(100);
	//cout.setf(ios_base::floatfield);
	//cout.precision(5);
	cout.fill(x);
	cout.width(10);
	cout<<f<<endl;
	return 0;
}