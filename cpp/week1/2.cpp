#include <bits/stdc++.h>
using namespace std;

class HumanBeing
{
 public : void display()
 {
 	cout<<"Inside Member function\n";
 }
};

int main()
{
	//makes code faster...
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	HumanBeing obj;
	obj.display();
} 
