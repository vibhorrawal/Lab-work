 /* Special type of Variable - 
  * - const : once initialised, value cant change
  * - static : once initialised value can be changed, 
  * holds value b/w function calls
  */

#include<iostream>
using namespace std;

int main()
{
	const int i = 5;
	//i = 5; 
	cout<<i;
	//i = 6;
	cout<<i;

}  