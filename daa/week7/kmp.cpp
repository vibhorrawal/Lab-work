#include<iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string s,p;
	printf("Enter String: \n");
	cin>>s;
	printf("Enter pattern: \n");
	cin>>p;
	int* pre = (int*)malloc(p.length() * sizeof(int));
	prefix(p, pre);
	return 0;
}

void prefix(string p, int* pre){
	int k = 0,j = 0;
	for (int i = 0; i < p.length(); ++i)
	{
		
	}
}