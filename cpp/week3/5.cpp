#include<iostream>
#include<fstream>
#include<ctype.h>
using namespace std;

int main()
{
	char ch;
	ifstream ifs("text.txt");
	ofstream ofs("upper.txt");
	while(!ifs.eof())
	{
		ifs.get(ch);
		ch = putchar(toupper(ch));
		ofs.put(ch);
	}
}