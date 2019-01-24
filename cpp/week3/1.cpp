#include <iostream>
using namespace std;

class Test 
{
	int i = 5;
public:
	int change(int &k, int x) const
	{
		//i = k;
		k++;
		x++; 	
		return k;
	}
};

int main(){
	const Test t1;
	int t = 6;
	cout<<t1.change(t,t)<<endl;
	cout<<t;
	return 0;
}