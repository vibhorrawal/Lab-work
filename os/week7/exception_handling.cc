#include<iostream>
#include <exception>
using namespace std;

int main() try{
	int n;
	cin>>n;
	cout<<n/0;
}

catch(exception e){
    cout<<e->what();
}