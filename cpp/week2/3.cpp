#include <iostream>
using namespace std;

int num;
int& test(){
	return num;
}
int main()
{
	cout<<num<<endl;
	test() = 5;
	cout<<num<<endl;

	return 0;
}