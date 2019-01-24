#include <iostream>
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
	HumanBeing obj;
	obj.display();
} 