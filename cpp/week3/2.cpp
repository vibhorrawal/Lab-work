#include<iostream>
using namespace std;

int main()
{
	char ch;
	char a[20];
	
	while(ch!= '\n')
	{
		cin.get(ch);
		cout<<ch;
	}

	cin.getline(a,20);
	cout.write(a,20);
}