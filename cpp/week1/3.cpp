/*
 * types of Variables:
 * -Global
 * -local
 */

#include <iostream>
using namespace std;

int main()
{
	int i = 10;
	cout<<i;

	//int i = 5;
	cout<<i;

	{
		int i = 4;
		int n = 3;
		i = 2;
		cout<<i;
		cout<<n;
	}
	cout<<i;
}