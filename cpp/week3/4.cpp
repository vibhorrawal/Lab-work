#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char ch;
	ifstream ifs("text.txt");
	while(!ifs.eof())
	{
		ifs.get(ch);
		cout<<ch;
	}
}